import QtQuick 2.4

InitializationForm {
    id: form
    Connections {
        target: backend
        function onShowInitialization(state, text) {
            label.text = (text === "") ? "ИНИЦИАЛИЗАЦИЯ" : text;

            switch (state) {
                case 0:
                    form.state = "base state"
                    break;
                case 1:
                    form.state = "prefinish"
                    break;
                case 2:
                    form.state = "finish"
                    break;
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
