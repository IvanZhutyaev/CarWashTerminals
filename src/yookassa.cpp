#include "yookassa.h"
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QByteArray>

YooKassa::YooKassa(QObject *parent)
    : QObject(parent)
    , m_networkManager(new QNetworkAccessManager(this))
{
}

QString YooKassa::shopId() const
{
    return m_shopId;
}

void YooKassa::setShopId(const QString &shopId)
{
    if (m_shopId != shopId) {
        m_shopId = shopId;
        emit shopIdChanged();
    }
}

QString YooKassa::secretKey() const
{
    return m_secretKey;
}

void YooKassa::setSecretKey(const QString &secretKey)
{
    if (m_secretKey != secretKey) {
        m_secretKey = secretKey;
        emit secretKeyChanged();
    }
}

void YooKassa::createPayment(double amount, const QString &description)
{
    QNetworkRequest request(QUrl("https://api.yookassa.ru/v3/payments"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", generateAuthHeader().toUtf8());
    request.setRawHeader("Idempotence-Key", generateIdempotenceKey().toUtf8());

    QJsonObject paymentData;
    QJsonObject amountObj;
    amountObj["value"] = QString::number(amount, 'f', 2);
    amountObj["currency"] = "RUB";
    paymentData["amount"] = amountObj;

    QJsonObject confirmation;
    confirmation["type"] = "redirect";
    confirmation["return_url"] = "carwash://payment_result";
    paymentData["confirmation"] = confirmation;

    paymentData["description"] = description;

    QJsonDocument doc(paymentData);
    QByteArray data = doc.toJson();

    QNetworkReply *reply = m_networkManager->post(request, data);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        handlePaymentCreationResponse(reply);
    });
}

void YooKassa::checkPaymentStatus(const QString &paymentId)
{
    QNetworkRequest request(QUrl(QString("https://api.yookassa.ru/v3/payments/%1").arg(paymentId)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", generateAuthHeader().toUtf8());

    QNetworkReply *reply = m_networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        handleStatusCheckResponse(reply);
    });
}

void YooKassa::handlePaymentCreationResponse(QNetworkReply *reply)
{
    reply->deleteLater();

    if (reply->error() != QNetworkReply::NoError) {
        emit errorOccurred(reply->errorString());
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject response = doc.object();

    if (response.contains("confirmation") && response["confirmation"].isObject()) {
        QJsonObject confirmation = response["confirmation"].toObject();
        QString paymentUrl = confirmation["confirmation_url"].toString();
        QString paymentId = response["id"].toString();
        emit paymentCreated(paymentUrl, paymentId);
    } else {
        emit errorOccurred("Invalid response format");
    }
}

void YooKassa::handleStatusCheckResponse(QNetworkReply *reply)
{
    reply->deleteLater();

    if (reply->error() != QNetworkReply::NoError) {
        emit errorOccurred(reply->errorString());
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject response = doc.object();

    if (response.contains("status")) {
        QString status = response["status"].toString();
        emit paymentStatusReceived(status);
    } else {
        emit errorOccurred("Invalid response format");
    }
}

QString YooKassa::generateAuthHeader() const
{
    QString auth = m_shopId + ":" + m_secretKey;
    return "Basic " + auth.toUtf8().toBase64();
}

QString YooKassa::generateIdempotenceKey() const
{
    return QUuid::createUuid().toString(QUuid::WithoutBraces);
} 