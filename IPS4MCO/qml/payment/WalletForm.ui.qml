import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtGraphicalEffects 1.0

Item {
    id: page
    width: Constants.width
    height: Constants.height

    Image {
        id: wallet_icon
        //z: 0
        //asynchronous: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 100

        source: "qrc:/images/wallet.png"
    }

    ColorOverlay {
        anchors.fill: wallet_icon
        source: wallet_icon
        color: color_cfg.first
        visible: color_cfg.isWalletOverlay
    }

    Label {
        id: wallet_label
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 50 + wallet_icon.height + wallet_icon.y
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold

        text: qsTr("ЭЛЕКТРОННЫЙ\nКОШЕЛЕК")
        font.pixelSize: 80
        //color: "#0087C6"
        color: color_cfg.first
        horizontalAlignment: Text.AlignHCenter
    }

    Item {
        id: row_deposit
        width: 750
        height: img_deposit.height > text_deposit.height ? img_deposit.height : text_deposit.height

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: wallet_label.y + wallet_label.height + 45

        Image {
            id: img_deposit
            y: 0
            //anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/images/dep.png"
        }

        ColorOverlay {
            anchors.fill: img_deposit
            source: img_deposit
            color: color_cfg.second
            visible: color_cfg.isWalletOverlay
        }

        Text {
            id: text_deposit
            y: 0
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            text: "Зачислено\nв депозит: " + backend.deposit + " ₽"
            font.pixelSize: 55
            //color: "#0087C6"
            color: color_cfg.first
            anchors.left: parent.left
            anchors.leftMargin: 250
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Item {
        id: row_discount_fix
        width: 750
        height: img_discount_fix.height
                > text_discount_fix.height ? img_discount_fix.height : text_discount_fix.height

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: row_deposit.y + row_deposit.height + 45

        Image {
            id: img_discount_fix
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/images/fix.png"
        }

        ColorOverlay {
            anchors.fill: img_discount_fix
            source: img_discount_fix
            color: color_cfg.second
            visible: color_cfg.isWalletOverlay
        }

        Text {
            id: text_discount_fix
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            text: "Скидка: " + backend.discountfix + "%"
            font.pixelSize: 55
            //color: "#0087C6"
            color: color_cfg.first
            anchors.left: parent.left
            anchors.leftMargin: 250
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Item {
        id: row_discount_acc
        width: 750
        height: img_discount_acc.height
                > text_discount_acc.height ? img_discount_acc.height : text_discount_acc.height

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: row_discount_fix.y + row_discount_fix.height + 45

        Image {
            id: img_discount_acc
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/images/acc.png"
        }

        ColorOverlay {
            anchors.fill: img_discount_acc
            source: img_discount_acc
            color: color_cfg.second
            visible: color_cfg.isWalletOverlay
        }

        Text {
            id: text_discount_acc
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            text: "Новая\nнакопительная\nскидка: " + backend.discountacc + "%"
            font.pixelSize: 55
            //color: "#0087C6"
            color: color_cfg.first
            anchors.left: parent.left
            anchors.leftMargin: 250
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Item {
        id: row_expire_discount
        width: 750
        height: img_expire_discount.height > text_expire_discount.height ? img_expire_discount.height : text_expire_discount.height

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: row_discount_acc.y + row_discount_acc.height + 45

        Rectangle {
            width: parent.width
            height: 3
            anchors.top: parent.top
            color: color_cfg.isWalletOverlay ? color_cfg.second : "#0BB232"
        }

        Image {
            id: img_expire_discount
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 45

            source: "qrc:/images/exp.png"
        }

        ColorOverlay {
            anchors.fill: img_expire_discount
            source: img_expire_discount
            color: color_cfg.second
            visible: color_cfg.isWalletOverlay
        }

        Text {
            id: text_expire_discount
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            text: "Срок действия\nнакопительной\nскидки: до " + backend.date
            font.pixelSize: 55
            //color: "#0087C6"
            color: color_cfg.first
            anchors.left: parent.left
            anchors.leftMargin: 250
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 45
        }
    }

    states: [
        State {
            name: "dep"
            PropertyChanges {
                target: row_deposit
                visible: true
                anchors.topMargin: wallet_label.y + wallet_label.height + 350
            }
            PropertyChanges {
                target: text_deposit
                text: "Зачислено\nв депозит: " + backend.deposit + " ₽"
            }
            PropertyChanges {
                target: row_discount_fix
                visible: false
            }
            PropertyChanges {
                target: row_discount_acc
                visible: false
            }
            PropertyChanges {
                target: row_expire_discount
                visible: false
            }
        },
        State {
            name: "dep fix"
            PropertyChanges {
                target: row_deposit
                visible: true
                anchors.topMargin: wallet_label.y + wallet_label.height + 240 //175
            }
            PropertyChanges {
                target: text_deposit
                text: "Депозит: " + backend.deposit + " ₽"
            }
            PropertyChanges {
                target: row_discount_fix
                visible: true
                anchors.topMargin: row_deposit.y + row_deposit.height + 220 //350
            }
            PropertyChanges {
                target: text_discount_fix
                text: "Скидка: " + backend.discountfix + "%"
            }
            PropertyChanges {
                target: row_discount_acc
                visible: false
            }
            PropertyChanges {
                target: row_expire_discount
                visible: false
            }
        },
        State {
            name: "dep acc exp"
            PropertyChanges {
                target: row_deposit
                visible: true
                anchors.topMargin: wallet_label.y + wallet_label.height + 96
            }
            PropertyChanges {
                target: text_deposit
                text: "Зачислено\nв депозит: " + backend.deposit + " ₽"
            }
            PropertyChanges {
                target: row_discount_fix
                visible: false
            }
            PropertyChanges {
                target: row_discount_acc
                visible: true
                anchors.topMargin: row_deposit.y + row_deposit.height + 100
            }
            PropertyChanges {
                target: text_discount_acc
                text: "Новая\nнакопительная\nскидка: " + backend.discountacc + "%"
            }
            PropertyChanges {
                target: row_expire_discount
                visible: true
                anchors.topMargin: row_discount_acc.y + row_discount_acc.height + 100
            }
            PropertyChanges {
                target: text_expire_discount
                text: "Срок действия\nнакопительной\nскидки: до " + backend.date
            }
        },
        State {
            name: "dep fix acc exp"
            PropertyChanges {
                target: row_deposit
                visible: true
                anchors.topMargin: wallet_label.y + wallet_label.height + 90
            }
            PropertyChanges {
                target: text_deposit
                text: "Депозит: " + backend.deposit + " ₽"
            }
            PropertyChanges {
                target: row_discount_fix
                visible: true
                anchors.topMargin: row_deposit.y + row_deposit.height + 60
            }
            PropertyChanges {
                target: text_discount_fix
                text: "Скидка: " + backend.discountfix + "%"
            }
            PropertyChanges {
                target: row_discount_acc
                visible: true
                anchors.topMargin: row_discount_fix.y + row_discount_fix.height + 60
            }
            PropertyChanges {
                target: text_discount_acc
                text: "Накопительная\nскидка: " + backend.discountacc + "%"
            }
            PropertyChanges {
                target: row_expire_discount
                visible: true
                anchors.topMargin: row_discount_acc.y + row_discount_acc.height + 60
            }
            PropertyChanges {
                target: text_expire_discount
                text: "Срок действия\nнакопительной\nскидки: до " + backend.date
            }
        }
    ]
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/

