import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0

Item {
    id: content
    width: Constants.width
    height: Constants.height
    property alias label: label

    AnimatedImage {
        id: busyIndicator
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -label.height - 150
        anchors.horizontalCenterOffset: 0

        //source: "qrc:/images/init.gif"
        source: color_cfg.InitProcessingImg
    }

    Label {
        id: label
        anchors.centerIn: parent
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold
        text: qsTr("ИНИЦИАЛИЗАЦИЯ")
        font.pixelSize: 80
        font.bold: false
        //color: "#0087C6"
        color: color_cfg.first

        anchors.verticalCenterOffset: label.height + 200
        anchors.horizontalCenterOffset: 0
    }
    states: [
        State {
            name: "prefinish"
            PropertyChanges {
                target: busyIndicator
                //source: "qrc:/images/init_prefinish.gif"
                source: color_cfg.InitPreFinishImg
            }
        },
        State {
            name: "finish"
            PropertyChanges {
                target: busyIndicator
                //source: "qrc:/images/init_finish.gif"
                source: color_cfg.InitFinishImg
            }
        }
    ]
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/

