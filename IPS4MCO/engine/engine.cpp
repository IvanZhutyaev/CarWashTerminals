#include "engine.h"

#define LOG_DEBUG 1



Engine::Engine(QString appdir, LogManager *logmanager, QObject *parent) : QObject(parent) {
    Engine::appdir = appdir;

    modbusController = new ModbusController();
    logManager = logmanager;

    bank_pilotnt = new PilotNT();
    connect(bank_pilotnt, &PilotNT::finished, this, &Engine::paymentBankHandler);

    // Initialize AccountManager
    m_accountManager = new AccountManager(this);
    connect(m_accountManager, &AccountManager::loggedInChanged, [this]() { emit loggedInChanged(); }); // Example connection
    connect(m_accountManager, &AccountManager::currentBalanceChanged, [this]() { emit currentBalanceChanged(); });
    connect(m_accountManager, &AccountManager::loginMessageChanged, [this]() { emit loginMessageChanged(); });
    connect(m_accountManager, &AccountManager::registrationMessageChanged, [this]() { emit registrationMessageChanged(); });
    connect(m_accountManager, &AccountManager::showPersonalAccount, this, &Engine::showPersonalAccount); // Forward signal
    connect(m_accountManager, &AccountManager::hidePersonalAccount, this, &Engine::hidePersonalAccount); // Forward signal

    timer = new QTimer();
    delayTimer = new QTimer();
    reconnectTimer = new QTimer();
    initTimer = new QTimer();
    elapsedTimer = new QElapsedTimer();
    elapsedTimerSession = new QElapsedTimer();
    bank.elapsedTimer = new QElapsedTimer();
    //timeoutErrorTimer = new QTimer();


    timer->setInterval(10);
    reconnectTimer->setInterval(30000);
    initTimer->setInterval(initialization_timeout);
    //timeoutErrorTimer->setInterval(error_timeout);

    connect(timer, &QTimer::timeout, this, &Engine::tEvent);
    connect(delayTimer, &QTimer::timeout, this, &Engine::delayTimerSlot);
    connect(reconnectTimer, &QTimer::timeout, this, &Engine::reconnectTimerSlot);
    connect(initTimer, &QTimer::timeout, this, &Engine::initTimerSlot);
    //connect(timeoutErrorTimer, &QTimer::timeout, this, &Engine::timeoutErrorSlot);
}


Engine::~Engine() {
    delete modbusController;
}


void Engine::initEvent() {
    ConfigManager::s_modbus_config modbus_config;
    QJsonObject ui_config;
    state = States::Initialization;
    emit showInitialization(0);
    logManager->addMsg("Инициализация системы.");

    //=========================================
    // UI configuring
    //qDebug() << "path to ui config: " << appdir << FILE_PATH_UI_CONFIG;
    ui_config = ConfigManager::readUIConfig(appdir + FILE_PATH_UI_CONFIG, &error);
    if (error) {
        errorEvent();
        return;
    }

    number_of_programs = ui_config.value("NumberOfPrograms").toInt() * 1000;
    qr_code_timing = ui_config.value("QrCodeTiming").toInt() * 1000;
    qr_code_data_timeout = ui_config.value("QrCodeDataTimeout").toInt() * 1000;

    slide_change_timeout = ui_config.value("SlideChangeTimeout").toInt();
    init_slide_change_mult = ui_config.value("InitSlideChangeMult").toInt();
    button_timeout = ui_config.value("ButtonTimeout").toInt();
    bt_error_timeout = ui_config.value("BankTerminalErrorTimeout").toInt() * 1000;
    bt_success_timeout = ui_config.value("BankTerminalSuccessTimeout").toInt() * 1000;

    emit setUIConfig(ui_config);
    //=========================================

    //emit showSessionLocal();
    //return;

    //=========================================
    // Modbus device configuring
    modbus_config = ConfigManager::readModbusConfig(appdir + FILE_PATH_MODBUS_CONFIG, &error);
    if (error) {
        errorEvent();
        return;
    }

    // enable initialization timer
    if (!initTimer->isActive()) {
        initTimer->start();
    }

    error = modbusController->create();
    if (error) {
        timer->start();
        return;
    }

    error = modbusController->connect(modbus_config.PortName, modbus_config.Parity,
                                      modbus_config.BaudRate, modbus_config.DataBits,
                                      modbus_config.StopBits, modbus_config.ServerAddress,
                                      modbus_config.Timeout);
    if (!error)
        logManager->addMsg("Успешное подключение к указанному COM порту.", "MBS");
    timer->start();

    //=========================================
}

