#ifndef PILOTNT_H
#define PILOTNT_H

#include <QObject>

#include <QProcess>
#include <QTimer>

#include <QFile>
#include <QTextStream>
#include <QDebug>
#define DEBUG 0


#define FILE_OPERATION_RESULT "../PilotNT/e"

class PilotNT : public QObject
{
    Q_OBJECT
public:
    explicit PilotNT(QObject *parent = nullptr);
    ~PilotNT();

    enum Errors{
        NoErrors = 0,
        FileNotExist = 10000,
        FileNotOpen = 10001,
        ProcessAlreadyRun = 10002,

        Timeout = 2002,
        Timeout2 = 254,
        TimeoutPinPad = 2004,

        NotEnouthMoney = 521,
        NotEnouthMoney2 = 4451,

        MissedPinCode = 403,
        MissedPinCode2 = 4455,

        OperationCanceled = 2000,
        OperationCanceled1 = 250,

        CloseSession = 4123,
        CloseSession2 = 4142,
        CloseSession3 = 4134,
        CloseSession4 = 4130,

        CancelOperation = 4325,
        KillProcess = 10004,

    };


    bool isRunning();
    int getError();
    void sentSale(int price);
    void cancelPayment();
    void closeSession();
    bool isCloseSession();
    int getLastPrice();

signals:
    void finished(int code);

private:
    const QString program_file = "../PilotNT/sb_pilot";
    QProcess *PilotNTProcess;
    QFile *fileOperationResult;
    int error = Errors::NoErrors;
    bool closedSession = false;
    int last_price = 0;

private slots:
    void process_finished_handler(int exitCode, QProcess::ExitStatus exitStatus);
    void sentRequest (QStringList arguments);

};

#endif // PILOTNT_H
