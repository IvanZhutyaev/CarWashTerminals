import QtQuick 2.4
import IPS4MCO 1.0
import QtGraphicalEffects 1.0

Item {
    id: button
    width: 400
    height: 140
    state: "default"
    property alias text: btnText.text
    property alias number: numberText.text
    property bool checked: false

    Image {
        id: visualImage
        anchors.fill: parent
        source: "qrc:/images/button.png"
    }

    ColorOverlay {
        id: visualImageOverlay
        anchors.fill: visualImage
        source: visualImage
        color: color_cfg.first
        visible: color_cfg.isButtonOverlay
    }

    Rectangle {
        id: inside_circle
        width: 105
        height: width
        radius: width

        x: button.height / 2 - width / 2
        y: x

        color: color_cfg.fourth
    }

    Rectangle {
        width: 102
        height: 102
        color: "transparent"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 19
        radius: 102

        Text {
            id: numberText
            font.pixelSize: 70
            anchors.centerIn: parent
            anchors.verticalCenterOffset: -3
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            text: "#"
            //color: "#0087C6"
            color: color_cfg.first
        }
    }

    Rectangle {
        width: button.width
        height: button.height
        color: "transparent"
        anchors.fill: parent

        Text {
            id: btnText
            width: parent.width - 178
            height: parent.height

            fontSizeMode: Text.Fit
            minimumPixelSize: 5
            font.pixelSize: 45

            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 140
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            text: "text"
            //color: "#fff"
            color: color_cfg.fourth
        }
    }

    states: [
        State {
            name: "default"
            when: !checked
            PropertyChanges {
                target: visualImage
                source: "qrc:/images/button.png"
            }
            PropertyChanges {
                target: visualImageOverlay
                color: color_cfg.first
            }
            PropertyChanges {
                target: numberText
                //color: "#0087C6"
                color: color_cfg.first
            }
        },
        State {
            name: "checked"
            when: checked
            PropertyChanges {
                target: visualImage
                source: "qrc:/images/button_pressed.png"
            }
            PropertyChanges {
                target: visualImageOverlay
                color: color_cfg.second
            }
            PropertyChanges {
                target: numberText
                //color: "#0BB232"
                color: color_cfg.second
            }
        }
    ]
}
