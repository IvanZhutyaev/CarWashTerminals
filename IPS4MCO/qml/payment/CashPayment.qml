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
                text: "ВНЕСИТЕ НАЛИЧНЫЕ"
                font.pixelSize: 48
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold
                color: color_cfg.first
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Label {
                text: "ОЖИДАНИЕ ВНЕСЕНИЯ НАЛИЧНЫХ..."
                font.pixelSize: 36
                font.family: Constants.fontFamily
                font.weight: Font.Bold
                color: color_cfg.second
                horizontalAlignment: Text.AlignHCenter
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