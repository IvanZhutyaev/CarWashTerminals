import QtQuick 2.4
import QtGraphicalEffects 1.12

Item {
    property int gbBorderWidth: 8
    property alias gbTopColor: gradientTopColor.color
    property alias gbBottomColor: gradientBottomColor.color
    property alias gbTopColorPos: gradientTopColor.position
    property alias gbBottomColorPos: gradientBottomColor.position
    property int gbRadius: 0

    width: 400
    height: 400

    Rectangle {
        id: bottomBorderFill
        anchors.fill: parent
        radius: gbRadius
        gradient: Gradient {
            GradientStop {
                id: gradientTopColor
                position: 0.2
                color: "#000"
            }
            GradientStop {
                id: gradientBottomColor
                position: 1.0
                color: "#fff"
            }
        }
        visible: false
    }

    Rectangle {
        id: bottomBorderMask
        border.width: gbBorderWidth
        anchors.fill: parent
        radius: gbRadius
        color: 'transparent'
        visible: false
    }

    OpacityMask {
        id: bottomBorder_opM
        anchors.fill: parent
        source: bottomBorderFill
        maskSource: bottomBorderMask
    }
}
