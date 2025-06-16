import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtQuick.Layouts 1.15
import "NewStyledButton.qml"

Item {
    id: root
    width: Constants.width
    height: Constants.height
    property int selectedAmount: 0
    property string paymentId: ""
    property bool isProcessing: false

    Rectangle {
        anchors.fill: parent
        color: color_cfg.background

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 20

            Label {
                Layout.fillWidth: true
                text: "ОПЛАТА ЧЕРЕЗ СПБ"
                font.pixelSize: 48
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold
                color: color_cfg.first
                horizontalAlignment: Text.AlignHCenter
            }

            Label {
                Layout.fillWidth: true
                text: "Сумма: " + selectedAmount + " ₽"
                font.pixelSize: 36
                font.family: Constants.fontFamily
                color: color_cfg.first
                horizontalAlignment: Text.AlignHCenter
            }

            Label {
                Layout.fillWidth: true
                text: "ОТСКАНИРУЙТЕ QR-КОД\nВ ПРИЛОЖЕНИИ СПБ"
                font.pixelSize: 36
                font.family: Constants.fontFamily
                font.weight: Font.Bold
                color: color_cfg.second
                horizontalAlignment: Text.AlignHCenter
            }

            BusyIndicator {
                Layout.alignment: Qt.AlignHCenter
                running: isProcessing
                visible: isProcessing
            }

            Image {
                id: qrCode
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredWidth: 300
                Layout.preferredHeight: 300
                visible: !isProcessing && paymentId !== ""
                source: "image://qr/" + paymentId // Предполагается, что у вас есть провайдер для генерации QR-кодов
            }

            NewStyledButton {
                Layout.alignment: Qt.AlignHCenter
                buttonText: "НАЗАД"
                width: 400
                height: 100
                onClicked: {
                    window.popScreen()
                }
            }
        }
    }

    Component.onCompleted: {
        isProcessing = true
        yooKassa.createPayment(selectedAmount, "Пополнение баланса через СПБ")
    }

    Connections {
        target: yooKassa

        function onPaymentCreated(paymentUrl, paymentId) {
            root.paymentId = paymentId
            isProcessing = false
        }

        function onPaymentStatusReceived(status) {
            if (status === "succeeded") {
                backend.updateBalance(selectedAmount)
                window.popScreen()
            }
        }

        function onErrorOccurred(error) {
            isProcessing = false
            errorDialog.text = error
            errorDialog.open()
        }
    }

    Dialog {
        id: errorDialog
        title: "Ошибка"
        property alias text: errorText.text
        standardButtons: Dialog.Ok

        Label {
            id: errorText
            anchors.fill: parent
            wrapMode: Text.WordWrap
        }
    }
} 