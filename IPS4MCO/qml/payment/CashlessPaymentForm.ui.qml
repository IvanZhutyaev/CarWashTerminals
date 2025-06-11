import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Item {
    id: content
    width: Constants.width
    height: Constants.height
    property alias cashless_info: cashless_info
    property alias cashless_btns: cashless_btns

    property int back_screen

    Rectangle {
        height: Constants.height - 50
        width: Constants.width - 75

        anchors.centerIn: parent
        color: "transparent"

        // Card payment
        Rectangle {
            height: parent.height * 0.66
            width: parent.width * 0.96
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: parent.width * 0.02

            //color: "#fdfdfd"
            //border.color: "#0087C6"
            color: color_cfg.background
            border.color: color_cfg.first
            border.width: 4
            radius: 30

            Image {
                id: img_card_icon
                height: label_card_title.height * 0.65
                width: img_card_icon.sourceSize.width
                       / (img_card_icon.sourceSize.height / label_card_title.height) * 0.65

                anchors.left: parent.left
                anchors.leftMargin: 50
                anchors.top: parent.top
                anchors.topMargin: 20

                source: "qrc:/images/cpf_bank_icon.png"
            }

            ColorOverlay {
                anchors.fill: img_card_icon
                source: img_card_icon
                color: color_cfg.third
                visible: color_cfg.isCashlessOverlay
            }

            Label {
                id: label_card_title
                font.pixelSize: 72
                anchors.left: parent.left
                anchors.leftMargin: 60 + img_card_icon.width + img_card_icon.y
                anchors.bottom: img_card_icon.bottom
                anchors.bottomMargin: -15
                //anchors.topMargin: label_cash_title.height
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold

                text: "Безналичная оплата"
                //color: "#0087C6"
                color: color_cfg.first
            }

            Rectangle {
                width: parent.width * 0.9
                height: 3
                anchors.top: label_card_title.bottom
                anchors.horizontalCenter: parent.horizontalCenter

                //color: "#0087C6"
                color: color_cfg.first
            }

            Label {
                id: label_balance
                font.pixelSize: 101
                anchors.left: parent.left
                anchors.leftMargin: 65
                anchors.bottom: text_balance.bottom
                anchors.bottomMargin: 20
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold

                text: "Аванс:"
                //color: "#0087C6"
                color: color_cfg.first
            }

            Text {
                id: text_balance
                font.pixelSize: 155
                anchors.right: parent.right
                anchors.rightMargin: 65
                anchors.top: parent.top
                anchors.topMargin: label_card_title.y + label_card_title.height + 50
                font.family: Constants.fontFamilyStatic
                font.weight: Font.ExtraBold

                text: m_balance + " ₽"
                //color: "#fe7709"
                color: color_cfg.third
            }

            CashlessPaymentButtons {
                id: cashless_btns
                width: (parent.width - 90) * 0.5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 50
                anchors.left: parent.left
                anchors.leftMargin: 30
            }

            Rectangle {
                width: 3
                height: 550
                anchors.left: parent.left
                anchors.leftMargin: 30 + cashless_btns.x + cashless_btns.width
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 50
                //color: "#0087C6"
                color: color_cfg.first
            }

            CashlessPaymentStatus {
                id: cashless_info
                width: (parent.width - 90) * 0.5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 50
                anchors.right: parent.right
                anchors.rightMargin: 30
            }
        }

        // Cash payment
        Rectangle {
            height: parent.height * 0.30
            width: parent.width * 0.96
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.width * 0.02

            //color: "#fdfdfd"
            //border.color: "#0087C6"
            color: color_cfg.background
            border.color: color_cfg.first
            border.width: 4
            radius: 30

            Image {
                id: img_cash_icon
                height: label_cash_title.height
                width: img_cash_icon.sourceSize.width
                       / (img_cash_icon.sourceSize.height / label_cash_title.height)

                anchors.left: parent.left
                anchors.leftMargin: 50
                anchors.top: parent.top
                anchors.topMargin: 20

                source: "qrc:/images/cpf_cash_icon.png"
            }

            ColorOverlay {
                anchors.fill: img_cash_icon
                source: img_cash_icon
                color: color_cfg.third
                visible: color_cfg.isCashlessOverlay
            }

            Label {
                id: label_cash_title
                font.pixelSize: 72
                anchors.left: parent.left
                anchors.leftMargin: 80 + img_cash_icon.width + img_cash_icon.y
                anchors.bottom: img_cash_icon.bottom
                anchors.bottomMargin: -15
                //anchors.topMargin: label_cash_title.height
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold

                text: "Оплата наличными"
                //color: "#0087C6"
                color: color_cfg.first
            }

            Rectangle {
                width: parent.width * 0.9
                height: 3
                anchors.top: label_cash_title.bottom
                anchors.horizontalCenter: parent.horizontalCenter

                //color: "#0087C6"
                color: color_cfg.first
            }

            Image {
                id: img_cash_arrow
                height: label_cash_text.height
                width: img_cash_arrow.sourceSize.width
                       / (img_cash_arrow.sourceSize.height / label_cash_text.height)

                anchors.left: parent.left
                anchors.leftMargin: 50
                anchors.top: parent.top
                anchors.topMargin: label_cash_title.height * 2

                source: "qrc:/images/cpf_cash_arrow.png"
            }

            ColorOverlay {
                anchors.fill: img_cash_arrow
                source: img_cash_arrow
                color: color_cfg.third
                visible: color_cfg.isCashlessOverlay
            }

            Label {
                id: label_cash_text
                font.pixelSize: 44
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.horizontalCenterOffset: 105
                anchors.top: parent.top
                anchors.topMargin: label_cash_title.height * 2
                font.family: Constants.fontFamily
                font.weight: Font.ExtraBold

                text: "Для оплаты наличными\nиспользуйте платёжные\nустройства, расположенные\nна панели пульта"
                //color: "#0087C6"
                color: color_cfg.first
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/

