import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0
import QtGraphicalEffects 1.0

Item {
    id: content
    width: 400
    height: 550

    AnimatedImage {
        id: img
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        height: 150
        width: img.sourceSize.width / (img.sourceSize.height / img.height)
        source: "qrc:/images/cpf_info_icon.png"
    }


    ColorOverlay {
        id: imgOverlay
        anchors.fill: img
        source: img
        color: color_cfg.third
        visible: color_cfg.isCashlessOverlay
    }

    Text {
        id: text_top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: text_bot.height

        font.pixelSize: 42
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        text: "Выберите\nтребуемую сумму\nаванса, нажмите"
        //color: "#0088c6"
        color: color_cfg.first
    }

    Text {
        id: text_bot
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom

        font.pixelSize: 42
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        text: "кнопку «Оплата»\nи следуйте\nинструкциям на\nбанковском\nтерминале"
        //color: "#0088c6"
        color: color_cfg.first
    }

    states: [
        State {
            name: "info"
            PropertyChanges {
                target: img
                source: "qrc:/images/cpf_info_icon.png"
                height: 150
                playing: false
            }
            PropertyChanges {
                target: imgOverlay
                color: color_cfg.third
                visible: true
            }
            PropertyChanges {
                target: text_top
                anchors.bottom: parent.bottom
                anchors.bottomMargin: text_bot.height
                //color: "#0088c6"
                color: color_cfg.first
                text: "Выберите\nтребуемую сумму\nаванса, нажмите"
            }

            PropertyChanges {
                target: text_bot
                //color: "#0088c6"
                color: color_cfg.first
                text: "кнопку «Оплата»\nи следуйте\nинструкциям на\nбанковском\nтерминале"
            }
        },
        State {
            name: "processing"
            PropertyChanges {
                target: img
                //source: "qrc:/images/init.gif"
                source: color_cfg.InitProcessingImg
                height: 250
                playing: true
            }
            PropertyChanges {
                target: imgOverlay
                visible: false
            }
            PropertyChanges {
                target: text_top
                anchors.bottom: parent.bottom
                anchors.bottomMargin: text_bot.height
                //color: "#0088c6"
                color: color_cfg.first
                text: "Операция\nвыполняется......"
            }

            PropertyChanges {
                target: text_bot
                //color: "#fe7709"
                color: color_cfg.third
                text: "Cледуйте\nинструкциям на\nбанковском\nтерминале "
            }
        },
        State {
            name: "error"
            PropertyChanges {
                target: img
                source: "qrc:/images/cpf_error.png"
                height: 230
                playing: false
            }
            PropertyChanges {
                target: imgOverlay
                color: color_cfg.error
                visible: true
            }
            PropertyChanges {
                target: text_top
                anchors.bottom: parent.bottom
                anchors.bottomMargin: text_bot.height
                //color: "#fe0000"
                color: color_cfg.error
                text: "Ошибка!\nОплата не\nвыполнена."
            }

            PropertyChanges {
                target: text_bot
                //color: "#fe7709"
                color: color_cfg.third
                text: "Попробуйте еще\nраз или отмените\nоперацию"
            }
        },
        State {
            name: "success"
            PropertyChanges {
                target: img
                //source: "qrc:/images/init_finish.gif"
                source: color_cfg.InitFinishImg
                height: 250
                playing: false
            }
            PropertyChanges {
                target: imgOverlay
                visible: false
            }
            PropertyChanges {
                target: text_top
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 153
                //color: "#0088c6"
                color: color_cfg.first
                text: "Операция\nвыполнена\nуспешно"
            }

            PropertyChanges {
                target: text_bot
                text: ""
            }
        },
        State {
            name: "presuccess"
            PropertyChanges {
                target: img
                //source: "qrc:/images/init_prefinish.gif"
                source: color_cfg.InitPreFinishImg
                height: 250
                playing: false
            }
            PropertyChanges {
                target: imgOverlay
                visible: false
            }
            PropertyChanges {
                target: text_top
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 204
                text: "Операция\nвыполняется......"
            }

            PropertyChanges {
                target: text_bot
                text: ""
            }
        },
        State {
            name: "cancel"
            PropertyChanges {
                target: img
                //source: "qrc:/images/init_finish.gif"
                source: color_cfg.InitFinishImg
                height: 250
                playing: false
            }
            PropertyChanges {
                target: imgOverlay
                visible: false
            }
            PropertyChanges {
                target: text_top
                //color: "#0088c6"
                color: color_cfg.first
                text: "Операция\nотменена"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 204
            }

            PropertyChanges {
                target: text_bot
                text: ""
            }
        }
    ]
}
