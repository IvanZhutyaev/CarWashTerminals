import QtQuick 2.4
import QtGraphicalEffects 1.12

Item {
    property bool checked: true

    property int borderWidth: 5
    property string borderColor: "#808080"
    property string borderColorPressed: "#010101"
    property string backgroundTopColor: "#d8d8d8"
    property string backgroundBottomColor: "#fdfdfd"
    property string backgroundTopColorPressed: "#858585"
    property string backgroundBottomColorPressed: "#ababab"
    property string stickColor: "#8a8a8a"

    width: 132
    height: width

    Rectangle {
        id: inside_circle
        width: parent.width
        height: width
        radius: width
        anchors.centerIn: parent

        border.color: checked ? borderColorPressed : borderColor
        border.width: borderWidth
        gradient: Gradient {
            GradientStop {
                position: 0.0
                color: checked ? backgroundTopColorPressed : backgroundTopColor
            }
            GradientStop {
                position: 0.8
                color: checked ? backgroundBottomColorPressed : backgroundBottomColor
            }
        }
    }

    Rectangle {
        id: pause_stick_left
        height: parent.width - parent.width / 2.5
        width: 16

        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: width

        gradient: Gradient {
            GradientStop {
                position: 0.0
                color: borderColorPressed
            }
            GradientStop {
                position: 1.0
                color: checked ? borderColorPressed : stickColor
            }
        }
    }

    Rectangle {
        id: pause_stick_right
        height: pause_stick_left.height
        width: pause_stick_left.width

        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -pause_stick_left.anchors.horizontalCenterOffset

        gradient: Gradient {
            GradientStop {
                position: 0.0
                color: borderColorPressed
            }
            GradientStop {
                position: 1.0
                color: checked ? borderColorPressed : stickColor
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:4}
}
##^##*/

