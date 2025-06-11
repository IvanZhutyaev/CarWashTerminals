#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <QObject>

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

#include "errors.h"

class LogManager : public QObject
{
    Q_OBJECT
public:
    explicit LogManager(QString file_path, QObject *parent = nullptr);
    void addMsg(int error);
    void addMsg(QString text, QString subsystyem = "All", QString messagetype = "Информационное сообщение", QString errorcode = "");

    const QString SYBSYS_COLORSCHEME {"CS"};

signals:

private:
    QMap<int, QString> map;
    QString file_path;
    QString last_massage = "";
};

#endif // LOGMANAGER_H
