import QtQuick 2.4
import QtQuick.Controls 2.5
import QtQuick.Shapes 1.12
import IPS4MCO 1.0
import "qml/single"


ApplicationWindow {
    id: window
    visible: true
    title: qsTr("IPS4MCO")
    flags: Qt.FramelessWindowHint | Qt.Window
    //visibility:  Qt.WindowFullScreen
    width: Constants.width
    height: Constants.height


    signal qmlSetButtons(buttons: int)
    signal qmlClerButtonStateQr()
    signal qmlClerButtonStateWallet()

    signal qmlSendPayment(value : int, back_screen : int)


    property bool isErrorColorCFG: false

    // Use definition fro, IPS4MCO.Constants
    function changePage (page) {
        var visible_page = [false, false, false]
        visible_page[page] = true

        p_initialization.visible = visible_page[0]
        p_error.visible = visible_page[1]
        p_session.visible = visible_page[2]
    }


    Connections {
        target: backend
        function onSetUIConfig(config) {
            window.title = config["Title"]
        }

        function onShowInitialization() {
            changePage(Constants.initialization)
        }

        function onShowError() {
            changePage(Constants.error)
        }

        function onShowWaiting() {
            p_session.isWaiting = true
            p_session.enabled = false
            p_session.resetButtons()
            changePage(Constants.session)
        }

        function onShowSession() {
            p_session.isWaiting = false
            p_session.enabled = true
            changePage(Constants.session)
        }

        function onShowQR() {
        }

        function onShowCollection() {
        }

        function onShowWallet() {
        }
    }




    Session {
        id: p_session
        anchors.fill: parent
        isWaiting: true
        enabled: false
        visible: false
    }

    Error {
        id: p_error
        visible: false
    }

    Initialization {
        id: p_initialization
        visible: false
    }

}




