import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtQuick.Layouts 1.15

Item {
    id: root
    width: Constants.width
    height: Constants.height
    property int selectedAmount: 0

    Rectangle {
        anchors.fill: parent
        color: color_cfg.background

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 20

            Label {
                Layout.fillWidth: true
                text: "ОПЛАТА КАРТОЙ"
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

            YooKassaPayment {
                Layout.fillWidth: true
                Layout.fillHeight: true
                amount: selectedAmount
                description: "Пополнение баланса"

                onPaymentCompleted: {
                    // Обновляем баланс пользователя
                    backend.updateBalance(selectedAmount)
                    window.popScreen()
                }

                onPaymentFailed: {
                    // Показываем ошибку
                    errorDialog.text = error
                    errorDialog.open()
                }

                onBackClicked: {
                    window.popScreen()
                }
            }
        }
    }

    Dialog {
        id: errorDialog
        title: "Ошибка"
        property alias text: errorText.text
        modal: true
        anchors.centerIn: parent
        standardButtons: Dialog.Ok

        Label {
            id: errorText
            anchors.fill: parent
            wrapMode: Text.WordWrap
        }
    }
}
