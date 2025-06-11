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

    Rectangle {
        anchors.fill: parent
        color: "#000"
    }

    Image {
        id: error_icon
        //z: 0
        //asynchronous: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 150

        source: "qrc:/images/error_icon.png"
    }

    Label {
        id: label
        anchors.top: parent.top
        anchors.topMargin: error_icon.width + error_icon.y + 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 0
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 80
        color: "#fff"
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold

        text: qsTr("СИСТЕМА\nНЕ ОБСЛУЖИВАЕТСЯ")
    }

    Text {
        id: code
        anchors.top: parent.top
        anchors.topMargin: error_icon.width + error_icon.y + 400
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 0
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 48
        color: "#fff"
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold

        text: qsTr("Код: ")
    }
}
