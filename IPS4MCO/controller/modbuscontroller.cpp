#include "modbuscontroller.h"

ModbusController::ModbusController(QObject *parent) : QObject(parent) {
    controlMsgTimer = new QTimer();
    error.controlmsg = Errors::MCTimeout;
    error.internal = Errors::No;
    QObject::connect(controlMsgTimer, &QTimer::timeout, this, &ModbusController::controlMsgTimerSlot);
}

ModbusController::~ModbusController() {
    if (modbusDevice->state() == QModbusDevice::ConnectedState)
        modbusDevice->disconnect();

    if (modbusDevice)
        modbusDevice->disconnectDevice();

    delete modbusDevice;

}


int ModbusController::create() {
    error.internal = Errors::No;
    if (modbusDevice) {
         modbusDevice->disconnect();
         delete modbusDevice;
         modbusDevice = nullptr;
    }
    modbusDevice = new QModbusRtuSerialSlave(this);

    if (modbusDevice) {
        QModbusDataUnitMap reg;
        reg.insert(QModbusDataUnit::HoldingRegisters, { QModbusDataUnit::HoldingRegisters, 0, 44});
        //reg.insert(QModbusDataUnit::HoldingRegisters, { QModbusDataUnit::HoldingRegisters, 10, 1});
        //reg.insert(QModbusDataUnit::HoldingRegisters, { QModbusDataUnit::HoldingRegisters, 20, 11});
        modbusDevice->setMap(reg);
        QObject::connect(modbusDevice, &QModbusServer::dataWritten, this, &ModbusController::DebugDataWriten);
    } else {
        error.internal = Errors::MCCreateDevice;
    }

    return error.internal;

}

void ModbusController::DebugDataWriten(QModbusDataUnit::RegisterType table, int address, int size) {
    QString sdata = "";
    quint16 data;
    for (int i{}; i < size; ++i) {
        modbusDevice->data(table, address + i, &data);
        sdata += QString::number(data) + ", ";
    }
    qDebug() << "DEBUG: Data writed on start addr: " << address << "; size: " << size << "; data: " + sdata;
}

int ModbusController::connect() {
    error.internal = Errors::No;
    if (modbusDevice->state() == QModbusDevice::UnconnectedState && modbusDevice){

        modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter, config.PortName);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter, config.Parity);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, config.BaudRate);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, config.DataBits);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, config.StopBits);
        modbusDevice->setServerAddress(config.ServerAddress);

        if (!modbusDevice->connectDevice()){
            error.qt = modbusDevice->error();
            error.internal = Errors::MCConnect;
        } else {
            //controlMsgTimerSlot();
            controlMsgTimer->start();
        }
    } else {
        error.internal = Errors::MCAlreadyConnected;
    }

    return error.internal;
}


int ModbusController::connect(QString Port, int Parity, int BaudRate, int DataBits, int StopBits, int ServerAddress, int Timeout) {
    config.PortName = Port;
    config.Parity = Parity;
    config.BaudRate = BaudRate;
    config.DataBits = DataBits;
    config.StopBits = StopBits;
    config.ServerAddress = ServerAddress;
    config.Timeout = Timeout;
    controlMsgTimer->setInterval(Timeout);
    return connect();
}


int ModbusController::disconnect() {
    error.internal = Errors::No;
    controlMsgTimer->stop();

    if (modbusDevice->state() == QModbusDevice::ConnectedState) {
        if (!modbusDevice->disconnect()) {
            error.qt = modbusDevice->error();
            error.internal = Errors::MCDisconnect;
        }
    }

    return error.internal;
}


bool ModbusController::isConnected() {
    return modbusDevice->state() == QModbusDevice::ConnectedState;
}


int ModbusController::getError() {
    return error.internal;
}

QString ModbusController::getEmptyQR() {
    return "t=0T0&s=0&fn=0&i=0&fp=0&n=0";
}


int ModbusController::writeBankPayment(quint16 value) {
    error.internal = Errors::No;
    if (modbusDevice->state() == QModbusDevice::ConnectedState) {
        modbusDevice->setData(QModbusDataUnit::HoldingRegisters, REG_BANK_DEPOSIT, value);
        modbusDevice->setData(QModbusDataUnit::HoldingRegisters, REG_CMD_FPANEL, 1 << 8);
    } else {
        error.internal = Errors::MCConnectionLost;
    }

    return error.internal;
}


