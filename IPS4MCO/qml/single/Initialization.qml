import QtQuick 2.4

InitializationForm {
    id: form
    Connections {
        target: backend
        function onShowInitialization(state, text) {
            label.text = (text === "") ? "ИНИЦИАЛИЗАЦИЯ" : text;
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
