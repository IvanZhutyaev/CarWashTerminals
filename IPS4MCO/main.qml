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
    color: "#000000" // Set background color to black

    // Top header as seen in the new design
    Row {
        id: topHeader
        width: parent.width
        height: 60 // Adjust height as needed
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        spacing: 10
        padding: 20

        Text {
            text: "VoDA | Self Service"
            font.family: Constants.fontFamily
            font.pixelSize: 30
            font.weight: Font.ExtraBold
            color: "#FFFFFF"
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle {
            width: 1 // Spacer to push time to the right
            height: 1
            Layout.fillWidth: true
        }

        Text {
            id: currentTimeText
            text: backend.time // Assuming backend.time provides the current time string (e.g., "23:00")
            font.family: Constants.fontFamily
            font.pixelSize: 30
            font.weight: Font.ExtraBold
            color: "#FFFFFF"
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    signal qmlSetButtons(buttons: int)
    signal qmlClerButtonStateQr()
    signal qmlClerButtonStateWallet()

    signal qmlSendPayment(value : int, back_screen : int)

    // New signals for Account Management screens
    signal showRegistrationScreen()
    signal showLoginScreen()

    property bool isErrorColorCFG: false

    // Use definition fro, IPS4MCO.Constants
    function changePage (page) {
        var visible_page = [false, false, false, false, false] // Expanded for 5 pages: Init, Error, Session, Registration, Login
        visible_page[page] = true

        p_initialization.visible = visible_page[Constants.initialization]
        p_error.visible = visible_page[Constants.error]
        p_session.visible = visible_page[Constants.session]
        p_registration_screen.visible = visible_page[Constants.registration]
        p_login_screen.visible = visible_page[Constants.login]
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

    // New connections for account screens
    Connections {
        target: window // Connect to signals from this window
        function onShowRegistrationScreen() {
            changePage(Constants.registration)
        }
        function onShowLoginScreen() {
            changePage(Constants.login)
        }
    }


    Session {
        id: p_session
        anchors.fill: parent // Adjusted to fill below the header
        anchors.top: topHeader.bottom // Position below the new header
        anchors.topMargin: 10 // Small margin from the header
        isWaiting: true
        enabled: false
        visible: false
    }

    Error {
        id: p_error
        visible: false
        anchors.fill: parent // Assuming error covers the whole screen
        anchors.top: topHeader.bottom
        anchors.topMargin: 10
    }

    Initialization {
        id: p_initialization
        visible: false
        anchors.fill: parent // Assuming initialization covers the whole screen
        anchors.top: topHeader.bottom
        anchors.topMargin: 10
    }

    RegistrationScreen {
        id: p_registration_screen
        anchors.fill: parent
        // No top margin needed as it will overlay the header
        visible: false
    }

    LoginScreen {
        id: p_login_screen
        anchors.fill: parent
        // No top margin needed as it will overlay the header
        visible: false
    }

}




