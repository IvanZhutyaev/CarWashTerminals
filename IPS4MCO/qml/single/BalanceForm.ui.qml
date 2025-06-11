import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtGraphicalEffects 1.0

Item {
    property alias logoImage: logo.source
    property alias titleText: title.text
    property alias textBalance: text_balance.text
    property alias textTime: text_time.text
    property string textColor: "#fff"
    property string backgroundTopColor: "#f0f0f0"
    property string backgroundBottomColor: "#636363"
    property string headerColor: "#000"
    property int headerHeight: 55
    property int backgroundRadius: 50
    property int bordersWidth: 8
    property string borderTopColor: "#4c4c4c"
    property string borderBottomColor: "#808080"
    property string colorBalanceLabel: "#606060"
    property string colorBalance: "#000"
    property string timeDivTopColor: "#acacac"
    property string timeDivBottomColor: "#727272"

    property bool isWaiting: true

    property alias pause_btn: pause_btn

    width: 600
    height: 395
    property alias text_balance: text_balance
    property alias text_time: text_time

    Rectangle {
        id: background
        width: parent.width - bordersWidth * 2
        height: parent.height
        anchors.centerIn: parent
        radius: backgroundRadius
        gradient: Gradient {
            GradientStop {
                position: 0.2
                color: backgroundTopColor
            }
            GradientStop {
                position: 1.0
                color: backgroundBottomColor
            }
        }
    }

    GradientBorderForm {
        id: outsideBorder
        anchors.fill: parent
        gbRadius: backgroundRadius
        gbBorderWidth: bordersWidth
        gbTopColor: headerColor
        gbBottomColor: "#00ffffff"
    }

    GradientBorderForm {
        id: insideBorder
        anchors.fill: background
        gbRadius: backgroundRadius - 3
        gbBorderWidth: bordersWidth
        gbTopColor: borderTopColor
        gbBottomColor: borderBottomColor
    }

    Rectangle {
        id: header
        width: parent.width
        height: headerHeight
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top

        color: headerColor
        Row {
            height: parent.height
            //width: parent.width
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10

            Image {
                id: logo
                height: parent.height
                fillMode: Image.PreserveAspectFit
                source: ""
                //width: 100
            }

            Rectangle {
                id: sep
                height: parent.height - 16
                width: 4
                anchors.verticalCenter: parent.verticalCenter
                color: textColor
            }

            Text {
                id: title
                height: parent.height
                anchors.verticalCenter: parent.verticalCenter

                verticalAlignment: Text.AlignBottom
                font.pointSize: 28
                minimumPointSize: 18
                fontSizeMode: Text.Fit
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold
                wrapMode: Text.WordWrap

                color: textColor
                text: "Self Service"
            }
        }
    }

    Label {
        id: label_balance
        font.pixelSize: 36
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: headerHeight + 25
        font.family: Constants.fontFamily
        font.weight: Font.Bold

        text: "Баланс"
        color: colorBalanceLabel
    }

    Text {
        id: text_balance
        font.pixelSize: 128
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: headerHeight + label_balance.height + 10
        font.family: Constants.fontFamilyStatic
        font.weight: Font.ExtraBold

        //text: backend.balance + " ₽"
        text: "999₽"
        color: colorBalance
    }

    Rectangle {
        id: time_div
        width: parent.width - 132
        height: 75
        radius: height

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50

        gradient: Gradient {
            GradientStop {
                position: 0.2
                color: timeDivTopColor
            }
            GradientStop {
                position: 1.0
                color: timeDivBottomColor
            }
        }

        GradientBorderForm {
            anchors.fill: parent
            gbRadius: parent.radius
            gbTopColor: timeDivBottomColor
            gbBottomColor: timeDivTopColor
            gbBorderWidth: 4
        }

        Item {
            id: pause_label
            anchors.fill: parent
            visible: pause_btn.checked
            Label {
                height: parent.height
                anchors.centerIn: parent

                font.pixelSize: 44
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold
                verticalAlignment: Text.AlignVCenter

                text: isWaiting ? "" : "Пауза"
                color: textColor
            }
        }

        Item {
            id: timer
            anchors.fill: parent
            visible: !pause_btn.checked
            Label {
                id: label_time
                height: parent.height
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: parent.height / 2

                font.pixelSize: 44
                font.family: Constants.fontFamily
                font.weight: Font.Normal
                verticalAlignment: Text.AlignVCenter

                text: "Время"
                color: textColor
            }

            Text {
                id: text_time
                height: parent.height
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: (parent.height * 2) - 8

                font.family: Constants.fontFamilyStatic
                font.weight: Font.ExtraBold
                font.pixelSize: 50
                verticalAlignment: Text.AlignVCenter

                text: "00:00"
                color: textColor
            }
        }
    }

    PauseButton {
        id: pause_btn
        anchors.verticalCenter: time_div.verticalCenter
        anchors.right: time_div.right
        z: 1000
    }

    DropShadow {
        anchors.fill: pause_btn
        horizontalOffset: 3
        verticalOffset: 3
        radius: 8.0
        samples: 17
        color: "#80000000"
        source: pause_btn
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:2}
}
##^##*/

