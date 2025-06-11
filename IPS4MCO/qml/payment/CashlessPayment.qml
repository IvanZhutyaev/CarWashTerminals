import QtQuick 2.4

CashlessPaymentForm {
    id: root
    property int m_balance: 0
    property int m_step: 0

    onVisibleChanged: {
        if (root.visible == true) {
            back_timer.start();
            m_step = 50;
            m_balance = 0;
            cashless_btns.slideInit();
            cashless_info.showPaymentInfo();
        }

    }


    cashless_btns.onBtnIncClicked: {
        if (m_balance == 0)
            cashless_btns.btnSndEnable(true);
        m_balance += m_step;
    }

    cashless_btns.onBtnDecClicked: {
        if (m_balance - m_step <= 0) {
            m_balance = 0;
            cashless_btns.btnSndEnable(false);
        } else
            m_balance -= m_step;
    }

    cashless_btns.onBtnS10Clicked: {
        m_step = 10;
    }

    cashless_btns.onBtnS50Clicked: {
        m_step = 50;
    }

    cashless_btns.onBtnSndClicked: {
        if (m_balance > 0) {
            app_footer.state = app_footer.empty;
            window.qmlSendPayment(m_balance, back_screen);
        }
    }

    Timer {
       id: back_timer
       interval: 30000;
       running: false;
       onTriggered: {
           back_timer.stop();
           backend.showWaiting();
       }
    }

    Connections {
        target: backend
        function onSetUIConfig(config) {
            back_timer.interval = config["BankTerminalBackTimeout"] * 1000;
        }
    }

}
