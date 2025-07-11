#include "database_manager.h"
#include <QDebug>
#include <QFile>
#include <QSettings>
#include <QTextStream>
#include <QDir>
QMap<QString, QString> loadEnvFile(const QString &path)
{
    QMap<QString, QString> env;
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Не удалось открыть .env файл!";
        return env;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        if (line.startsWith("#") || line.isEmpty()) continue;

        QStringList parts = line.split("=", Qt::SkipEmptyParts);
        if (parts.size() >= 2)
        {
            QString key = parts[0].trimmed();
            QString value = parts[1].trimmed();
            env[key] = value;
        }
    }

    file.close();
    return env;
}

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject(parent)
    , m_isConnected(false)
{
    m_syncTimer.setInterval(30000); // Проверка каждые 30 секунд
    connect(&m_syncTimer, &QTimer::timeout, this, &DatabaseManager::checkConnection);
}

DatabaseManager::~DatabaseManager()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DatabaseManager::connectToDatabase()
{

    auto env = loadEnvFile("../../.env");

    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName(env["DB_HOST"]);
    m_db.setDatabaseName(env["DB_NAME"]);
    m_db.setUserName(env["DB_USER"]);
    m_db.setPassword(env["DB_PASSWORD"]);
    m_db.setPort(env["DB_PORT"].toInt());

    if (!m_db.open()) {
        qDebug() << "Ошибка подключения к БД:" << m_db.lastError().text();
        m_isConnected = false;
        emit connectionStatusChanged(false);
        return false;
    }

    m_isConnected = true;
    emit connectionStatusChanged(true);
    
    if (!createTables()) {
        qDebug() << "Ошибка создания таблиц";
        return false;
    }

    startSyncTimer();
    return true;
}

bool DatabaseManager::isConnected() const
{
    return m_isConnected;
}

bool DatabaseManager::addReplenishment(const QString &cardNumber, double amount,
                                     const QString &terminalId)
{
    if (!m_isConnected) {
        // Если нет соединения, добавляем операцию в очередь
        QVariantMap operation;
        operation["type"] = "replenishment";
        operation["cardNumber"] = cardNumber;
        operation["amount"] = amount;
        operation["terminalId"] = terminalId;
        operation["timestamp"] = QDateTime::currentDateTime();
        
        QMutexLocker locker(&m_queueMutex);
        m_offlineQueue.enqueue(operation);
        return true;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO replenishments (card_number, amount, terminal_id, timestamp) "
                 "VALUES (:card_number, :amount, :terminal_id, :timestamp)");
    
    query.bindValue(":card_number", cardNumber);
    query.bindValue(":amount", amount);
    query.bindValue(":terminal_id", terminalId);
    query.bindValue(":timestamp", QDateTime::currentDateTime());

    if (!query.exec()) {
        qDebug() << "Ошибка добавления пополнения:" << query.lastError().text();
        return false;
    }

    return true;
}

QList<QVariantMap> DatabaseManager::getReplenishmentHistory(const QString &cardNumber)
{
    QList<QVariantMap> history;
    
    if (!m_isConnected) {
        return history;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM replenishments WHERE card_number = :card_number "
                 "ORDER BY timestamp DESC");
    query.bindValue(":card_number", cardNumber);

    if (!query.exec()) {
        qDebug() << "Ошибка получения истории:" << query.lastError().text();
        return history;
    }

    while (query.next()) {
        QVariantMap record;
        record["card_number"] = query.value("card_number").toString();
        record["amount"] = query.value("amount").toDouble();
        record["terminal_id"] = query.value("terminal_id").toString();
        record["timestamp"] = query.value("timestamp").toDateTime();
        history.append(record);
    }

    return history;
}

void DatabaseManager::queueOfflineOperation(const QString &operation, const QVariantMap &data)
{
    QMutexLocker locker(&m_queueMutex);
    data["type"] = operation;
    data["timestamp"] = QDateTime::currentDateTime();
    m_offlineQueue.enqueue(data);
}

void DatabaseManager::processOfflineQueue()
{
    if (!m_isConnected) {
        return;
    }

    QMutexLocker locker(&m_queueMutex);
    while (!m_offlineQueue.isEmpty()) {
        QVariantMap operation = m_offlineQueue.dequeue();
        QString type = operation["type"].toString();

        if (type == "replenishment") {
            addReplenishment(
                operation["cardNumber"].toString(),
                operation["amount"].toDouble(),
                operation["terminalId"].toString()
            );
        }
        // Добавьте обработку других типов операций здесь
    }

    emit syncCompleted();
}

void DatabaseManager::processSyncQueue() {
    // Обработка очереди синхронизации: переносим все офлайн-операции в БД
    if (!m_isConnected) return;
    QMutexLocker locker(&m_queueMutex);
    while (!m_offlineQueue.isEmpty()) {
        QVariantMap operation = m_offlineQueue.dequeue();
        QString type = operation["type"].toString();
        if (type == "replenishment") {
            addReplenishment(
                operation["cardNumber"].toString(),
                operation["amount"].toDouble(),
                operation["terminalId"].toString()
            );
        }
        // Здесь можно добавить обработку других типов операций (например, история, возвраты и т.д.)
    }
    emit syncCompleted();
}

void DatabaseManager::checkConnection()
{
    if (!m_db.isOpen()) {
        m_isConnected = false;
        emit connectionStatusChanged(false);
        return;
    }

    QSqlQuery query("SELECT 1");
    if (!query.exec()) {
        m_isConnected = false;
        emit connectionStatusChanged(false);
        return;
    }

    if (!m_isConnected) {
        m_isConnected = true;
        emit connectionStatusChanged(true);
        processOfflineQueue();
    }
}

bool DatabaseManager::createTables()
{
    QSqlQuery query;
    
    // Таблица для истории пополнений
    if (!query.exec("CREATE TABLE IF NOT EXISTS replenishments ("
                   "id INT AUTO_INCREMENT PRIMARY KEY,"
                   "card_number VARCHAR(50) NOT NULL,"
                   "amount DECIMAL(10,2) NOT NULL,"
                   "terminal_id VARCHAR(50) NOT NULL,"
                   "timestamp DATETIME NOT NULL,"
                   "INDEX idx_card_number (card_number),"
                   "INDEX idx_timestamp (timestamp))")) {
        qDebug() << "Ошибка создания таблицы replenishments:" << query.lastError().text();
        return false;
    }

    return true;
}

void DatabaseManager::startSyncTimer()
{
    m_syncTimer.start();
}
