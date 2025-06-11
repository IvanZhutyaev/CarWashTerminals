import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtGraphicalEffects 1.0

Item {
    id: page
    width: Constants.width
    height: Constants.height
    property alias pause_info_text: pause_info_text
    property alias pause_info: pause_info
    property alias buttons: buttons
    property alias text_time: text_time
    property alias text_balance: text_balance
    state: "pause_free"
    property alias button_prog1: button_prog1
    property alias button_prog2: button_prog2
    property alias button_prog3: button_prog3
    property alias button_prog4: button_prog4
    property alias button_prog5: button_prog5
    property alias button_prog6: button_prog6
    property alias button_prog7: button_prog7
    property alias button_pause: button_pause
    property int pause_cost: 0
    Item {
        id: special
        width: parent.width
        height: parent.height * 0.4
        anchors.top: parent.top
        anchors.topMargin: 0
        visible: false

        Image {
            id: special_icon
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 100

            source: "qrc:/images/service_icon.png"
        }

        ColorOverlay {
            id: special_icon_overlay
            anchors.fill: special_icon
            source: special_icon
            color: color_cfg.second
            visible: color_cfg.isSessionOverlay
        }

        Label {
            id: label_special
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: special_icon.y + special_icon.height + 100
            font.pixelSize: parent.width * 0.1
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            text: qsTr("Def Text")
        }
    }

    Item {
        id: normal
        width: parent.width
        height: parent.height * 0.4
        anchors.top: parent.top
        anchors.topMargin: 0

        Item {
            id: balance_div
            width: 850
            height: 160
            anchors.top: parent.top
            anchors.topMargin: 100
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                id: label_balance
                font.pixelSize: 72
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.bottom: balance_div.bottom
                anchors.bottomMargin: 15
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold

                text: "Баланс:"
                //color: "#0087C6"
                color: color_cfg.first
            }

            Text {
                id: text_balance
                font.pixelSize: 155
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.bottom: balance_div.bottom
                anchors.bottomMargin: 0
                font.family: Constants.fontFamilyStatic
                font.weight: Font.ExtraBold

                text: backend.balance + " ₽"
                //color: "#0BB232"
                color: color_cfg.second
            }
        }

        Rectangle {
            id: sep_line
            height: 3
            width: 850
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: balance_div.y + balance_div.height + 50
            //color: "#0BB232"
            color: color_cfg.second
        }

        Item {
            id: time_div
            width: 850
            height: 160
            anchors.top: parent.top
            anchors.topMargin: sep_line.y + sep_line.height + 80
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                id: label_time
                lineHeight: 1
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 15

                font.pixelSize: 72
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold

                text: "Осталось\nвремени:"
                //color: "#0087C6"
                color: color_cfg.first
            }

            Text {
                id: text_time
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                font.family: Constants.fontFamilyStatic
                font.weight: Font.ExtraBold

                font.pixelSize: 155
                text: backend.time
                //color: "#0BB232"
                color: color_cfg.second
            }
        }
    }

    Rectangle {
        id: buttons
        width: 880
        height: 800
        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.4
        anchors.horizontalCenter: parent.horizontalCenter
        color: "transparent"

        ProgButton {
            id: button_prog1
            text: "Program 1"
            number: "1"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: 0
        }

        ProgButton {
            id: button_prog2
            text: qsTr("Program 2")
            number: "2"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 0
        }

        ProgButton {
            id: button_prog3
            text: "Program 3"
            number: "3"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: 150
        }

        ProgButton {
            id: button_prog4
            text: "Program 4"
            number: "4"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 150
        }

        ProgButton {
            id: button_prog5
            text: "Program 5"
            number: "5"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: 300
        }

        ProgButton {
            id: button_prog6
            text: "Program 6"
            number: "6"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 300
        }

        ProgButton {
            id: button_prog7
            text: "Program 7"
            number: "7"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: 450
        }

        PauseButton {
            id: button_pause
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 450
        }
    }

    Rectangle {
        id: pause_info
        visible: false

        width: buttons.width
        height: 50
        radius: 50
        //border.color: "#F4720C"
        border.color: color_cfg.third
        color: color_cfg.background
        border.width: 4

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 45
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: pause_info_text

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            //color: "#F4720C"
            color: color_cfg.third
            font.pixelSize: 32
            text: "Идет бесплатное время программы \"Пауза\""
        }
    }

    states: [
        State {
            name: "service"
            PropertyChanges {
                target: normal
                visible: false
            }
            PropertyChanges {
                target: special
                visible: true
            }
            PropertyChanges {
                target: label_special
                text: "Сервисный режим"
                //color: "#F4720C"
                color: color_cfg.third
            }
            PropertyChanges {
                target: special_icon
                source: "qrc:/images/service_icon.png"
            }
            PropertyChanges {
                target: special_icon_overlay
                color: color_cfg.third
            }
            PropertyChanges {
                target: time_div
                visible: true
            }
        },
        State {
            name: "unlimit"
            PropertyChanges {
                target: normal
                visible: false
            }
            PropertyChanges {
                target: special
                visible: true
            }
            PropertyChanges {
                target: label_special
                text: "Безлимитый режим"
                //color: "#0BB232"
                color: color_cfg.second
            }
            PropertyChanges {
                target: special_icon
                source: "qrc:/images/unlim_icon.png"
            }
            PropertyChanges {
                target: special_icon_overlay
                color: color_cfg.second
            }
            PropertyChanges {
                target: time_div
                visible: true
            }
        },
        State {
            name: "washing"
            PropertyChanges {
                target: normal
                visible: true
            }
            PropertyChanges {
                target: special
                visible: false
            }
            PropertyChanges {
                target: label_time
                text: "Осталось\nвремени:"
                font.pixelSize: 72
            }
            PropertyChanges {
                target: text_time
                text: backend.time
                font.pixelSize: 160
                //color: "#0BB232"
                color: color_cfg.second
            }
            PropertyChanges {
                target: time_div
                visible: true
            }
        },
        State {
            name: "pause_free"
            PropertyChanges {
                target: normal
                visible: true
            }

            PropertyChanges {
                target: special
                visible: false
            }
            PropertyChanges {
                target: label_time
                text: "Бесплатная\n\"пауза\":"
                font.pixelSize: 60
            }
            PropertyChanges {
                target: text_time
                text: backend.pause_time
                font.pixelSize: 160
                //color: "#0BB232"
                color: color_cfg.second
            }
            PropertyChanges {
                target: pause_info
                visible: true
                //border.color: "#F4720C"
                border.color: color_cfg.third
            }
            PropertyChanges {
                target: pause_info_text
                text: "Идет бесплатное время программы \"Пауза\""
                //color: "#F4720C"
                color: color_cfg.third
            }
            PropertyChanges {
                target: time_div
                visible: !backend.ispause_free
            }
        },
        State {
            name: "pause"
            PropertyChanges {
                target: normal
                visible: true
            }

            PropertyChanges {
                target: special
                visible: false
            }
            PropertyChanges {
                target: label_time
                text: "Цена\n\"паузы\":"
                font.pixelSize: 72
            }
            PropertyChanges {
                target: text_time
                text: pause_cost + " ₽\\мин"
                font.pixelSize: 120
                //color: "#DB030C"
                color: color_cfg.error
            }
            PropertyChanges {
                target: pause_info
                visible: true
                //border.color: "#DB030C"
                border.color: color_cfg.error
            }
            PropertyChanges {
                target: pause_info_text
                text: "Дейситвует тариф для программы \"Пауза\""
                //color: "#DB030C"
                color: color_cfg.error
            }
            PropertyChanges {
                target: time_div
                visible: !backend.ispause_free
            }
        }
    ]
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.25}
}
##^##*/

