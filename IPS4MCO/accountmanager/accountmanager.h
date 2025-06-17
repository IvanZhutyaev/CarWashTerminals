#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCryptographicHash>
#include <QtNetwork/qnetworkconfigurationmanager.h>
#include <QHostInfo>


class AccountManager : public QObject
{
    Q_OBJECT
public:
    explicit AccountManager(QObject *parent = nullptr);
    ~AccountManager();

    Q_PROPERTY(bool isLoggedIn READ isLoggedIn NOTIFY loggedInChanged)
    Q_PROPERTY(QString currentBalance READ currentBalance NOTIFY currentBalanceChanged)
    Q_PROPERTY(QString loginMessage READ loginMessage NOTIFY loginMessageChanged)
    Q_PROPERTY(QString registrationMessage READ registrationMessage NOTIFY registrationMessageChanged)

    bool isLoggedIn() const { return m_isLoggedIn; }
    QString currentBalance() const { return m_currentBalance; }
    QString loginMessage() const { return m_loginMessage; }
    QString registrationMessage() const { return m_registrationMessage; }

signals:
    void loggedInChanged();
    void currentBalanceChanged();
    void loginMessageChanged();
    void registrationMessageChanged();
    void showPersonalAccount();
    void hidePersonalAccount();
    void registrationStatus(bool success, QString message);
    void loginStatus(bool success, QString message);
    void networkStatusChanged(bool isOnline);

public slots:
    void registerUser(const QString &phoneNumber, const QString &password);
    void loginUser(const QString &phoneNumber, const QString &password);
    void logoutUser();
    void checkNetworkStatus();
    void syncData(); // For future synchronization logic

private:
    QSqlDatabase m_centralDb; // PostgreSQL
    QSqlDatabase m_localDb;   // SQLite
    bool m_isLoggedIn = false;
    QString m_currentBalance = "0";
    QString m_loginMessage = "";
    QString m_registrationMessage = "";
    bool m_isOnline = false;

    void setLoggedIn(bool loggedIn);
    void setCurrentBalance(const QString &balance);
    void setLoginMessage(const QString &message);
    void setRegistrationMessage(const QString &message);
    void setIsOnline(bool online);

    bool openCentralDatabase();
    void closeCentralDatabase();
    bool openLocalDatabase();
    void closeLocalDatabase();
    void createTables();
    QString hashPassword(const QString &password);

    QNetworkConfigurationManager *m_networkConfigManager;

    // Temp. private properties for internal use
    QString m_currentUserId;
};

#endif // ACCOUNTMANAGER_H 
