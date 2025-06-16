#ifndef YOOKASSA_H
#define YOOKASSA_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUuid>

class YooKassa : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString shopId READ shopId WRITE setShopId NOTIFY shopIdChanged)
    Q_PROPERTY(QString secretKey READ secretKey WRITE setSecretKey NOTIFY secretKeyChanged)

public:
    explicit YooKassa(QObject *parent = nullptr);

    QString shopId() const;
    void setShopId(const QString &shopId);

    QString secretKey() const;
    void setSecretKey(const QString &secretKey);

    Q_INVOKABLE void createPayment(double amount, const QString &description);
    Q_INVOKABLE void checkPaymentStatus(const QString &paymentId);

signals:
    void shopIdChanged();
    void secretKeyChanged();
    void paymentCreated(const QString &paymentUrl, const QString &paymentId);
    void paymentStatusReceived(const QString &status);
    void errorOccurred(const QString &message);

private slots:
    void handlePaymentCreationResponse(QNetworkReply *reply);
    void handleStatusCheckResponse(QNetworkReply *reply);

private:
    QString m_shopId;
    QString m_secretKey;
    QNetworkAccessManager *m_networkManager;
    QString generateAuthHeader() const;
    QString generateIdempotenceKey() const;
};

#endif // YOOKASSA_H 