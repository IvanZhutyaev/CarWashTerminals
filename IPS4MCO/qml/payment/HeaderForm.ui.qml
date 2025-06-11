import QtQuick 2.4
import IPS4MCO 1.0

Item {
    height: Constants.header_height

    property alias header_title: header_title
    property alias header_logo_img: header_logo_img
    property alias header_termid: header_termid
    property alias header_phone: header_phone

    Rectangle {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height - bottom_line.height
        //color: "#000"
        color: color_cfg.header
    }

    Rectangle {
        id: bottom_line
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height * 0.08
        //color: "#00c2e8"
        color: color_cfg.first
    }

    Image {
        id: header_logo_img
        asynchronous: true
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -bottom_line.height
        anchors.left: parent.left
        anchors.leftMargin: 40
    }

    Text {
        id: header_title
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.verticalCenterOffset: -bottom_line.height
        anchors.leftMargin: header_logo_img.x + header_logo_img.width + 40
        font.bold: true
        font.pixelSize: 46
        //color: Constants.text_color
        color: color_cfg.fourth
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold
    }

    Column {
        id: column
        anchors.right: parent.right
        anchors.rightMargin: 40

        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -bottom_line.height
        Text {
            id: header_support_text
            font.bold: true
            font.pixelSize: Constants.header_height * 0.1
            anchors.right: parent.right
            anchors.rightMargin: 0
            //color: Constants.text_color
            color: color_cfg.fourth
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            text: "Техническая поддержка"
        }

        Text {
            id: header_phone
            font.bold: true
            anchors.right: parent.right
            font.pixelSize: Constants.header_height * 0.1
            anchors.rightMargin: 0
            //color: Constants.text_color
            color: color_cfg.fourth
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            text: "8 000 000 00 00"
        }

        Text {
            id: header_termid
            font.pixelSize: Constants.header_height * 0.1
            anchors.right: parent.right
            anchors.rightMargin: 0
            font.bold: true
            //color: Constants.text_color
            color: color_cfg.fourth
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            text: "Терминал №0000"
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/

