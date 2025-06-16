import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtGraphicalEffects 1.0
import "NewStyledButton.qml"

Item {
    id: root
    width: Constants.width
    height: Constants.height

    property int selectedAmount: 0
    property string selectedMethod: ""

    Rectangle {
        anchors.fill: parent
        color: color_cfg.background

        Column {
            anchors.centerIn: parent
            spacing: 30

            Label {
                text: "ВЫБЕРИТЕ СПОСОБ ОПЛАТЫ"
                font.pixelSize: 48
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold
                color: color_cfg.first
                anchors.horizontalCenter: parent.horizontalCenter
            }

            NewStyledButton {
                buttonText: "КАРТА"
                width: 400
                height: 100
                onClicked: {
                    selectedMethod = "card"
                    amountSelection.visible = true
                    paymentMethods.visible = false
                }
            }

            NewStyledButton {
                buttonText: "СПБ"
                width: 400
                height: 100
                onClicked: {
                    selectedMethod = "spb"
                    amountSelection.visible = true
                    paymentMethods.visible = false
                }
            }

            NewStyledButton {
                buttonText: "НАЛИЧНЫЕ"
                width: 400
                height: 100
                onClicked: {
                    selectedMethod = "cash"
                    amountSelection.visible = true
                    paymentMethods.visible = false
                }
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

    // Экран выбора суммы
    Item {
        id: amountSelection
        anchors.fill: parent
        visible: false

        Rectangle {
            anchors.fill: parent
            color: color_cfg.background

            Column {
                anchors.centerIn: parent
                spacing: 30

                Label {
                    text: "ВЫБЕРИТЕ СУММУ"
                    font.pixelSize: 48
                    font.family: Constants.fontFamily
                    font.weight: Font.ExtraBold
                    color: color_cfg.first
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Grid {
                    columns: 2
                    spacing: 20
                    anchors.horizontalCenter: parent.horizontalCenter

                    Repeater {
                        model: [50, 100, 200, 300]

                        NewStyledButton {
                            buttonText: modelData + " ₽"
                            width: 200
                            height: 100
                            onClicked: {
                                selectedAmount = modelData
                                processPayment()
                            }
                        }
                    }
                }

                NewStyledButton {
                    buttonText: "НАЗАД"
                    width: 400
                    height: 100
                    onClicked: {
                        amountSelection.visible = false
                        paymentMethods.visible = true
                    }
                }
            }
        }
    }

    function processPayment() {
        switch(selectedMethod) {
            case "card":
                window.pushScreen("CashlessPayment")
                break
            case "spb":
                window.pushScreen("SPBPayment")
                break
            case "cash":
                window.pushScreen("CashPayment")
                break
        }
    }
} 