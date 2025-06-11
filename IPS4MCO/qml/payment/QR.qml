import QtQuick 2.4

QRForm {
    id: form

    Connections {
        target: backend
        function onShowQR() {
            form.state = "generating"
        }
        function onSetQR(qr_string) {
            form.state = "show"
            form.qrcode.data = qr_string
        }

    }
}
