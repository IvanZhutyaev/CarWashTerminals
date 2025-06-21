#include "yookassa.h"
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QByteArray>

YooKassa::YooKassa(QObject* parent) : QObject(parent) {}
YooKassa::~YooKassa() {}
void YooKassa::setSecretKey(const QString&) {}
void YooKassa::setShopId(const QString&) {}

void YooKassa::createPayment(double amount, const QString &description)
{
    QNetworkRequest request(QUrl("https://api.yookassa.ru/v3/payments"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", generateAuthHeader());
    request.setRawHeader("Idempotence-Key", generateIdempotenceKey().toUtf8());

    QJsonObject payment;
    payment["amount"] = QJsonObject{
        {"value", QString::number(amount, 'f', 2)},
        {"currency", "RUB"}
    };
    payment["description"] = description;
    payment["confirmation"] = QJsonObject{
        {"type", "qr"},
        {"return_url", "carwash://payment_result"}
    };
    payment["capture"] = true;

    QJsonDocument doc(payment);
    QNetworkReply *reply = m_networkManager->post(request, doc.toJson());
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        handlePaymentCreationResponse(reply);
    });
}

void YooKassa::checkPaymentStatus(const QString &paymentId)
{
    QNetworkRequest request(QUrl(QString("https://api.yookassa.ru/v3/payments/%1").arg(paymentId)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", generateAuthHeader());

    QNetworkReply *reply = m_networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        handleStatusCheckResponse(reply);
    });
}

QString YooKassa::getPaymentUrl(const QString &paymentId) const
{
    return m_paymentUrls.value(paymentId);
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

    if (response.contains("id") && response.contains("confirmation")) {
        QString paymentId = response["id"].toString();
        QString confirmationUrl = response["confirmation"].toObject()["confirmation_url"].toString();
        m_paymentUrls[paymentId] = confirmationUrl;
        emit paymentCreated(confirmationUrl, paymentId);
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
        emit paymentStatusReceived(response["status"].toString());
    } else {
        emit errorOccurred("Invalid response format");
    }
}

QByteArray YooKassa::generateAuthHeader() const
{
    QString auth = m_shopId + ":" + m_secretKey;
    return "Basic " + auth.toUtf8().toBase64();
}

QString YooKassa::generateIdempotenceKey() const
{
    return QUuid::createUuid().toString(QUuid::WithoutBraces);
}
