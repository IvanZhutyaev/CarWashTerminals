#include "pilotnt.h"

PilotNT::PilotNT(QObject *parent) : QObject(parent)
{
    PilotNTProcess = new QProcess(this);
    fileOperationResult = new QFile (FILE_OPERATION_RESULT);
    connect(PilotNTProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &PilotNT::process_finished_handler);
}

PilotNT::~PilotNT() {
    if (PilotNTProcess->state() != QProcess::NotRunning)
        cancelPayment();

    if (fileOperationResult->isOpen())
        fileOperationResult->close();

    if (PilotNTProcess)
        delete PilotNTProcess;

    if (fileOperationResult)
        delete fileOperationResult;
}

void PilotNT::sentRequest(QStringList arguments) {
    if (PilotNTProcess->state() == QProcess::NotRunning) {
        PilotNTProcess->start(program_file, arguments);
        error = Errors::NoErrors;
    } else
        error = Errors::ProcessAlreadyRun;
}

bool PilotNT::isRunning() {
    return PilotNTProcess->state() != QProcess::NotRunning;
}

bool PilotNT::isCloseSession() {
    bool cs = closedSession;
    closedSession = false;
    return cs;
}

int PilotNT::getError() {
    return error;
}

int PilotNT::getLastPrice() {
    return last_price;
}


void PilotNT::sentSale(int price) {
    QStringList arguments;
    last_price = price;
    arguments << "1" << QVariant(price).toString();
    closedSession = false;
    sentRequest(arguments);
}

void PilotNT::closeSession() {
    QStringList arguments;
    arguments << "7";
    closedSession = true;
    sentRequest(arguments);
}

void PilotNT::cancelPayment() {
    QStringList arguments;
    arguments << "3";
    if (PilotNTProcess->state() != QProcess::NotRunning)
        PilotNTProcess->close();
    sentRequest(arguments);
}


void PilotNT::process_finished_handler(int exitCode, QProcess::ExitStatus exitStatus) {
    if (DEBUG) qDebug() << "ExitCode: " << exitCode << "; ExitStatus: " << exitStatus;
    if (exitCode != 0) {
        if (fileOperationResult->exists()){
            if (fileOperationResult->open(QIODevice::ReadOnly)){
                QTextStream cfgread(fileOperationResult);
                error = cfgread.readLine().split(',').first().toInt();
                fileOperationResult->close();
            } else {
                error = Errors::FileNotOpen;
            }
        } else {
             error =  Errors::FileNotExist;
        }
    } else
        error = Errors::NoErrors;

    if (DEBUG) qDebug() << error;
    emit finished(error);
}

