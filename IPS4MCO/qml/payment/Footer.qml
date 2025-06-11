import QtQuick 2.4

FooterForm {
    id: root
    signal buttonOkClicked()
    signal buttonCashlessStartClicked()
    signal buttonCashlessReplenishClicked()
    signal buttonCashlessBackClicked()

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        onClicked: {
            switch (root.state) {
                case root.button_ok:
                    root.buttonOkClicked();
                    break;
                case root.button_cashless_start:
                    root.buttonCashlessStartClicked();
                    break;
                case root.button_cashless_replenish:
                    root.buttonCashlessReplenishClicked();
                    break;
                case root.button_cashless_back:
                    root.buttonCashlessBackClicked();
                    break;
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
