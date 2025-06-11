import QtQuick 2.4
import IPS4MCO 1.0

Item {
    width: Constants.width
    height: Constants.height

    Rectangle {
        color: "#fff"
        anchors.fill: parent
    }

    Image {
        id: content_background_img
        //z: 0
        asynchronous: true
        anchors.fill: parent
        fillMode: Image.Tile

        source: "qrc:/images/background.png"
    }

    Rectangle {
        height: Constants.height - 50
        width: Constants.width - 75

        anchors.centerIn: parent
        //color: "#fdfdfd"
        //border.color: "#0087C6"
        color: color_cfg.background
        border.color: color_cfg.first
        border.width: 4
        radius: 30
    }
}
