import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0

ErrorStaticForm {
    id: form
    Connections {
        target: backend
        function onSetUIConfig(config) {
            header_termid.text = "Терминал №" + config["TerminalID"]
            header_phone.text = "Техническая поддержка " + config["Phone"] + ","
        }
    }
}


/*##^##
Designer {
    D{i:0;formeditorZoom:0.25}
}
##^##*/
