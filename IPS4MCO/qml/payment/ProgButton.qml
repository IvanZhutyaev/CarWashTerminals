import QtQuick 2.4

ProgButtonForm {
    id: root
    signal buttonClicked()

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        onClicked: {
            checked = !checked
            root.buttonClicked();
        }
    }
}







/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
