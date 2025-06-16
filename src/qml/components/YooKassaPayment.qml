import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root
    color: "#f5f5f5"
    property double amount: 0
    property string description: ""
    property string paymentId: ""
    property bool isProcessing: false

    signal paymentCompleted()
    signal paymentFailed(string error)
    signal backClicked()

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20

        Label {
            Layout.fillWidth: true
            text: "Оплата через ЮKassa"
            font.pixelSize: 24
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
        }

        Label {
            Layout.fillWidth: true
            text: "Сумма: " + amount.toFixed(2) + " ₽"
            font.pixelSize: 18
            horizontalAlignment: Text.AlignHCenter
        }

        BusyIndicator {
            Layout.alignment: Qt.AlignHCenter
            running: isProcessing
            visible: isProcessing
        }

        Button {
            Layout.fillWidth: true
            Layout.preferredHeight: 50
            text: "Оплатить"
            enabled: !isProcessing
            onClicked: {
                isProcessing = true
                yooKassa.createPayment(amount, description)
            }
        }

        Button {
            Layout.fillWidth: true
            Layout.preferredHeight: 50
            text: "Назад"
            enabled: !isProcessing
            onClicked: backClicked()
        }
    }

    Connections {
        target: yooKassa

        function onPaymentCreated(paymentUrl, paymentId) {
            root.paymentId = paymentId
            Qt.openUrlExternally(paymentUrl)
        }

        function onPaymentStatusReceived(status) {
            isProcessing = false
            if (status === "succeeded") {
                paymentCompleted()
            } else if (status === "canceled") {
                paymentFailed("Платеж отменен")
            } else if (status === "pending") {
                // Продолжаем проверять статус
                yooKassa.checkPaymentStatus(paymentId)
            }
        }

        function onErrorOccurred(message) {
            isProcessing = false
            paymentFailed(message)
        }
    }
} 