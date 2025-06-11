import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtGraphicalEffects 1.0

Item {
    id: content
    width: Constants.width
    height: Constants.height
    property alias label: label
    property alias content: content
    property alias code: code
    property alias header_termid: header_termid
    property alias header_phone: header_phone
    Image {
        id: error_icon
        //z: 0
        //asynchronous: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 100

        source: "qrc:/images/error_icon.png"
    }

    ColorOverlay {
        anchors.fill: error_icon
        source: error_icon
        color: color_cfg.error
        visible: color_cfg.isErrorOverlay
    }

    Label {
        id: label
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -label.height
        anchors.horizontalCenterOffset: 0
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 80
        //color: "#DB030C"
        color: color_cfg.error
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold

        text: qsTr("СИСТЕМА\nНЕ ОБСЛУЖИВАЕТСЯ")
    }

    Text {
        id: code
        anchors.centerIn: parent
        anchors.verticalCenterOffset: label.height
        anchors.horizontalCenterOffset: 0
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 48
        //color: "#838384"
        color: color_cfg.fifth
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold

        text: qsTr("Код: ")
    }

    Text {
        id: header_phone
        font.pixelSize: 36
        //color: "#838384"
        color: color_cfg.fifth
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 180 + header_termid.height
        horizontalAlignment: Text.AlignHCenter
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold

        text: "Техническая поддержка 8 800 123 45 67"
    }

    Text {
        id: header_termid
        font.pixelSize: 36
        //color: "#838384"
        color: color_cfg.fifth
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 180
        horizontalAlignment: Text.AlignHCenter
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold

        text: "Терминал №0000"
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/

