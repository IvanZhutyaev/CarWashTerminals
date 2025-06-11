import QtQuick 2.4
import QtGraphicalEffects 1.12
import IPS4MCO 1.0

Item {
    id: container
    width: Constants.width
    height: Constants.height
    property alias voiceover: voiceover
    property alias balance: balance
    property alias btn8: btn8
    property alias btn7: btn7
    property alias btn6: btn6
    property alias btn5: btn5
    property alias btn4: btn4
    property alias btn3: btn3
    property alias btn2: btn2
    property alias btn1: btn1
    property bool isWaiting: false
    Voiceover {
        id: voiceover
    }
    Column {
        Row {

            ProgramButton {
                id: btn1
                width: container.width / 3
                height: container.height / 3

                image: ""
                topColor: "#007540"
                topBorderColor: "#81c252"
                bottomBorderColor: "#7fbe50"
            }

            Rectangle {
                width: btn1.width
                height: btn1.height
            }

            ProgramButton {
                id: btn2
                width: btn1.width
                height: btn1.height

                isLeftAligment: false
                image: ""
                topColor: "#85691d"
                topBorderColor: "#f6e023"
                bottomBorderColor: "#f3dd22"
            }
        }

        Row {
            ProgramButton {
                id: btn3
                width: btn1.width
                height: btn1.height

                image: ""
                topColor: "#1aa6c3"
                topBorderColor: "#41abc4"
                bottomBorderColor: "#47bcd7"
            }

            ProgramButton {
                id: btn4
                width: btn1.width
                height: btn1.height

                topColor: "#0c5ad3"
                topBorderColor: "#00386a"
                bottomBorderColor: "#006ccb"
            }

            ProgramButton {
                id: btn5
                width: btn1.width
                height: btn1.height

                topColor: "#2e297b"
                topBorderColor: "#5c4fbb"
                bottomBorderColor: "#5a4db8"
            }
        }

        Row {
            ProgramButton {
                id: btn6
                width: btn1.width
                height: btn1.height

                topColor: "#6a2891"
                topBorderColor: "#804e9f"
                bottomBorderColor: "#804e9f"
            }

            ProgramButton {
                id: btn7
                width: btn1.width
                height: btn1.height

                topColor: "#b31866"
                topBorderColor: "#a24397"
                bottomBorderColor: "#a24397"
            }

            ProgramButton {
                id: btn8
                width: btn1.width
                height: btn1.height

                topColor: "#e71921"
                topBorderColor: "#ec3531"
                bottomBorderColor: "#ec3531"
            }
        }
    }

    Balance {
        id: balance
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        //logoImage: ""
        textBalance: isWaiting ? "0" : backend.balance
        textTime: backend.time
        isWaiting: container.isWaiting
    }

    DropShadow {
        anchors.fill: balance
        radius: 24
        samples: 32
        color: "#80000000"
        source: balance
        spread: 0.5
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/

