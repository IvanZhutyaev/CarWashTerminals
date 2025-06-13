import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.12
import IPS4MCO 1.0

Button {
    id: control
    property string buttonText: ""
    property string topColor: "#b2e0ff" // Light blue from the image
    property string bottomColor: "#80b2ff" // Darker blue from the image
    property string borderColor: "#007bff" // Blue border color
    property int borderWidth: 2
    property int buttonRadius: 10
    property string textColor: "#000000" // Black text color
    property int textPointSize: 24 // Default font size, can be adjusted

    background: Rectangle {
        implicitWidth: 150
        implicitHeight: 80
        radius: control.buttonRadius
        border.color: control.borderColor
        border.width: control.borderWidth

        gradient: Gradient {
            GradientStop { position: 0.0; color: control.topColor }
            GradientStop { position: 1.0; color: control.bottomColor }
        }

        DropShadow {
            anchors.fill: parent
            horizontalOffset: 2
            verticalOffset: 2
            radius: 8.0
            samples: 17
            color: "#80000000" // Dark shadow
            source: parent
        }
    }

    contentItem: Text {
        text: control.buttonText
        font.family: Constants.fontFamily // Use existing font
        font.pointSize: control.textPointSize
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: control.textColor
        wrapMode: Text.WordWrap
    }
} 