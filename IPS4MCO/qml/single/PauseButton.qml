import QtQuick 2.4

PauseButtonForm {
    id: root
    signal buttonClicked()

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        onClicked: {
            //checked = !checked
            root.buttonClicked();
        }
    }
}
