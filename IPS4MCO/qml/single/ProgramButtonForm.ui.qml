import QtQuick 2.12
import QtGraphicalEffects 1.12
import IPS4MCO 1.0

Item {
    //property alias width: btn.width
    //property alias height: btn.height
    property alias image: img.source
    property string topColor: "#007540"
    property string bottomColor: "#000000"
    property string topBorderColor: "#81c252"
    property string bottomBorderColor: "#7fbe50"
    property string textColor: "#fff"
    property int bottomBorderWidth: 8
    property int topBorderWidth: 5
    property int bordersOffset: 4
    property int textSidesOffset: 16
    property bool checked: false
    property bool isLeftAligment: true

    property alias text: prog_name.text

    id: btn
    width: 400
    height: 400

    Rectangle {
        id: background

        anchors.fill: parent
        gradient: Gradient {
            GradientStop {
                position: 0.0
                color: topColor
            }
            GradientStop {
                position: 0.6
                color: bottomColor
            }
        }
    }

    ColorOverlay {
        anchors.fill: background
        source: background
        color: topColor
        visible: checked
    }

    GradientBorderForm {
        id: bottomBorder
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        gbBottomColor: bottomBorderColor
        gbTopColor: bottomColor
        gbBorderWidth: bottomBorderWidth
        gbBottomColorPos: 1.0
        gbTopColorPos: 0.2
    }

    GradientBorderForm {
        id: topBorder
        height: parent.height - ((bottomBorderWidth + bordersOffset) * 2)
        width: parent.width - ((bottomBorderWidth + bordersOffset) * 2)
        anchors.centerIn: parent
        gbBottomColor: bottomColor
        gbTopColor: topBorderColor
        gbBorderWidth: topBorderWidth
        gbBottomColorPos: 0.8
        gbTopColorPos: 0.0
    }

    Image {
        id: img
        //source: ""
        width: 132
        height: 132
        anchors.left: isLeftAligment ? parent.left : undefined
        anchors.leftMargin: isLeftAligment ? 32 : undefined
        anchors.right: isLeftAligment ? undefined : parent.right
        anchors.rightMargin: isLeftAligment ? undefined : 32
        anchors.top: parent.top
        anchors.topMargin: 64
    }

    ColorOverlay {
        anchors.fill: img
        source: img
        color: textColor
    }

    Text {
        id: prog_name
        //text: "Ручной нано- шампунь" //"Вода | сильное давление"
        text: "Вода | сильное давление"

        width: parent.width - ((bottomBorderWidth + bordersOffset
                                + topBorderWidth) * 2) - textSidesOffset * 2
        height: 132
        color: textColor
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: (bottomBorderWidth + bordersOffset + topBorderWidth) + textSidesOffset
        verticalAlignment: Text.AlignBottom
        horizontalAlignment: isLeftAligment ? Text.AlignLeft : Text.AlignRight
        font.pointSize: 28
        minimumPointSize: 18
        fontSizeMode: Text.Fit
        font.family: Constants.fontFamily
        font.weight: Font.ExtraBold
        wrapMode: Text.WordWrap
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:2}
}
##^##*/

