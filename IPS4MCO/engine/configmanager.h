#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "errors.h"

class ConfigManager : public QObject
{
    Q_OBJECT
public:
    explicit ConfigManager(QObject *parent = nullptr);

    struct s_modbus_config {
        QString PortName;
        int BaudRate;
        int DataBits;
        int Parity;
        int StopBits;
        int ServerAddress;
        int Timeout; // seconds
    };

    static int createModbusConfig(QString file_path);
    static int createUIConfig(QString file_path);

    static s_modbus_config readModbusConfig(QString file_path, int *error);
    static QJsonObject readUIConfig(QString file_path, int *error);

    static int checkModbusConfig(QJsonObject config);
    static int checkUIConfig(QJsonObject config);


private:
};

#endif // CONFIGMANAGER_H
