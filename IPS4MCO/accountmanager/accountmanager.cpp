#include "accountmanager.h"
#include <QNetworkInformation>
#include <QDateTime>

AccountManager::AccountManager(QObject *parent) : QObject(parent) {
    // Central Database (PostgreSQL)
    m_centralDb = QSqlDatabase::addDatabase("QPSQL", "central_db");
    m_centralDb.setHostName("your_pg_host"); // TODO: Replace with actual host
    m_centralDb.setPort(5432); // Default PostgreSQL port
    m_centralDb.setDatabaseName("your_pg_database"); // TODO: Replace with actual database name
    m_centralDb.setUserName("your_pg_user"); // TODO: Replace with actual user
    m_centralDb.setPassword("your_pg_password"); // TODO: Replace with actual password

    // Local Database (SQLite)
    m_localDb = QSqlDatabase::addDatabase("QSQLITE", "local_db");
    m_localDb.setDatabaseName("local_users.sqlite"); // Local SQLite database file

    // Network status manager
    m_networkConfigManager = new QNetworkConfigurationManager(this);
    connect(QNetworkInformation::instance(), &QNetworkInformation::reachabilityChanged,
            this, [this](QNetworkInformation::Reachability reachability) {
                setIsOnline(reachability == QNetworkInformation::Reachability::Online);
            });

    // Initial network check
    checkNetworkStatus();

    // Open databases and create tables
    openCentralDatabase();
    openLocalDatabase();
    createTables(); // Create tables in both databases if they don't exist
}

AccountManager::~AccountManager() {
    closeCentralDatabase();
    closeLocalDatabase();
}

void AccountManager::setLoggedIn(bool loggedIn) {
    if (m_isLoggedIn == loggedIn)
        return;
    m_isLoggedIn = loggedIn;
    emit loggedInChanged();
}

void AccountManager::setCurrentBalance(const QString &balance) {
    if (m_currentBalance == balance)
        return;
    m_currentBalance = balance;
    emit currentBalanceChanged();
}

void AccountManager::setLoginMessage(const QString &message) {
    if (m_loginMessage == message)
        return;
    m_loginMessage = message;
    emit loginMessageChanged();
}

void AccountManager::setRegistrationMessage(const QString &message) {
    if (m_registrationMessage == message)
        return;
    m_registrationMessage = message;
    emit registrationMessageChanged();
}

void AccountManager::setIsOnline(bool online) {
    if (m_isOnline == online)
        return;
    m_isOnline = online;
    emit networkStatusChanged(m_isOnline);
    if (!m_isOnline) {
        setRegistrationMessage("Регистрация временно недоступна");
        setLoginMessage("Вход временно недоступен");
    } else {
        setRegistrationMessage(""); // Clear message if online
        setLoginMessage(""); // Clear message if online
    }
}

bool AccountManager::openCentralDatabase() {
    if (!m_centralDb.isOpen()) {
        if (!m_centralDb.open()) {
            qWarning() << "Error opening central database:" << m_centralDb.lastError().text();
            return false;
        }
        qDebug() << "Central database opened successfully.";
    }
    return true;
}

void AccountManager::closeCentralDatabase() {
    if (m_centralDb.isOpen()) {
        m_centralDb.close();
        qDebug() << "Central database closed.";
    }
}

bool AccountManager::openLocalDatabase() {
    if (!m_localDb.isOpen()) {
        if (!m_localDb.open()) {
            qWarning() << "Error opening local database:" << m_localDb.lastError().text();
            return false;
        }
        qDebug() << "Local database opened successfully.";
    }
    return true;
}

void AccountManager::closeLocalDatabase() {
    if (m_localDb.isOpen()) {
        m_localDb.close();
        qDebug() << "Local database closed.";
    }
}

void AccountManager::createTables() {
    // Create users table in central database if it doesn't exist
    if (openCentralDatabase()) {
        QSqlQuery query(m_centralDb);
        if (!query.exec("CREATE TABLE IF NOT EXISTS users (" // Use IF NOT EXISTS for idempotence
                        "id SERIAL PRIMARY KEY, "
                        "phone_number VARCHAR(20) UNIQUE NOT NULL, "
                        "password_hash TEXT NOT NULL, "
                        "balance INTEGER DEFAULT 0)")) {
            qWarning() << "Error creating users table in central DB:" << query.lastError().text();
        } else {
            qDebug() << "Users table ensured in central DB.";
        }
    }

    // Create users table in local database if it doesn't exist
    if (openLocalDatabase()) {
        QSqlQuery query(m_localDb);
        if (!query.exec("CREATE TABLE IF NOT EXISTS users (" // Use IF NOT EXISTS for idempotence
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "phone_number TEXT UNIQUE NOT NULL, "
                        "password_hash TEXT NOT NULL, "
                        "balance INTEGER DEFAULT 0)")) {
            qWarning() << "Error creating users table in local DB:" << query.lastError().text();
        } else {
            qDebug() << "Users table ensured in local DB.";
        }
    }

    // Create top-up history table in central database if it doesn't exist
    if (openCentralDatabase()) {
        QSqlQuery query(m_centralDb);
        if (!query.exec("CREATE TABLE IF NOT EXISTS top_ups (" // Use IF NOT EXISTS for idempotence
                        "id SERIAL PRIMARY KEY, "
                        "user_id INTEGER REFERENCES users(id), "
                        "amount INTEGER NOT NULL, "
                        "timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP)")) {
            qWarning() << "Error creating top_ups table in central DB:" << query.lastError().text();
        } else {
            qDebug() << "Top-ups table ensured in central DB.";
        }
    }

    // Create top-up history table in local database if it doesn't exist
    if (openLocalDatabase()) {
        QSqlQuery query(m_localDb);
        if (!query.exec("CREATE TABLE IF NOT EXISTS top_ups (" // Use IF NOT EXISTS for idempotence
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "user_id INTEGER, " // No foreign key constraint for simplicity in local cache
                        "amount INTEGER NOT NULL, "
                        "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP)")) {
            qWarning() << "Error creating top_ups table in local DB:" << query.lastError().text();
        } else {
            qDebug() << "Top-ups table ensured in local DB.";
        }
    }
}

