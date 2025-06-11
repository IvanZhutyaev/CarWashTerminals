import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0

Item {
    id: content
    width: Constants.width
    height: Constants.height
    property alias label: label
    Rectangle {
        color: "#000"
        anchors.fill: parent
    }

    BusyIndicator {
        id: busyIndicator
        width: 450
        height: 450
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -label.height
        anchors.horizontalCenterOffset: 0
        palette.dark: "#fff"
    }

    Label {
        id: label
        anchors.centerIn: parent
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold
        text: qsTr("ИНИЦИАЛИЗАЦИЯ")
        font.pixelSize: 80
        font.bold: false
        color: "#fff"

        anchors.verticalCenterOffset: label.height + 200
        anchors.horizontalCenterOffset: 0
    }
}
