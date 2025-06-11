import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtGraphicalEffects 1.0

Item {
    id: content
    width: 500
    height: 550
    property alias btn_increase_image_overlay: btn_increase_image_overlay
    property alias btn_decrease_image_overlay: btn_decrease_image_overlay
    property alias btn_increase_image: btn_increase_image
    property alias btn_decrease_image: btn_decrease_image
    property alias btn_step_10_step: btn_step_10_step
    property alias btn_step_10_price: btn_step_10_price
    property alias btn_payment_text: btn_payment_text
    property alias btn_step_50_price: btn_step_50_price
    property alias btn_step_50_step: btn_step_50_step
    property alias btn_step_50: btn_step_50
    property alias btn_payment: btn_payment
    property alias btn_step_10: btn_step_10
    property alias btn_decrease: btn_decrease
    property alias btn_increase: btn_increase

    Rectangle {
        id: btn_increase
        width: 200
        height: 150
        radius: 150

        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left

        border.width: 4
        //border.color: "#007bb3"
        border.color: color_cfg.cashlessPaymentBtns3
        color: color_cfg.cashlessPaymentBtns1

        Image {
            id: btn_increase_image
            anchors.centerIn: parent
            width: btn_increase_image.sourceSize.width * 0.25
            height: btn_increase_image.sourceSize.height * 0.25
            source: "qrc:/images/cpf_up_down_btn_icon.png"
        }

        ColorOverlay {
            id: btn_increase_image_overlay
            anchors.fill: btn_increase_image
            source: btn_increase_image
            color: color_cfg.cashlessPaymentBtns3
            visible: color_cfg.isCashlessOverlay
        }
    }

    Rectangle {
        id: btn_decrease
        width: 200
        height: 150
        radius: 150

        anchors.top: btn_increase.top
        anchors.topMargin: btn_increase.y + btn_increase.height + 50
        anchors.left: parent.left

        border.width: 4
        //border.color: "#007bb3"
        //color: "#fff"
        border.color: color_cfg.cashlessPaymentBtns3
        color: color_cfg.cashlessPaymentBtns1
        Image {
            id: btn_decrease_image
            anchors.centerIn: parent
            width: btn_decrease_image.sourceSize.width * 0.25
            height: btn_decrease_image.sourceSize.height * 0.25
            rotation: 180
            source: "qrc:/images/cpf_up_down_btn_icon.png"
        }

        ColorOverlay {
            id: btn_decrease_image_overlay
            rotation: 180
            anchors.fill: btn_decrease_image
            source: btn_decrease_image
            color: color_cfg.cashlessPaymentBtns3
            visible: color_cfg.isCashlessOverlay
        }
    }

    Rectangle {
        id: btn_step_10
        width: 200
        height: 150
        radius: 150

        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right

        border.width: 4
        //border.color: "#fe7709"
        border.color: color_cfg.cashlessPaymentBtns5

        Label {
            id: btn_step_10_step
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 0
            font.pixelSize: 56
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            //color: "#fe7709"
            color: color_cfg.cashlessPaymentBtns5
            text: "шаг"
        }

        Label {
            id: btn_step_10_price
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 13
            font.pixelSize: 70
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            //color: "#fe7709"
            color: color_cfg.cashlessPaymentBtns5
            text: "10₽"
        }
    }

    Rectangle {
        id: btn_step_50
        width: 200
        height: 150
        radius: 150

        anchors.top: btn_step_10.top
        anchors.topMargin: btn_step_10.y + btn_step_10.height + 50
        anchors.right: parent.right

        border.width: 4
        //border.color: "#fe7709"
        border.color: color_cfg.cashlessPaymentBtns5

        Label {
            id: btn_step_50_step
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 0
            font.pixelSize: 56
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            //color: "#fe7709"
            color: color_cfg.cashlessPaymentBtns5
            text: "шаг"
        }

        Label {
            id: btn_step_50_price
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 13
            font.pixelSize: 70
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            //color: "#fe7709"
            color: color_cfg.cashlessPaymentBtns5
            text: "50₽"
        }
    }

    Rectangle {
        id: btn_payment
        width: parent.width
        height: 150
        radius: 150

        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        border.width: 4
        //border.color: "#fe7709"
        //color: "#fff"

        //border.color: "#007cb5"
        //color: "#0088c6"
        border.color: color_cfg.cashlessPaymentBtns3
        color: color_cfg.cashlessPaymentBtns2

        Label {
            id: btn_payment_text
            anchors.centerIn: parent
            anchors.verticalCenterOffset: -10
            font.pixelSize: 72
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            //color: "#fe7709"

            //color: "#fff"
            color: color_cfg.cashlessPaymentBtns1
            text: "оплатить"
        }
    }
}
