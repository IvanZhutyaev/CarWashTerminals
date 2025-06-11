pragma Singleton
import QtQuick 2.4

QtObject {
    property FontLoader fontLoaderStatic: FontLoader {
        id: fontLoaderStatic
        source: "qrc:/fonts/Exo2-Bold-Static.ttf"
    }

    property FontLoader fontLoader: FontLoader {
        id: fontLoader
        source: "qrc:/fonts/Exo2-Bold.ttf"
    }


    readonly property alias fontFamilyStatic: fontLoaderStatic.name
    readonly property alias fontFamily: fontLoader.name


    readonly property int header_height: 200
    readonly property int footer_height: 150
    readonly property int width: 1280
    readonly property int height: 1024
    readonly property string text_color: '#fff'


    readonly property int initialization: 0
    readonly property int error: 1
    readonly property int session: 2
    readonly property int waiting: 3
    readonly property int qr: 4
    readonly property int collection: 5
    readonly property int wallet: 6

}
