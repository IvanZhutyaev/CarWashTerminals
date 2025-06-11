import QtQuick 2.4
import QtQuick.Controls 2.5
import QtMultimedia 5.15
import IPS4MCO 1.0

Item {
    id: item1
    width: Constants.width
    height: Constants.height
    property alias video_waiting: video_waiting
    property alias image_waiting: image_waiting
    property bool envideo: false
    property bool enimage: false

    AnimatedImage {
        id: image_waiting
        playing: false
        visible: enimage
        anchors.centerIn: parent

        source: ""
    }

    Video {
        id: video_waiting
        width: parent.width - 200
        height: parent.height - 200
        visible: envideo
        anchors.centerIn: parent

        flushMode: VideoOutput.FirstFrame
        loops: MediaPlayer.Infinite

        source: ""
    }
    states: [
        State {
            name: "simage"
            PropertyChanges {
                target: image_waiting
                visible: true
            }
            PropertyChanges {
                target: video_waiting
                visible: false
            }
        },
        State {
            name: "svideo"
            PropertyChanges {
                target: image_waiting
                visible: false
            }
            PropertyChanges {
                target: video_waiting
                visible: true
            }
        }
    ]
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.33000001311302185}
}
##^##*/

