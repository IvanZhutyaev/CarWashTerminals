#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
#include <QDebug>

#include "controller/modbuscontroller.h"
#include "engine/configmanager.h"
#include "engine/logmanager.h"
#include "pilotnt/pilotnt.h"
#include "../accountmanager/accountmanager.h"

#define FILE_PATH_MODBUS_CONFIG "config/modbus.json"
#define FILE_PATH_UI_CONFIG "config/ui.json"
#define FILE_PATH_LOG "log/"


class Engine : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int balance READ balance WRITE setBalance NOTIFY balanceChanged)
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QString pause_time READ pause_time WRITE setPauseTime NOTIFY pauseTimeChanged)
    Q_PROPERTY(int discountfix READ discountfix WRITE setDiscountfix NOTIFY discountfixChanged)
    Q_PROPERTY(int discountacc READ discountacc WRITE setDiscountacc NOTIFY discountaccChanged)
    Q_PROPERTY(int deposit READ deposit WRITE setDeposit NOTIFY depositChanged)
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(int colbalance READ colbalance WRITE setColbalance NOTIFY colbalanceChanged)
    Q_PROPERTY(int colcash READ colcash WRITE setColcash NOTIFY colcashChanged)
    Q_PROPERTY(bool ispause_free READ ispause_free WRITE setIsPauseFree NOTIFY isPauseFreeChanged)

    Q_PROPERTY(AccountManager* accountManager READ accountManager CONSTANT)

    explicit Engine(QString appdir, LogManager *logmanager, QObject *parent = nullptr);
    ~Engine();

    void initEvent();

    // Properties
    int balance() const;
    QString time() const;
    QString pause_time() const;
    int discountfix() const;
    int discountacc() const;
    int deposit() const;
    QString date() const;
    int colbalance() const;
    int colcash() const;
    bool ispause_free() const;
    AccountManager* accountManager() const { return m_accountManager; }

    Q_INVOKABLE void updateBalance(int amount);

signals:
    void showInitialization(int state, QString text = "");
    void showError(int error, QString text = "");
    void showWaiting();
    void showSession(int state);
    void showQR();
    void showCollection();
    void showWallet(int state);

    void showPaymentLoading(int state);
    void showPaymentError();

    void setQR(QString qr_string);
    void setPressedButtons(int buttons);
    void setUIConfig(QJsonObject config);

    // Properties
    void balanceChanged(int balance);
    void timeChanged(QString time);
    void pauseTimeChanged(QString pause_time);
    void discountfixChanged(int discountfix);
    void discountaccChanged(int discountacc);
    void depositChanged(int deposit);
    void dateChanged(QString date);
    void colbalanceChanged(int colbalance);
    void colcashChanged(int colcash);
    void isPauseFreeChanged(bool ispause_free);
public slots:
    void cppSetButtons(int buttons);
    void cppClerButtonStateQr();
    void cppClerButtonStateWallet();

    void cppSendPayment(int value, int back_screen);

    // Properties
    void setBalance(int balance);
    void setTime(QString time);
    void setPauseTime(QString pause_time);
    void setDiscountfix(int dicountfix);
    void setDiscountacc(int dicountacc);
    void setDeposit(int deposit);
    void setDate(QString date);
    void setColbalance(int colbalance);
    void setColcash(int colcash);
    void setIsPauseFree(bool ispause_free);

private:
    enum States {
        Initialization = 0,
        Error,
        Waiting,
        Session,
        QrCode,
        Collection,
        Wallet,
        HandleBank,
    };

    struct BankVars {
        bool wait = false;
        bool block_update = false;
        bool finish_from_plc = false;

        QElapsedTimer *elapsedTimer;
    } bank;
    int back_screen;

    QString appdir;

    PilotNT *bank_pilotnt;
    ModbusController *modbusController;
    LogManager *logManager;
    QTimer *timer;
    QTimer *delayTimer;
    QTimer *reconnectTimer;
    QTimer *initTimer;
    QElapsedTimer *elapsedTimer;
    QElapsedTimer *elapsedTimerSession;

    int state;
    int initialization_timeout = 30000;
    int number_of_programs = 5;
    int qr_code_timing = 5000;
    int qr_code_data_timeout = 5000;
    int error_timeout = 5000;
    int is_session_init;

    int slide_change_timeout = 1000;
    int init_slide_change_mult = 3;
    int button_timeout = 5000;
    // bt - BankTerminal
    int bt_error_timeout = 5000;
    int bt_success_timeout = 5000;

    bool write_buttons = false;
    unsigned int pbuttons = 0;

    int error = Errors::No;
    int last_error = Errors::No;
    int last_session_state = 0;

    // Properties
    int m_balance {0};
    QString m_time {""};
    QString m_pause_time {""};
    int m_discountfix {0};
    int m_discountacc {0};
    int m_deposit {0};
    QString m_date {""};
    int m_colbalance {0};
    int m_colcash {0};
    bool m_ispause_free {false};

    AccountManager *m_accountManager;

    void errorEvent();
    int st_waiting();
    int sessionEvent();
    int qrcodeEvent();
    int collectionEvent();
    int walletEvent();

    int sessionTransition();

    int setState(ModbusController::s_status status);
    int stateTransition(int state, ModbusController::s_status status);
    int stateEvent(int state);

    void paymentBankErrorMessage(int error, QString text);

private slots:
    void tEvent();
    void delayTimerSlot();
    void reconnectTimerSlot();
    void initTimerSlot();

    void paymentBankHandler(int error);
    void showSessionLocal();
};

#endif // ENGINE_H
