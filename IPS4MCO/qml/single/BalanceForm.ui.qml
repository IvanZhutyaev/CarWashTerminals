import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtGraphicalEffects 1.0
import "NewStyledButton.qml"

Item {
    property alias logoImage: logo.source
    property alias titleText: title.text
    property alias textBalance: text_balance.text
    property alias textTime: text_time.text
    property string textColor: "#fff"
    property string backgroundTopColor: "#b2e0ff"
    property string backgroundBottomColor: "#80b2ff"
    property string borderColor: "#007bff"
    property int borderWidth: 2
    property int backgroundRadius: 10

    property string balanceLabelColor: "#000"
    property string balanceValueColor: "#FF0000"
    property string timeLabelColor: "#000"
    property string timeValueColor: "#FF0000"

    property bool isWaiting: true

    width: 600
    height: 300
    property alias text_balance: text_balance
    property alias text_time: text_time

    Rectangle {
        id: background
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        radius: backgroundRadius
        border.color: borderColor
        border.width: borderWidth
        gradient: Gradient {
            GradientStop { position: 0.0; color: backgroundTopColor }
            GradientStop { position: 1.0; color: backgroundBottomColor }
        }

        DropShadow {
            anchors.fill: parent
            horizontalOffset: 2
            verticalOffset: 2
            radius: 8.0
            samples: 17
            color: "#80000000"
            source: parent
        }
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        spacing: 10

        Text {
            id: label_balance
            font.pixelSize: 36
            font.family: Constants.fontFamily
            font.weight: Font.Bold
            text: "БАЛАНС"
            color: balanceLabelColor
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: text_balance
            font.pixelSize: 128
            font.family: Constants.fontFamilyStatic
            font.weight: Font.ExtraBold
            text: backend.balance + "₽"
            color: balanceValueColor
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: text_balance.bottom
        anchors.topMargin: 20
        spacing: 10

        Row {
            spacing: 5

            Rectangle {
                id: time_display_rect
                width: 150
                height: 80
                radius: 10
                border.color: "#007bff"
                border.width: 2
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#b2e0ff" }
                    GradientStop { position: 1.0; color: "#80b2ff" }
                }

                DropShadow {
                    anchors.fill: parent
                    horizontalOffset: 2
                    verticalOffset: 2
                    radius: 8.0
                    samples: 17
                    color: "#80000000"
                    source: parent
                }

                Column {
                    anchors.centerIn: parent
                    spacing: 5
                    Text {
                        id: label_time
                        font.pixelSize: 20
                        font.family: Constants.fontFamily
                        font.weight: Font.Normal
                        text: "ВРЕМЯ"
                        color: timeLabelColor
                        horizontalAlignment: Text.AlignHCenter
                    }
                    Text {
                        id: text_time
                        font.pixelSize: 50
                        font.family: Constants.fontFamilyStatic
                        font.weight: Font.ExtraBold
                        text: backend.time
                        color: timeValueColor
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }

            NewStyledButton {
                id: end_wash_btn
                buttonText: "ЗАКОНЧИТЬ\nМОЙКУ"
                width: 150
                height: 80
            }

            NewStyledButton {
                id: pay_wash_btn
                buttonText: "ОПЛАТИТЬ\nМОЙКУ"
                width: 150
                height: 80
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:2}
}
##^##*/