int ModbusController::writeButtons(quint16 buttons) {
    qDebug() << "writeButtons: " << buttons;
    error.internal = Errors::No;
    if (modbusDevice->state() == QModbusDevice::ConnectedState) {
        modbusDevice->setData(QModbusDataUnit::HoldingRegisters, REG_CMD_FPANEL, buttons);
    } else {
        error.internal = Errors::MCConnectionLost;
    }

    return error.internal;
}


int ModbusController::clearButtonState(int reg, int btn_mask) {
    error.internal = Errors::No;
    quint16 regdata;

    if (modbusDevice->state() == QModbusDevice::ConnectedState) {
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, reg, &regdata);
        modbusDevice->setData(QModbusDataUnit::HoldingRegisters, reg, regdata & !btn_mask);
    } else {
        error.internal = Errors::MCConnectionLost;
    }

    return error.internal;
}


ModbusController::s_session ModbusController::readInSession() {
    error.internal = Errors::No;
    s_session session;
    quint16 raw_status1;
    quint16 raw_status2;
    quint16 time;
    quint16 pause_time;
    quint16 balance;


    if (modbusDevice->state() == QModbusDevice::ConnectedState) {
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_CMD1_TPANEL, &raw_status1);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_CMD2_TPANEL, &raw_status2);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_TIME, &time);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_BALANCE, &balance);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_PAUSE_TIME, &pause_time);

        session.buttons = (raw_status1 & 0xFF);
        session.ispause_free = (raw_status2 & 0x4);

        session.balance = balance;
        session.minute = time >> 8;
        session.seconds = time & 0x00FF;

        session.pause_minute = pause_time >> 8;
        session.pause_seconds = pause_time & 0x00FF;
    } else {
        error.internal = Errors::MCConnectionLost;
    }

    return session;
}


QString ModbusController::readQrCode() {
    error.internal = Errors::No;
    quint16 status;
    quint16 date1 = 0;
    quint16 date2 = 0;
    quint16 time = 0;
    quint16 price1 = 0;
    quint16 price2 = 0;
    quint16 fiscal1 = 0;
    quint16 fiscal2 = 0;
    quint16 fiscal3 = 0;
    quint16 fiscal4 = 0;
    quint16 calc1 = 0;
    quint16 calc2 = 0;
    quint16 docnum1 = 0;
    quint16 docnum2 = 0;
    quint16 operation_type = 0;

    unsigned int date = 0;
    unsigned int price = 0;
    QString sprice = "";
    unsigned long long fiscal = 0;
    unsigned int calc = 0;
    unsigned int document_number = 0;


    QString qr_string = "";


    if (modbusDevice->state() == QModbusDevice::ConnectedState) {
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_CMD2_TPANEL, &status);
        if (!(status & 0x2))
            return getEmptyQR();



        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_DATE, &date1);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_DATE + 1, &date2);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_TIME, &time);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_PRICE, &price1);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_PRICE + 1, &price2);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_FISCAL, &fiscal1);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_FISCAL + 1, &fiscal2);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_FISCAL + 2, &fiscal3);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_FISCAL + 3, &fiscal4);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_FP, &calc1);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_FP + 1, &calc2);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_DOCNUM, &docnum1);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_DOCNUM + 1, &docnum2);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_QR_SIGNTYPE, &operation_type);

        date = (date1 << 16) | date2;
        price = (price1 << 16) | price2;
        sprice = QVariant(price).toString();
        fiscal = (unsigned long long)fiscal1 | ((unsigned long long)fiscal2 << 16) | ((unsigned long long)fiscal3 << 32) | ((unsigned long long)fiscal4 << 48);
        calc = (calc1 << 16) | calc2;
        document_number = (docnum1 << 16) | docnum2;

        qr_string = "t="   + QVariant(date).toString() +
                    "T"    + QVariant(time).toString() +
                    "&s="  + sprice.left(sprice.length() - 2) + "." + sprice.right(2) +
                    "&fn=" + QVariant(fiscal).toString() +
                    "&i="  + QVariant(document_number).toString() +
                    "&fp=" + QVariant(calc).toString() +
                    "&n="  + QVariant(operation_type).toString();
    } else {
        error.internal = Errors::MCConnectionLost;
    }

    return qr_string;
}


void ModbusController::controlMsgTimerSlot() {
    readControlMsg();
}

