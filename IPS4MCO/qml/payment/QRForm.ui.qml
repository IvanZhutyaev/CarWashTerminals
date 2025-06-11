import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtQrCode.Component 1.0

Item {
    id: page
    width: Constants.width
    height: Constants.height
    state: "generating"
    property alias qrcode: qrcode

    QRGenerating {
        id: generating
        visible: false
    }

    Item {
        id: qr
        anchors.fill: parent

        Label {
            id: label
            anchors.centerIn: parent
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold

            text: qsTr("ВАШ\nЭЛЕКТРОННЫЙ ЧЕК")
            font.pixelSize: 80
            horizontalAlignment: Text.AlignHCenter
            //color: "#0087C6"
            color: color_cfg.first

            anchors.verticalCenterOffset: -300
            anchors.horizontalCenterOffset: 0
        }

        Rectangle {
            width: parent.width * 0.75
            height: width

            anchors.centerIn: parent
            anchors.verticalCenterOffset: 270
            anchors.horizontalCenterOffset: 0

            color: "transparent"

            //border.color: "#0cb332"
            border.color: color_cfg.second
            border.width: 4

            QtQrCode {
                id: qrcode
                data: "qrcode"
                background: "transparent"
                width: parent.width * 0.95
                height: parent.height * 0.95
                anchors.centerIn: parent
            }
        }
    }

    states: [
        State {
            name: "generating"
            PropertyChanges {
                target: generating
                visible: true
            }
            PropertyChanges {
                target: qr
                visible: false
            }
        },
        State {
            name: "show"
            PropertyChanges {
                target: generating
                visible: false
            }
            PropertyChanges {
                target: qr
                visible: true
            }
        }
    ]
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/

