import QtQuick 2.4
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import IPS4MCO 1.0

Item {
    //width: Constants.width
    //height: Constants.height
    anchors.fill: parent

    AnimatedImage {
        //Image {
        id: loading_img
        //z: 0
        //asynchronous: true
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -300

        //source: "qrc:/images/init.gif"
        source: color_cfg.InitProcessingImg
        //source: "qrc:/images/qr_loading.png"
    }

    Label {
        id: label
        anchors.centerIn: parent
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold

        text: qsTr("ФОРМИРОВАНИЕ\nЧЕКА")
        font.pixelSize: 80
        //color: "#0087C6"
        color: color_cfg.first
        horizontalAlignment: Text.AlignHCenter

        anchors.verticalCenterOffset: 300
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.5;height:480;width:640}
}
##^##*/

