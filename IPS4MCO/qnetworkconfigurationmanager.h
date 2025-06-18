#ifndef QNETWORKCONFIGURATIONMANAGER_H
#define QNETWORKCONFIGURATIONMANAGER_H
#include <QObject>

class QNetworkConfigurationManager : public QObject {
    Q_OBJECT
public:
    explicit QNetworkConfigurationManager(QObject *parent = nullptr) { Q_UNUSED(parent); }
    bool isOnline() const { return true; }
};

#endif // QNETWORKCONFIGURATIONMANAGER_H