//==========================================
// Event States
void Engine::errorEvent() {
    if (LOG_DEBUG) logManager->addMsg("DEBUG: errorEvent: error=" + QString::number(error) + ".");

    if (!initTimer->isActive()) {
        logManager->addMsg(error);
        emit showError(error);
    }

    switch (error) {
        case Errors::MCTimeout:
            if (!reconnectTimer->isActive()){
                reconnectTimer->start();
                error = modbusController->create();
                if (error)
                    break;
                error = modbusController->connect();
            }
            break;
        case Errors::MCConnectionLost:
            error = modbusController->connect();
            if (!error)
                logManager->addMsg("Успешное подключение к указанному COM порту.", "MBS");
            break;
        case Errors::MCConnect:
            error = modbusController->create();
            if (error)
                break;
            error = modbusController->connect();
            if (!error)
                logManager->addMsg("Успешное подключение к указанному COM порту.", "MBS");
            break;
        case Errors::MCCreateDevice:
            error = modbusController->create();
            if (error)
                break;
            error = modbusController->connect();
            if (!error)
                logManager->addMsg("Успешное подключение к указанному COM порту.", "MBS");
            break;
        default:
            error = Errors::No;
            break;
    }
}


int Engine::sessionEvent() {
    int error = Errors::No;
    // todo optimize s_session
    ModbusController::s_session session;
    session = modbusController->readInSession();
    error = modbusController->getError();
    if (LOG_DEBUG) logManager->addMsg("DEBUG: sessionEvent: error=" + QString::number(error)
                                      + ". session.buttons: " + QString::number(session.buttons)
                                      + ". session.ispause_free: " + QString::number(session.ispause_free)
                                      + ". session.minute: " + QString::number(session.minute)
                                      + ". session.seconds: " + QString::number(session.seconds)
                                      + ". session.pause_minute: " + QString::number(session.pause_minute)
                                      + ". session.pause_seconds: " + QString::number(session.pause_seconds)
                                       + ". session.balance: " + QString::number(session.balance));
    if (error)
        return error;

    setBalance(session.balance);
    setTime(QString::number(session.minute).rightJustified(2, '0') + ":" + QString::number(session.seconds).rightJustified(2, '0'));
    if (pbuttons & 0x80)
        setPauseTime(QString::number(session.pause_minute).rightJustified(2, '0') + ":" + QString::number(session.pause_seconds).rightJustified(2, '0'));

    if (elapsedTimerSession->isValid()) {
        if (elapsedTimerSession->elapsed() < slide_change_timeout)
            return error;

        elapsedTimerSession->invalidate();
    }


    if (write_buttons) {
        elapsedTimer->start();
        write_buttons = false;
        error = modbusController->writeButtons(pbuttons);
        if (error)
            return error;
    } else if ((pbuttons == 0) && (session.buttons != 0)) {
        emit setPressedButtons(session.buttons);
    } else if (pbuttons != session.buttons) {
        if (elapsedTimer->elapsed() > button_timeout) {
            elapsedTimer->invalidate();
            qDebug() << "pbuttons: " << pbuttons << "; session.buttons:" << session.buttons;
            error = modbusController->writeButtons(session.buttons);
            emit setPressedButtons(session.buttons);
        }
    } else if (pbuttons == session.buttons) {
        elapsedTimer->invalidate();
        emit setPressedButtons(session.buttons);
    }

    if (is_session_init <= 0) {
        setIsPauseFree(session.ispause_free);
    } else {
        is_session_init--;
    }

    elapsedTimerSession->start();

    return error;
}


int Engine::qrcodeEvent() {
    int error = Errors::No;
    QString qr_string = modbusController->readQrCode();
    error = modbusController->getError();
    if (error) {
        return error;
    }

    if (qr_string != modbusController->getEmptyQR()){
        emit setQR(qr_string);
        if (!delayTimer->isActive()) {
            timer->stop();
            delayTimer->setInterval(qr_code_timing);
            delayTimer->start();
        }
    }

    return error;
}


int Engine::collectionEvent() {
    int error = Errors::No;
    // todo optimize s_collection
    ModbusController::s_collection collection = modbusController->readCollection();
    error = modbusController->getError();
    if (error)
        return error;

    //setColbalance(collection.balance);
    setColcash(collection.cash);

    return error;
}


