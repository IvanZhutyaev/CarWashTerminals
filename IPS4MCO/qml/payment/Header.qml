import QtQuick 2.4

HeaderForm {
    Connections {
        target: backend
        function onSetUIConfig(config) {
            header_title.text = config["Title"]
            header_logo_img.source = "file:/" + applicationDirPath + "images/" + config["UILogo"]
            header_termid.text = "Терминал №" + config["TerminalID"]
            header_phone.text = config["Phone"]
        }
    }
}
