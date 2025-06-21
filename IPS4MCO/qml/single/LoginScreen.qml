import QtQuick 2.4
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import "NewStyledButton.qml"
import IPS4MCO 1.0 // To access backend properties like balance

Item {
    id: loginScreen
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
                text: "ВХОД В ЛИЧНЫЙ КАБИНЕТ"
                font.family: Constants.fontFamily
                font.pixelSize: 30
                font.weight: Font.ExtraBold
                color: "#FFFFFF"
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
            }

            TextField {
                id: loginPhoneNumberInput
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
                id: loginPasswordInput
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
                id: loginMessage
                text: accountManager.loginMessage // Bind to C++ property
                font.pixelSize: 18
                color: "red"
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
                wrapMode: Text.WordWrap
                visible: accountManager.loginMessage !== "" // Visible only if message is not empty
            }

            NewStyledButton {
                id: loginConfirmButton
                buttonText: "ВОЙТИ"
                width: 250
                height: 70
                Layout.alignment: Qt.AlignHCenter
                onClicked: {
                    accountManager.loginUser(loginPhoneNumberInput.text, loginPasswordInput.text)
                    // Message is handled by accountManager.loginMessage property
                    console.log("Login confirm clicked");
                }
            }

            // --- Personal Account View (visible after successful login) ---
            ColumnLayout {
                id: personalAccountView
                visible: accountManager.isLoggedIn // Bind visibility to login status
                spacing: 10
                Layout.fillWidth: true

                Text {
                    text: "ТЕКУЩИЙ БАЛАНС: " + accountManager.currentBalance + "₽" // Bind to C++ property
                    font.family: Constants.fontFamily
                    font.pixelSize: 25
                    font.weight: Font.ExtraBold
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    Layout.fillWidth: true
                }

                // История пополнений
                Text {
                    text: "ИСТОРИЯ ПОПОЛНЕНИЙ:"
                    font.pixelSize: 16
                    color: "#AAAAAA"
                    horizontalAlignment: Text.AlignHCenter
                    Layout.fillWidth: true
                    wrapMode: Text.WordWrap
                }
                ListView {
                    id: topUpHistoryView
                    model: accountManager.getTopUpHistory()
                    delegate: RowLayout {
                        spacing: 10
                        Text {
                            text: "Сумма: " + model.amount + "₽"
                            color: "#FFFFFF"
                            font.pixelSize: 16
                        }
                        Text {
                            text: "Время: " + model.timestamp
                            color: "#CCCCCC"
                            font.pixelSize: 14
                        }
                    }
                    Layout.fillWidth: true
                    Layout.preferredHeight: 120
                    visible: count > 0
                }
                Text {
                    text: topUpHistoryView.count === 0 ? "Нет пополнений" : ""
                    color: "#888888"
                    font.pixelSize: 14
                    Layout.fillWidth: true
                    visible: topUpHistoryView.count === 0
                }
            }

            NewStyledButton {
                id: logoutButton
                buttonText: "ВЫЙТИ"
                width: 250
                height: 70
                Layout.alignment: Qt.AlignHCenter
                visible: personalAccountView.visible // Visible only if logged in
                onClicked: {
                    accountManager.logoutUser()
                    console.log("Logout button clicked");
                }
            }

            NewStyledButton {
                id: loginBackButton
                buttonText: "НАЗАД"
                width: 250
                height: 70
                Layout.alignment: Qt.AlignHCenter
                onClicked: {
                    loginScreen.visible = false
                    personalAccountView.visible = false
                    window.changePage(Constants.session) // Return to main session screen
                    accountManager.setLoginMessage(""); // Clear message on exit
                    console.log("Back button clicked from login");
                }
            }
        }
    }

    Connections {
        target: accountManager
        function onShowPersonalAccount() {
            // Handled by property binding for personalAccountView.visible
        }
        function onHidePersonalAccount() {
            // Handled by property binding for personalAccountView.visible
            loginPhoneNumberInput.text = ""; // Clear fields on logout/hide
            loginPasswordInput.text = "";
        }
        function onLoginStatus(success, message) {
            if (success) {
                // UI updates (like showing personalAccountView) are handled by property binding
            } else {
                // Message is already bound, no explicit update needed here
            }
        }
    }
} 