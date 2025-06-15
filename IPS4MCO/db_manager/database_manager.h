#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QQueue>
#include <QMutex>
#include <QTimer>

class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

    bool connectToDatabase(const QString &host, const QString &database, 
                          const QString &username, const QString &password);
    bool isConnected() const;
    
    // Методы для работы с историей пополнений
    bool addReplenishment(const QString &cardNumber, double amount, 
                         const QString &terminalId);
    QList<QVariantMap> getReplenishmentHistory(const QString &cardNumber);
    
    // Методы для работы с офлайн-данными
    void queueOfflineOperation(const QString &operation, const QVariantMap &data);
    void processOfflineQueue();

signals:
    void connectionStatusChanged(bool connected);
    void syncCompleted();
    void syncError(const QString &error);

private slots:
    void checkConnection();
    void processSyncQueue();

private:
    QSqlDatabase m_db;
    bool m_isConnected;
    QQueue<QVariantMap> m_offlineQueue;
    QMutex m_queueMutex;
    QTimer m_syncTimer;
    
    bool createTables();
    bool syncOfflineData();
    void startSyncTimer();
};

#endif // DATABASE_MANAGER_H 