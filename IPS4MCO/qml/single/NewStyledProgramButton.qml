import QtQuick 2.0
import QtQuick.Controls 2.5
import "NewStyledButton.qml"

NewStyledButton {
    id: control
    property bool checked: false

    onCheckedChanged: {
        if (checked) {
            // Apply checked state visual changes if any (e.g., darker border, different color)
            // For now, it will be the same as unchecked as per the image
        } else {
            // Revert to unchecked state visual changes
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: control.checked = !control.checked // Toggle checked state
    }
} 