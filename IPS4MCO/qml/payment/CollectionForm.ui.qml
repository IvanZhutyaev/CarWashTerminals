import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtGraphicalEffects 1.0

Item {
    width: Constants.width
    height: Constants.height

    Image {
        id: collection_icon
        //z: 0
        //asynchronous: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 100

        source: "qrc:/images/collection_icon.png"
    }

    ColorOverlay {
        anchors.fill: collection_icon
        source: collection_icon
        color: color_cfg.collectionImg
        visible: color_cfg.isCollectionOverlay
    }

    Label {
        id: label
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 100 + collection_icon.y + collection_icon.height
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 80
        //color: "#0087C6"
        color: color_cfg.first
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold

        text: "ИНКАССАЦИЯ"
    }


    /*
    Label {
        id: label_bal
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold
        text: qsTr("сумма")
        font.pixelSize: 55
        color: "#0087C6"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 100 + label.y + label.height
    }

    Text {
        id: text_bal
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold
        text: backend.colbalance + " ₽"
        font.pixelSize: 65
        color: "#0BB232"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 30 + label_bal.y + label_bal.height
    }
*/
    Label {
        id: label_cash
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold
        text: qsTr("сумма")
        font.pixelSize: 55
        //color: "#0087C6"
        color: color_cfg.first
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 250 + label.y + label.height
        //anchors.topMargin: 100 + text_bal.y + text_bal.height
    }

    Text {
        id: text_cash
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold
        text: backend.colcash + " ₽"
        font.pixelSize: 65
        //color: "#0BB232"
        color: color_cfg.second
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 30 + label_cash.y + label_cash.height
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.20000000298023224}
}
##^##*/

