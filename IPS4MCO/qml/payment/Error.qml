import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0

ErrorForm {
    id: form
    property string subsystem
    Connections {
        target: backend
        function onShowError(error, text) {
            // ERRORS_SUBSYSTEM_PNT from error.h
            var ERRORS_SUBSYSTEM_PNT = 10000;
            // ERRORS_SUBSYSTEM_PLC from error.h
            var ERRORS_SUBSYSTEM_PLC = 1000;
            // ERRORS_SUBSYSTEM_UI from error.h
            var ERRORS_SUBSYSTEM_UI = 100;
            // ERRORS_SUBSYSTEM_MBS from error.h
            var ERRORS_SUBSYSTEM_MBS = 0;

            label.text = text === "" ? "СИСТЕМА\nНЕ ОБСЛУЖИВАЕТСЯ" : "Ошибка:\n" + text;

            if (error >= ERRORS_SUBSYSTEM_PNT) {
                //error = error - ERRORS_SUBSYSTEM_PNT;
                subsystem = "PNT";

            } else if (error >= ERRORS_SUBSYSTEM_PLC) {
                error = error - ERRORS_SUBSYSTEM_PLC;
                subsystem = "PLC";

            } else if (error >= ERRORS_SUBSYSTEM_UI) {
                subsystem = "UI";

            } else {
                subsystem = "MBS";
            }

            form.code.text = "Подсистема: " + subsystem + ". Код: " + error + "."
        }

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