QString AccountManager::hashPassword(const QString &password) {
    QByteArray passwordData = password.toUtf8();
    return QString(QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256).toHex());
}

void AccountManager::registerUser(const QString &phoneNumber, const QString &password) {
    if (!m_isOnline) {
        setRegistrationMessage("Регистрация временно недоступна: нет подключения к серверу.");
        emit registrationStatus(false, m_registrationMessage);
        return;
    }

    if (!openCentralDatabase()) {
        setRegistrationMessage("Ошибка регистрации: не удалось подключиться к серверу базы данных.");
        emit registrationStatus(false, m_registrationMessage);
        return;
    }

    bool ok;
    password.toLongLong(&ok);
    if (password.length() != 6 || !ok || password.contains(".")) {
        setRegistrationMessage("Пароль должен быть 6-значным числом.");
        emit registrationStatus(false, m_registrationMessage);
        return;
    }

    QString hashedPassword = hashPassword(password);

    QSqlQuery query(m_centralDb);
    query.prepare("INSERT INTO users (phone_number, password_hash) VALUES (:phone, :password)");
    query.bindValue(":phone", phoneNumber);
    query.bindValue(":password", hashedPassword);

    if (!query.exec()) {
        if (query.lastError().nativeErrorCode() == "23505") { // PostgreSQL unique violation error code
            setRegistrationMessage("Пользователь с таким номером телефона уже зарегистрирован.");
        } else {
            setRegistrationMessage("Ошибка регистрации: " + query.lastError().text());
        }
        emit registrationStatus(false, m_registrationMessage);
    } else {
        setRegistrationMessage("Регистрация прошла успешно!");
        emit registrationStatus(true, m_registrationMessage);
        // Optionally, automatically log in the user after successful registration
        // loginUser(phoneNumber, password);
    }
    closeCentralDatabase();
}

void AccountManager::handleDatabaseError(const QSqlQuery &query)
{
    QString errorCode = query.lastError().nativeErrorCode();
    QString errorText = query.lastError().text();

    // Проверка для PostgreSQL
    if (errorCode == "23505" || errorText.contains("unique", Qt::CaseInsensitive)) {
        emit registrationFailed("Пользователь с таким email уже существует");
    }
    // Проверка для SQLite
    else if (errorCode == "19" || errorText.contains("UNIQUE constraint", Qt::CaseInsensitive)) {
        emit registrationFailed("Пользователь с таким email уже существует");
    }
    else {
        emit registrationFailed("Ошибка базы данных: " + errorText);
    }
}

void AccountManager::logoutUser() {
    setLoggedIn(false);
    setCurrentBalance("0");
    m_currentUserId = "";
    setLoginMessage("Вы вышли из личного кабинета.");
    emit hidePersonalAccount(); // Signal to hide personal account view
}

void AccountManager::checkNetworkStatus() {
    // This is a basic check. For more robust network status, consider QNetworkAccessManager and pinging a known host.
    // QNetworkConfigurationManager::isOnline() generally reflects interface status, not necessarily internet reachability.
    bool online = m_networkConfigManager->isOnline();
    setIsOnline(online);
}

void AccountManager::syncData() {
    // Пример синхронизации: переносим все локальные пополнения в центральную БД при восстановлении связи
    if (!m_isOnline) return;
    if (!openCentralDatabase() || !openLocalDatabase()) return;
    QSqlQuery localQuery(m_localDb);
    localQuery.prepare("SELECT user_id, amount, timestamp FROM top_ups");
    if (localQuery.exec()) {
        while (localQuery.next()) {
            int userId = localQuery.value(0).toInt();
            int amount = localQuery.value(1).toInt();
            QDateTime timestamp = localQuery.value(2).toDateTime();
            // Добавляем в центральную БД, если такой записи нет
            QSqlQuery checkQuery(m_centralDb);
            checkQuery.prepare("SELECT COUNT(*) FROM top_ups WHERE user_id = :user_id AND amount = :amount AND timestamp = :timestamp");
            checkQuery.bindValue(":user_id", userId);
            checkQuery.bindValue(":amount", amount);
            checkQuery.bindValue(":timestamp", timestamp);
            if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() == 0) {
                QSqlQuery insertQuery(m_centralDb);
                insertQuery.prepare("INSERT INTO top_ups (user_id, amount, timestamp) VALUES (:user_id, :amount, :timestamp)");
                insertQuery.bindValue(":user_id", userId);
                insertQuery.bindValue(":amount", amount);
                insertQuery.bindValue(":timestamp", timestamp);
                insertQuery.exec();
            }
        }
    }
    closeCentralDatabase();
    closeLocalDatabase();
    qDebug() << "Synchronization completed.";
}

