import QtQuick 2.4
import QtQuick.Controls 2.5
import "NewStyledButton.qml"

Item {
    id: accountMenu

    // Centering the menu on the screen
    anchors.centerIn: parent
    width: 350 // Adjust width as needed
    height: 250 // Adjust height as needed
    visible: false // Initially hidden

    Rectangle {
        anchors.fill: parent
        color: "#1A1A1A" // Dark background for the menu
        radius: 15
        opacity: 0.9 // Slightly transparent
        border.color: "#FFFFFF"
        border.width: 1

        Column {
            anchors.centerIn: parent
            spacing: 20

            NewStyledButton {
                id: loginButton
                buttonText: "ВХОД"
                width: 250
                height: 70
                onClicked: {
                    accountMenu.visible = false
                    window.showLoginScreen() // Emit signal to main.qml
                    console.log("Login button clicked");
                }
            }

            NewStyledButton {
                id: registerButton
                buttonText: "РЕГИСТРАЦИЯ"
                width: 250
                height: 70
                onClicked: {
                    accountMenu.visible = false
                    window.showRegistrationScreen() // Emit signal to main.qml
                    console.log("Registration button clicked");
                }
            }
        }
    }
} 