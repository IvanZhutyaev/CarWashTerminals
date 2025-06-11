import QtQuick 2.4

WalletForm {
    id: form

    Connections {
        target: backend
        function onShowWallet(state) {
            switch (state) {
                case 0x4:
                    form.state = "dep"
                    break;
                case 0x5:
                    form.state = "dep fix"
                    break;
                case 0xE:
                    form.state = "dep acc exp"
                    break;
                case 0xF:
                    form.state = "dep fix acc exp"
                    break;
            }
        }
    }
}