int Engine::walletEvent() {
    int error = Errors::No;
    ModbusController::s_wallet wallet = modbusController->readWallet();
    error = modbusController->getError();
    if (error)
        return error;

    setDiscountfix(wallet.discount_fix);
    setDiscountacc(wallet.discount_acc);
    setDeposit(wallet.deposit);
    setDate(QVariant(wallet.day).toString() + "/" + QVariant(wallet.mounth).toString());

    return error;
}
//==========================================

//==========================================
// Transitions
int Engine::sessionTransition() {
    int error = Errors::No;
    // todo optimize s_session
    ModbusController::s_session session;
    session = modbusController->readInSession();
    error = modbusController->getError();
    if (error)
        return error;

    /*
    setBalance(session.balance);
    setIsPauseFree(session.ispause_free);
    emit setPressedButtons(session.buttons);
    setTime(QString::number(session.minute).rightJustified(2, '0') + ":" + QString::number(session.seconds).rightJustified(2, '0'));
    setPauseTime(QString::number(session.pause_minute).rightJustified(2, '0') + ":" + QString::number(session.pause_seconds).rightJustified(2, '0'));
    */

    setBalance(session.balance);
    setTime(QString::number(session.minute).rightJustified(2, '0') + ":" + QString::number(session.seconds).rightJustified(2, '0'));
    setPauseTime(QString::number(session.pause_minute).rightJustified(2, '0') + ":" + QString::number(session.pause_seconds).rightJustified(2, '0'));

    setIsPauseFree(true);
    emit setPressedButtons(0x80);
    is_session_init = init_slide_change_mult;
    elapsedTimerSession->start();


    return error;
}
//==========================================




//=======================================================
//=======================================================
//=======================================================
// Handle Cashless Payment

// send transaction to bank terminal
void Engine::cppSendPayment(int value, int back_screen) {
    Engine::back_screen = back_screen;
    bank_pilotnt->sentSale(value*100);
    emit showPaymentLoading(0);
}


void Engine::paymentBankErrorMessage(int error, QString text) {
    logManager->addMsg(text, "PNT", "Ошибка", ". Код ошибки: " + QVariant(error).toString());
    emit showPaymentError();
    QTimer::singleShot(bt_error_timeout, this, &Engine::showWaiting);
}


// wait respone from bank terminal
void Engine::paymentBankHandler(int error) {
    switch (error) {
        case PilotNT::NoErrors:
            if (bank_pilotnt->isCloseSession()) {
                paymentBankErrorMessage(error, "оплата не произведена");
            } else {
                //emit showInitialization(0);
                bank.wait = true;
                bank.block_update = false;
                bank.finish_from_plc = false;
                bank.block_update = false;

                modbusController->writeBankPayment(bank_pilotnt->getLastPrice());
                bank.elapsedTimer->start();
            }
            break;
        // timeout
        case PilotNT::Timeout:
            paymentBankErrorMessage(error, "превышено время ожидания");
            break;
        case PilotNT::Timeout2:
            paymentBankErrorMessage(error, "превышено время ожидания");
            break;
        case PilotNT::TimeoutPinPad:
            paymentBankErrorMessage(error, "превышено время ожидания");
            break;

        // not enouth money
        case PilotNT::NotEnouthMoney:
            paymentBankErrorMessage(error, "Недостаточно средств");
            break;
        case PilotNT::NotEnouthMoney2:
            paymentBankErrorMessage(error, "Недостаточно средств");
            break;

        // missed pincode
        case PilotNT::MissedPinCode:
            paymentBankErrorMessage(error, "неверный ПИН-код");
            break;
        case PilotNT::MissedPinCode2:
            paymentBankErrorMessage(error, "неверный ПИН-код");
            break;


        // cancel operation
        case PilotNT::OperationCanceled:
            emit showPaymentLoading(3);
            if (back_screen == 2)
                QTimer::singleShot(bt_success_timeout, this, &Engine::showWaiting);
            else if (back_screen == 3)
                QTimer::singleShot(bt_success_timeout, this, &Engine::showSessionLocal);
            break;
        case PilotNT::OperationCanceled1:
            emit showPaymentLoading(3);
            if (back_screen == 2)
                QTimer::singleShot(bt_success_timeout, this, &Engine::showWaiting);
            else if (back_screen == 3)
                QTimer::singleShot(bt_success_timeout, this, &Engine::showSessionLocal);
            break;


        case PilotNT::KillProcess:
            paymentBankErrorMessage(error, "оплата не произведена");
            break;

        case PilotNT::CancelOperation:
            paymentBankErrorMessage(error, "оплата не произведена");
            break;



        // close session
        case PilotNT::CloseSession:
            //emit showInitialization(0);
            bank_pilotnt->closeSession();
            break;
        case PilotNT::CloseSession2:
            //emit showInitialization(0);
            bank_pilotnt->closeSession();
            break;
        case PilotNT::CloseSession3:
            //emit showInitialization(0);
            bank_pilotnt->closeSession();
            break;
        case PilotNT::CloseSession4:
            //emit showInitialization(0);
            bank_pilotnt->closeSession();
            break;


        default:
            paymentBankErrorMessage(error, "оплата не произведена");
    }
}


