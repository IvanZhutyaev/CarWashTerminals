import QtQuick 2.4

CashlessPaymentStatusForm {
    id: form
    signal showPaymentInfo();


    onShowPaymentInfo: {
        form.state = "info"
    }

    Connections {
        target: backend
        function onShowPaymentLoading(state) {
            switch (state) {
                case 0:
                    form.state = "processing"
                    break;
                case 1:
                    form.state = "presuccess"
                    break;
                case 2:
                    form.state = "success"
                    break;
                case 3:
                    form.state = "cancel"
                    break;
            }
        }

        function onShowPaymentError() {
            form.state = "error"
        }

    }
}
