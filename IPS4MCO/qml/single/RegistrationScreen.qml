import QtQuick 2.4
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import "NewStyledButton.qml"

Item {
    id: registrationScreen
    anchors.fill: parent
    visible: false // Initially hidden

    Rectangle {
        anchors.fill: parent
        color: "#000000" // Black background, consistent with main UI
        opacity: 0.9

        ColumnLayout {
            anchors.centerIn: parent
            spacing: 20
            width: 400

            Text {
                text: "РЕГИСТРАЦИЯ"
                font.family: Constants.fontFamily
                font.pixelSize: 30
                font.weight: Font.ExtraBold
                color: "#FFFFFF"
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
            }

            TextField {
                id: phoneNumberInput
                placeholderText: "НОМЕР ТЕЛЕФОНА"
                font.pixelSize: 20
                color: "#FFFFFF"
                background: Rectangle {
                    implicitWidth: 300
                    implicitHeight: 50
                    color: "#333333"
                    radius: 10
                    border.color: "#555555"
                    border.width: 1
                }
                horizontalAlignment: TextInput.AlignHCenter
                Layout.fillWidth: true
            }

            TextField {
                id: passwordInput
                placeholderText: "ПАРОЛЬ (6 ЦИФР)"
                font.pixelSize: 20
                color: "#FFFFFF"
                echoMode: TextInput.Password
                inputMask: "999999"
                background: Rectangle {
                    implicitWidth: 300
                    implicitHeight: 50
                    color: "#333333"
                    radius: 10
                    border.color: "#555555"
                    border.width: 1
                }
                horizontalAlignment: TextInput.AlignHCenter
                Layout.fillWidth: true
            }

            Text {
                id: registrationMessage
                text: accountManager.registrationMessage // Bind to C++ property
                font.pixelSize: 18
                color: "red"
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
                wrapMode: Text.WordWrap
                visible: accountManager.registrationMessage !== "" // Visible only if message is not empty
            }

            NewStyledButton {
                id: registerConfirmButton
                buttonText: "ЗАРЕГИСТРИРОВАТЬСЯ"
                width: 250
                height: 70
                Layout.alignment: Qt.AlignHCenter
                onClicked: {
                    accountManager.registerUser(phoneNumberInput.text, passwordInput.text)
                    // Message is handled by accountManager.registrationMessage property
                    console.log("Register confirm clicked");
                }
            }

            NewStyledButton {
                id: backButton
                buttonText: "НАЗАД"
                width: 250
                height: 70
                Layout.alignment: Qt.AlignHCenter
                onClicked: {
                    registrationScreen.visible = false
                    window.changePage(Constants.session) // Return to main session screen
                    accountManager.setRegistrationMessage(""); // Clear message on exit
                    console.log("Back button clicked from registration");
                }
            }
        }
    }

    Connections {
        target: accountManager
        function onRegistrationStatus(success, message) {
            if (success) {
                // Optionally, hide registration screen and go to login/session
                registrationScreen.visible = false
                window.changePage(Constants.session)
                accountManager.setRegistrationMessage(""); // Clear message after successful registration
            }
            // Message will be displayed via property binding
        }
    }
} 