//read "Командное слово от ПЛК"(1), "Слово состояния системы от ПЛК"(2)
ModbusController::s_status ModbusController::readStatus() {
    error.internal = Errors::No;
    quint16 raw_status1 = 0;
    quint16 raw_status2 = 0;
    quint16 balance = 0;
    quint16 time = 0;
    //quint16 pause_time = 0;
    quint16 err = 0;
    quint16 bank_dep = 0;
    s_status status;
    status.raw = 0;
    status.pingerror = error.controlmsg;
    status.bank = false;
    QModbusDevice::State ms = modbusDevice->state();

    if (ms == QModbusDevice::ConnectedState) {
        if (error.controlmsg) {
            controlMsgTimer->start(); // restart timerx
            error.internal = 0;//readControlMsg();
            // for call transition function
            status.raw = status.raw | ((error.internal != 0) << 31);
            status.pingerror = (error.internal != 0);
            if (error.internal)
                return status;
        }


        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_CMD1_TPANEL, &raw_status1);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_CMD2_TPANEL, &raw_status2);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_BALANCE, &balance);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_TIME, &time);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_ERROR_CODE, &err);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_BANK_DEPOSIT, &bank_dep);
        //modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_PAUSE_TIME, &pause_time);
        //qDebug() << "raw_status1: " << raw_status1;
        //qDebug() << "raw_status2: " << raw_status2;
        //qDebug() << "balance: " << balance;
        //qDebug() << "time: " << time;
        //qDebug() << "err: " << err;

        //status.session = balance != 0;
        status.session = time != 0;
        //status.empty = ((raw_status1 == 0) && (raw_status2 == 0) && (balance == 0));
        status.empty = ((raw_status1 == 0) && (raw_status2 == 0) && (time == 0));
        status.raw = status.raw | (raw_status1 >> 8) | ((raw_status2 & (~(0x2))) << 8);
        //status.raw = status.raw | ((balance != 0) << 30);
        status.raw = status.raw | ((time != 0) << 30);
        status.raw = status.raw | ((err != 0) << 29);
        status.raw = status.raw | ((bank_dep != 0) << 28);
        status.bank = bank_dep != 0;

        if (err) {
            error.internal = Errors::MCPLC + err;
        }

        if (!status.empty) {
            if ((raw_status1 & 0x100) || err)
                error.internal = Errors::MCPLC + err;

            status.collection = (raw_status1 & 0x800) >> 11;
            status.wallet = (raw_status1 & 0xF000) >> 12;
            status.session = status.session | ((raw_status1 & 0x600) >> 8);// | (((raw_status2 & 0x4) != 0) << 3);
            status.qrcode = (raw_status2 & 0x1); // show generating slide. in readQRCode read 1st bit and show qr slide.
            status.pause_free = (raw_status2 & 0x4);
        }
    } else {
        error.internal = Errors::MCConnectionLost;
    }

    return status;
}



ModbusController::s_wallet ModbusController::readWallet() {
    error.internal = Errors::No;
    quint16 discount_fix = 0;
    quint16 discount_acc = 0;
    quint16 deposit = 0;
    quint16 date = 0;
    s_wallet wallet;


    if (modbusDevice->state() == QModbusDevice::ConnectedState) {
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_DISCOUNT_FIX, &discount_fix);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_DISCOUNT_ACC, &discount_acc);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_DEPOSIT, &deposit);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_DISCOUNT_DATE, &date);

        wallet.discount_fix = discount_fix;
        wallet.discount_acc = discount_acc;
        wallet.deposit = deposit;
        wallet.mounth = date >> 8;
        wallet.day = date & 0x00FF;
    } else {
        error.internal = Errors::MCConnectionLost;
    }

    return wallet;
}


ModbusController::s_collection ModbusController::readCollection() {
    error.internal = Errors::No;
    quint16 balance = 0;
    quint16 cash = 0;
    s_collection collection;


    if (modbusDevice->state() == QModbusDevice::ConnectedState) {
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_BALANCE, &balance);
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_SUM_ENCHASH, &cash);

        collection.balance = balance;
        collection.cash = cash;
    } else {
        error.internal = Errors::MCConnectionLost;
    }

    return collection;
}


int ModbusController::readControlMsg() {
    error.controlmsg = Errors::No;
    quint16 msg = 0;
    if (modbusDevice->state() == QModbusDevice::ConnectedState) {
        modbusDevice->data(QModbusDataUnit::HoldingRegisters, REG_PING, &msg);
        if (msg) {
            qDebug() << "readControlMsg: Ok";
            modbusDevice->setData(QModbusDataUnit::HoldingRegisters, REG_PING, 0);
        } else {
            qDebug() << "readControlMsg: MCTimeout";
            error.controlmsg = Errors::MCTimeout;
        }
    } else {
        qDebug() << "readControlMsg: MCConnectionLost";
        error.controlmsg = Errors::MCConnectionLost;
    }
    return error.controlmsg;
}







