import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtGraphicalEffects 1.0
import "NewStyledButton.qml"

Item {
    id: root
    width: Constants.width
    height: Constants.height

    Rectangle {
        anchors.fill: parent
        color: color_cfg.background

        Column {
            anchors.centerIn: parent
            spacing: 30

            Label {
                text: "ПРИЛОЖИТЕ КАРТУ\nИЛИ ОТСКАНИРУЙТЕ QR-КОД"
                font.pixelSize: 48
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold
                color: color_cfg.first
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Image {
                id: qrCode
                source: "qrc:/images/qr_code.png" // Нужно будет добавить реальный QR-код
                width: 300
                height: 300
                anchors.horizontalCenter: parent.horizontalCenter
            }

            NewStyledButton {
                buttonText: "НАЗАД"
                width: 400
                height: 100
                onClicked: {
                    window.popScreen()
                }
            }
        }
    }
} 