void AccountManager::updateBalance(int amount) {
    if (!m_isLoggedIn || m_currentUserId.isEmpty()) {
        setLoginMessage("Ошибка: пользователь не авторизован");
        emit loginStatus(false, m_loginMessage);
        return;
    }
    if (!m_isOnline) {
        setLoginMessage("Пополнение баланса временно недоступно: нет подключения к серверу.");
        emit loginStatus(false, m_loginMessage);
        return;
    }
    if (!openCentralDatabase()) {
        setLoginMessage("Ошибка пополнения: не удалось подключиться к серверу базы данных.");
        emit loginStatus(false, m_loginMessage);
        return;
    }
    QSqlQuery query(m_centralDb);
    query.prepare("UPDATE users SET balance = balance + :amount WHERE id = :id");
    query.bindValue(":amount", amount);
    query.bindValue(":id", m_currentUserId);
    if (!query.exec()) {
        setLoginMessage("Ошибка пополнения: " + query.lastError().text());
        emit loginStatus(false, m_loginMessage);
        closeCentralDatabase();
        return;
    }
    // Добавляем запись в историю пополнений
    QSqlQuery historyQuery(m_centralDb);
    historyQuery.prepare("INSERT INTO top_ups (user_id, amount) VALUES (:user_id, :amount)");
    historyQuery.bindValue(":user_id", m_currentUserId);
    historyQuery.bindValue(":amount", amount);
    historyQuery.exec(); // Не критично, если не удалось
    // Получаем новый баланс
    QSqlQuery balanceQuery(m_centralDb);
    balanceQuery.prepare("SELECT balance FROM users WHERE id = :id");
    balanceQuery.bindValue(":id", m_currentUserId);
    if (balanceQuery.exec() && balanceQuery.next()) {
        setCurrentBalance(balanceQuery.value(0).toString());
    }
    setLoginMessage("");
    emit loginStatus(true, "Баланс успешно пополнен");
    closeCentralDatabase();
}

void AccountManager::loginUser(const QString& phoneNumber, const QString& password) {
    if (!m_isOnline) {
        setLoginMessage("Вход временно недоступен: нет подключения к серверу.");
        emit loginStatus(false, m_loginMessage);
        return;
    }
    if (!openCentralDatabase()) {
        setLoginMessage("Ошибка входа: не удалось подключиться к серверу базы данных.");
        emit loginStatus(false, m_loginMessage);
        return;
    }
    QString hashedPassword = hashPassword(password);
    QSqlQuery query(m_centralDb);
    query.prepare("SELECT id, balance FROM users WHERE phone_number = :phone AND password_hash = :password");
    query.bindValue(":phone", phoneNumber);
    query.bindValue(":password", hashedPassword);
    if (!query.exec() || !query.next()) {
        setLoginMessage("Неверный номер телефона или пароль.");
        emit loginStatus(false, m_loginMessage);
        closeCentralDatabase();
        return;
    }
    int userId = query.value(0).toInt();
    int balance = query.value(1).toInt();
    m_currentUserId = QString::number(userId);
    setLoggedIn(true);
    setCurrentBalance(QString::number(balance));
    setLoginMessage("");
    emit loginStatus(true, "Вход выполнен успешно");
    emit showPersonalAccount();
    closeCentralDatabase();
}

void AccountManager::showPersonalAccount() {
    emit showPersonalAccount();
}

void AccountManager::hidePersonalAccount() {
    emit hidePersonalAccount();
}

QVariantList AccountManager::getTopUpHistory() {
    QVariantList historyList;
    if (m_currentUserId.isEmpty()) return historyList;
    bool useCentral = m_isOnline && openCentralDatabase();
    QSqlDatabase db = useCentral ? m_centralDb : m_localDb;
    if (!db.isOpen()) return historyList;
    QSqlQuery query(db);
    query.prepare("SELECT amount, timestamp FROM top_ups WHERE user_id = :user_id ORDER BY timestamp DESC");
    query.bindValue(":user_id", m_currentUserId);
    if (query.exec()) {
        while (query.next()) {
            QVariantMap record;
            record["amount"] = query.value(0).toInt();
            record["timestamp"] = query.value(1).toDateTime().toString(Qt::ISODate);
            historyList.append(record);
        }
    }
    if (useCentral) closeCentralDatabase();
    return historyList;
}
