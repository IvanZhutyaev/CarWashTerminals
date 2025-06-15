import QtQuick 2.4
import QtGraphicalEffects 1.12
import IPS4MCO 1.0
import "NewStyledButton.qml"
import "NewStyledProgramButton.qml"
import "AccountMenu.qml"

Item {
    id: container
    width: Constants.width
    height: Constants.height
    property alias voiceover: voiceover
    property alias balance: balance_component
    property alias btn8: btn_wax_polish
    property alias btn7: btn_foam
    property alias btn6: btn_active_chemistry
    property alias btn5: btn_weak_pressure
    property alias btn4: btn_medium_pressure
    property alias btn3: btn_high_pressure
    property alias btn2: btn_vacuum_cleaner
    property alias btn1: btn_turbosushka
    property alias pause_btn_new: btn_pause
    property bool isWaiting: false
    Voiceover {
        id: voiceover
    }
    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: balance_component.bottom
        anchors.topMargin: 20
        spacing: 10

        Text {
            id: water_pressure_title
            text: "ЧИСТАЯ ВОДА | ВЫСОКОЕ ДАВЛЕНИЕ"
            font.family: Constants.fontFamily
            font.pixelSize: 20
            font.weight: Font.ExtraBold
            color: "#FFFFFF"
            horizontalAlignment: Text.AlignHCenter
            width: parent.width
        }

        Row {
            spacing: 5
            NewStyledButton {
                id: btn_weak_pressure
                buttonText: "СЛАБОЕ\n140 БАР"
                width: 150
                height: 80
            }
            NewStyledButton {
                id: btn_medium_pressure
                buttonText: "СРЕДНЕЕ\n170 БАР"
                width: 150
                height: 80
            }
            NewStyledButton {
                id: btn_high_pressure
                buttonText: "ВЫСОКОЕ\n210 БАР"
                width: 150
                height: 80
            }
        }

        Text {
            id: main_wash_title
            text: "ОСНОВНАЯ МОЙКА"
            font.family: Constants.fontFamily
            font.pixelSize: 20
            font.weight: Font.ExtraBold
            color: "#FFFFFF"
            horizontalAlignment: Text.AlignHCenter
            width: parent.width
        }

        Row {
            spacing: 5
            NewStyledProgramButton {
                id: btn_active_chemistry
                buttonText: "АКТИВНАЯ\nХИМИЯ"
                width: 150
                height: 80
            }
            NewStyledProgramButton {
                id: btn_foam
                buttonText: "ПЕНА"
                width: 150
                height: 80
            }
        }
        Row {
            spacing: 5
            NewStyledProgramButton {
                id: btn_wax_polish
                buttonText: "ПОЛИРУЮЩИЙ\nВОСК"
                width: 150
                height: 80
            }
            NewStyledProgramButton {
                id: btn_turbosushka
                buttonText: "ТУРБО\nСУШКА"
                width: 150
                height: 80
            }
            NewStyledProgramButton {
                id: btn_vacuum_cleaner
                buttonText: "ПЫЛЕСОС"
                width: 150
                height: 80
            }
        }

        Row {
            spacing: 5
            NewStyledProgramButton {
                id: btn_pause
                buttonText: "ПАУЗА"
                width: 150
                height: 80
            }
            NewStyledButton {
                id: btn_register
                buttonText: "РЕГИСТРАЦИЯ\nЛИЧНОГО КАБИНЕТА"
                width: 150
                height: 80
                onClicked: {
                    accountMenu.visible = true
                }
            }
            NewStyledButton {
                id: btn_price
                buttonText: "ПРАЙС"
                width: 150
                height: 80
                onClicked: {
                    // No functional changes
                }
            }
        }
    }

    Balance {
        id: balance_component
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        textBalance: isWaiting ? "0" : backend.balance
        textTime: backend.time
        isWaiting: container.isWaiting
    }

    DropShadow {
        anchors.fill: balance_component
        radius: 24
        samples: 32
        color: "#80000000"
        source: balance_component
        spread: 0.5
    }

    AccountMenu {
        id: accountMenu
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/

