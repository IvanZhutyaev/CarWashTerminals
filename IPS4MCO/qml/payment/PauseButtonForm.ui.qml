import QtQuick 2.4
import IPS4MCO 1.0
import QtGraphicalEffects 1.0

Item {
    id: button
    width: 400
    height: 140
    state: "default"
    property bool checked: false

    Image {
        id: visualImage
        anchors.fill: parent
        source: "qrc:/images/btn_pause.png"
    }

    ColorOverlay {
        id: visualImageOverlay
        anchors.fill: visualImage
        source: visualImage
        color: color_cfg.third
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
        id: pause_stick_left
        height: 45
        width: 6

        y: button.height / 2 - height / 2
        x: inside_circle.x + inside_circle.width/2 - 12

        color: color_cfg.third
    }

    Rectangle {
        id: pause_stick_right
        height: 45
        width: 6

        y: button.height / 2 - height / 2
        x: inside_circle.x + inside_circle.width/2 + 8

        color: color_cfg.third
    }

    Text {
        id: pauseText
        font.pixelSize: 45

        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -5
        anchors.left: parent.left
        anchors.leftMargin: 140
        //color: "#fff"
        color: color_cfg.fourth

        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold

        text: "пауза"
    }

    states: [
        State {
            name: "default"
            when: !checked
            PropertyChanges {
                target: visualImage
                source: "qrc:/images/btn_pause.png"
            }
            PropertyChanges {
                target: visualImageOverlay
                color: color_cfg.third
            }
            PropertyChanges {
                target: pause_stick_left
                color: color_cfg.third
            }
            PropertyChanges {
                target: pause_stick_right
                color: color_cfg.third
            }
        },
        State {
            name: "checked"
            when: checked
            PropertyChanges {
                target: visualImage
                source: "qrc:/images/btn_pause_pressed.png"
            }
            PropertyChanges {
                target: visualImageOverlay
                color: color_cfg.second
            }
            PropertyChanges {
                target: pause_stick_left
                color: color_cfg.second
            }
            PropertyChanges {
                target: pause_stick_right
                color: color_cfg.second
            }
        }
    ]
}
