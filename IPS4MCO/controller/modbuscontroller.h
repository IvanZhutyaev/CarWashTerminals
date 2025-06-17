#ifndef MODBUSCONTROLLER_H
#define MODBUSCONTROLLER_H

#include <QObject>


#include <QModbusServer>
#include <QtSerialBus/qmodbusrtuserialserver.h>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTimer>

#include "errors.h"
#include <QDebug>

#define REG_CMD_FPANEL      0
#define REG_CMD1_TPANEL     1
#define REG_CMD2_TPANEL     2
#define REG_ERROR_CODE      3

#define REG_TIME            5
#define REG_BALANCE         6

#define REG_DISCOUNT_FIX    7
#define REG_DEPOSIT         8
#define REG_DISCOUNT_ACC    9
#define REG_DISCOUNT_DATE   10

#define REG_BANK_DEPOSIT    11

#define REG_SUM_ENCHASH     15
#define REG_PAUSE_TIME      16
#define REG_PING            20


#define REG_QR_DATE         30 // lenght: 2
#define REG_QR_TIME         32 // lenght: 1
#define REG_QR_PRICE        33 // lenght: 2
#define REG_QR_FISCAL       35 // lenght: 4
#define REG_QR_FP           39 // lenght: 2
#define REG_QR_DOCNUM       41 // lenght: 2
#define REG_QR_SIGNTYPE     43 // lenght: 1

class ModbusController : public QObject
{
    Q_OBJECT
public:
    explicit ModbusController(QObject *parent = nullptr);
    ~ModbusController();

    struct s_status {
        bool empty;
        bool collection;
        bool qrcode;
        bool pingerror;
        bool pause_free;
        bool bank;
        int wallet;
        int session;
        int raw;

    };

    struct s_session {
        unsigned int balance;
        unsigned int minute;
        unsigned int seconds;
        unsigned int buttons;
        unsigned int pause_minute;
        unsigned int pause_seconds;
        bool ispause_free;
    };

    struct s_wallet {
        unsigned int discount_fix;
        unsigned int discount_acc;
        unsigned int deposit;
        unsigned int day;
        unsigned int mounth;
    };

    struct s_collection {
        unsigned int balance;
        unsigned int cash;
    };


    int create();
    int connect();
    int connect(QString Port, int Parity, int BaudRate, int DataBits, int StopBits, int ServerAddress, int Timeout);
    int disconnect();
    bool isConnected();
    int getError();
    QString getEmptyQR();

    s_session readInSession();
    QString readQrCode();
    s_status readStatus();
    s_wallet readWallet();
    s_collection readCollection();
    int readControlMsg();

    int writeButtons(quint16 buttons);
    int clearButtonState(int reg, int btn_mask);

    int writeBankPayment(quint16 value);

signals:


private:
    QModbusServer *modbusDevice = nullptr;
    QTimer *controlMsgTimer;


    struct s_error {
        int qt;
        int internal = Errors::No;
        int controlmsg = Errors::No;
    };

    struct s_config {
        QString PortName;
        int BaudRate;
        int DataBits;
        int Parity;
        int StopBits;
        int ServerAddress;
        int Timeout; // seconds
    };

    s_error error;
    s_config config;


private slots:
    void controlMsgTimerSlot();
    void DebugDataWriten(QModbusDataUnit::RegisterType table, int address, int size);
};

#endif // MODBUSCONTROLLER_H
