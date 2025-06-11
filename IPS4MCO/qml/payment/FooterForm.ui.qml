import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtGraphicalEffects 1.0

Item {
    id: item1
    height: Constants.footer_height
    readonly property string empty: "empty"
    readonly property string button_ok: "btn_ok"
    readonly property string button_cashless_start: "btn_pmnt_start"
    readonly property string button_cashless_replenish: "btn_pmnt_replenish"
    readonly property string button_cashless_back: "btn_pmnt_back"
    property alias state: item1.state


    Rectangle {

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height

        //color: "#00c2e8"
        color: color_cfg.first

        Text {
            id: button_ok
            visible: false
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 0
            font.pixelSize: parent.height * 0.7
            //color: "#fff"
            color: color_cfg.fourth
            font.family: Constants.fontFamily
            font.weight: Font.ExtraBold
            text: "ОК"
        }

        Image {
            id: img
            visible: false
            source: "qrc:/images/footer_back_btn.png"
            height: button_ok.height - 20
            width: img.sourceSize.width / (img.sourceSize.height / img.height)
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }

        ColorOverlay {
            id: imgOverlay
            anchors.fill: img
            source: img
            color: color_cfg.fourth
            visible: color_cfg.isFooterOverlay
        }
    }
    states: [
        State {
            name: "empty"
            PropertyChanges {
                target: button_ok
                visible: false
            }

            PropertyChanges {
                target: img
                visible: false
            }
            PropertyChanges {
                target: imgOverlay
                visible: false
            }
        },
        State {
            name: "btn_ok"
            PropertyChanges {
                target: button_ok
                visible: true
                text: "ОК"
                anchors.horizontalCenterOffset: 0
            }
            PropertyChanges {
                target: img
                visible: false
            }
            PropertyChanges {
                target: imgOverlay
                visible: false
            }
        },
        State {
            name: "btn_pmnt_start"
            PropertyChanges {
                target: button_ok
                visible: true
                text: "НАЧАТЬ МОЙКУ"
                anchors.horizontalCenterOffset: -img.width / 2 - 30
            }
            PropertyChanges {
                target: img
                visible: true
                source: "qrc:/images/footer_start_btn.png"
                anchors.horizontalCenterOffset: button_ok.width / 2 + 30
            }
            PropertyChanges {
                target: imgOverlay
                visible: true
            }
        },
        State {
            name: "btn_pmnt_replenish"
            PropertyChanges {
                target: button_ok
                visible: true
                text: "БЕЗНАЛИЧНАЯ\nОПЛАТА"
                anchors.horizontalCenterOffset: -img.width / 2 - 30
                font.pixelSize: (parent.height * 0.7) / 2
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            PropertyChanges {
                target: img
                visible: true
                source: "qrc:/images/footer_replenish_btn.png"
                anchors.horizontalCenterOffset: button_ok.width / 2 + 30
                height: button_ok.height - 30
            }
            PropertyChanges {
                target: imgOverlay
                visible: true
            }
        },
        State {
            name: "btn_pmnt_back"
            PropertyChanges {
                target: button_ok
                visible: true
                text: "НАЗАД"
                anchors.horizontalCenterOffset: -img.width / 2 - 30
            }
            PropertyChanges {
                target: img
                visible: true
                source: "qrc:/images/footer_back_btn.png"
                anchors.horizontalCenterOffset: button_ok.width / 2 + 30
            }
            PropertyChanges {
                target: imgOverlay
                visible: true
            }
        }
    ]
}