//=======================================================
//=======================================================
//=======================================================

void Engine::showSessionLocal() {
    emit showSession(last_session_state);
}


void Engine::cppSetButtons(int buttons) {
    write_buttons = true;
    pbuttons = buttons;
}

void Engine::cppClerButtonStateQr() {
    modbusController->clearButtonState(REG_CMD2_TPANEL, 0x3);
    if (delayTimer->isActive()) {
        delayTimer->stop();
        timer->start();
    }
}


void Engine::cppClerButtonStateWallet() {
    modbusController->clearButtonState(REG_CMD1_TPANEL, 0x600);
}



void Engine::tEvent() {
    ModbusController::s_status status;
    static int last_status_raw = -1;

    /*
    status = modbusController->readStatus();
    error = modbusController->getError();

    state = setState(status);

    if (status.raw != last_status_raw) {
        stateTransition(state, status);
    }
    last_status_raw = status.raw;

    error = stateEvent(state);
    */

    if (LOG_DEBUG) logManager->addMsg("DEBUG: tEvent: state: " + QString::number(state) + "; error=" + QString::number(error) + ".");
    if (!error || error == Errors::MCPLC || error == Errors::MCTimeout) {
        status = modbusController->readStatus();
        error = modbusController->getError();
        if (LOG_DEBUG) logManager->addMsg("DEBUG: tEvent: status=" + QString::number(status.raw) +
                                          "; status.pingerror=" + QString::number(status.pingerror) +
                                          "; status.bank=" + QString::number(status.bank) +
                                          "; status.collection=" + QString::number(status.collection) +
                                          "; status.empty=" + QString::number(status.empty) +
                                          "; status.pause_free=" + QString::number(status.pause_free) +
                                          "; status.qrcode=" + QString::number(status.qrcode) +
                                          "; status.wallet=" + QString::number(status.wallet));
        if (LOG_DEBUG) logManager->addMsg("DEBUG: tEvent: error=" + QString::number(error) + ".");
        if ((state == States::Initialization) && !status.pingerror) {
            if (!elapsedTimer->isValid()) {
                emit showInitialization(1);
                elapsedTimer->start();
            }

            if (elapsedTimer->elapsed() > 500) {
                initTimer->stop();
                elapsedTimer->invalidate();
                state = setState(status);
                stateTransition(state, status);
            } else if (elapsedTimer->elapsed() > 250)
                emit showInitialization(2);
        }
        if (!error) {
            if (last_error == Errors::MCPLC)
                logManager->addMsg("Авария Modbus RTU Master снята.", "PLC");
            else if (last_error == Errors::MCTimeout)
                logManager->addMsg("Связь с Modbus RTU Master установлена.", "MBS");
        }
        last_error = error;
    }

    if (bank.wait) {
        if (bank.elapsedTimer->elapsed() > 30000) {
            bank.block_update = false;
            bank.wait = false;
            paymentBankErrorMessage(Errors::TimeoutFromPLC, "превышено время ожидания");
        }
        if (bank.block_update && !status.bank) {
            if (bank.finish_from_plc) { // change to var
                bank.finish_from_plc = false;
                emit showPaymentLoading(1);
                bank.elapsedTimer->invalidate();
                bank.elapsedTimer->start();
            }

            if (bank.elapsedTimer->elapsed() > bt_success_timeout) {
                bank.block_update = false;
                bank.wait = false;
                bank.elapsedTimer->invalidate();
                state = setState(status);
                stateTransition(state, status);
            } else if (bank.elapsedTimer->elapsed() > 250)
                emit showPaymentLoading(2);
        } else if (!bank.block_update && status.bank) {
            bank.finish_from_plc = true;
            bank.block_update = true;
        }
    } else if (modbusController->isConnected() && !error && (state != States::Initialization)) {
        state = setState(status);
        if (status.raw != last_status_raw) {
            error = stateTransition(state, status);
        }

        if (!error)
            error = stateEvent(state);
    } else {
        errorEvent();
    }
    last_status_raw = status.raw;

}

int Engine::setState(ModbusController::s_status status) {
    int state;
    if (status.empty) {
        state = States::Waiting;
    } else if (status.wallet) {
        state = States::Wallet;
    } else if (status.qrcode) {
        state = States::QrCode;
    } else if (status.collection) {
        state = States::Collection;
    } else if (status.session) {
        state = States::Session;
    } else {
        state = States::Waiting;
    }

    return state;
}

int Engine::stateTransition(int state, ModbusController::s_status status) {
    int error = Errors::No;
    switch (state) {
        case States::Waiting:
            emit showWaiting();
            break;
        case States::Session:
            error = sessionTransition();
            //if (!error)
            //    error = sessionEvent();
            last_session_state = status.session;
            emit showSession(status.session);
            //emit showSession(0x8);
            break;
        case States::QrCode:
            emit showQR();
            break;
        case States::Collection:
            emit showCollection();
            break;
        case States::Wallet:
            emit showWallet(status.wallet);
            break;
    }

    return error;
}

int Engine::stateEvent(int state) {
    int error = 0;
    switch (state) {
        case States::Error:
            break;
        case States::Session:
            error = sessionEvent();
            break;
        case States::QrCode:
            error = qrcodeEvent();
            break;
        case States::Collection:
            error = collectionEvent();
            break;
        case States::Wallet:
            error = walletEvent();
            break;
    }

    return error;
}


void Engine::delayTimerSlot() {
    delayTimer->stop();
    timer->start();
}

void Engine::reconnectTimerSlot() {
    reconnectTimer->stop();
}

void Engine::initTimerSlot() {
    initTimer->stop();
}

//=========================================
// Properties
int Engine::balance() const {
    return m_balance;
}

void Engine::setBalance(int balance) {
    if (m_balance == balance)
        return;

    m_balance = balance;
    emit balanceChanged(m_balance);
}


QString Engine::time() const {
    return m_time;
}

void Engine::setTime(QString time) {
    if (m_time == time)
        return;

    m_time = time;
    emit timeChanged(m_time);
}



QString Engine::pause_time() const {
    return m_pause_time;
}

void Engine::setPauseTime(QString pause_time) {
    if (m_pause_time == pause_time)
        return;

    m_pause_time = pause_time;
    emit pauseTimeChanged(m_pause_time);
}


int Engine::discountfix() const {
    return m_discountfix;
}

void Engine::setDiscountfix(int discountfix) {
    if (m_discountfix == discountfix)
        return;

    m_discountfix = discountfix;
    emit discountfixChanged(m_discountfix);
}


int Engine::discountacc() const {
    return m_discountacc;
}

void Engine::setDiscountacc(int discountacc) {
    if (m_discountacc == discountacc)
        return;

    m_discountacc = discountacc;
    emit discountaccChanged(m_discountacc);
}


int Engine::deposit() const {
    return m_deposit;
}

void Engine::setDeposit(int deposit) {
    if (m_deposit == deposit)
        return;

    m_deposit = deposit;
    emit depositChanged(m_deposit);
}


QString Engine::date() const {
    return m_date;
}

void Engine::setDate(QString date) {
    if (m_date == date)
        return;

    m_date = date;
    emit dateChanged(m_date);
}


int Engine::colbalance() const {
    return m_colbalance;
}

void Engine::setColbalance(int colbalance) {
    if (m_colbalance == colbalance)
        return;

    m_colbalance = colbalance;
    emit colbalanceChanged(m_colbalance);
}


int Engine::colcash() const {
    return m_colcash;
}

void Engine::setColcash(int colcash) {
    if (m_colcash == colcash)
        return;

    m_colcash = colcash;
    emit colcashChanged(m_colcash);
}


bool Engine::ispause_free() const {
    return m_ispause_free;
}

void Engine::setIsPauseFree(bool ispause_free) {
    if (m_ispause_free == ispause_free)
        return;

    m_ispause_free = ispause_free;
    emit isPauseFreeChanged(m_ispause_free);
}
//=========================================

void Engine::updateBalance(int amount) {
    if (amount <= 0) {
        logManager->addMsg("Попытка пополнения баланса на отрицательную или нулевую сумму", "Payment", "Ошибка");
        return;
    }

    // Обновляем баланс в базе данных через AccountManager
    if (m_accountManager) {
        m_accountManager->updateBalance(amount);
        logManager->addMsg("Баланс успешно пополнен на " + QString::number(amount) + " ₽", "Payment", "Информация");
    } else {
        logManager->addMsg("Ошибка обновления баланса: AccountManager не инициализирован", "Payment", "Ошибка");
    }
}


