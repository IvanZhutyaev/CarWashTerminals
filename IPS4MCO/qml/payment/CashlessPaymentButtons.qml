import QtQuick 2.4

CashlessPaymentButtonsForm {
    id: root
    signal btnIncClicked()
    signal btnDecClicked()
    signal btnS10Clicked()
    signal btnS50Clicked()
    signal btnSndClicked()
    signal slideInit()
    signal btnSndEnable(bool value)


    property bool enable_buttons: true
    property bool enable_snd: false
    readonly property int step_10: 10
    readonly property int step_50: 50
    property int step: step_50


    MouseArea {
        id: mouseArea_inc
        anchors.fill: btn_increase

        onClicked: {
            if (enable_buttons)
                root.btnIncClicked();
        }

        onPressedChanged: {
            if (enable_buttons)
                //btn_increase.color = btn_increase.color == "#ffffff" ? "#c8c8c8" : "#ffffff";
                btn_increase.color = btn_increase.color == color_cfg.cashlessPaymentBtns1 ?
                            color_cfg.cashlessPaymentBtns8 : color_cfg.cashlessPaymentBtns1;
        }
    }


    MouseArea {
        id: mouseArea_dec
        anchors.fill: btn_decrease

        onClicked: {
            if (enable_buttons)
                root.btnDecClicked();
        }

        onPressedChanged: {
            //console.log(btn_decrease.color);
            //console.log(color_cfg.cashlessPaymentBtns1);
            if (enable_buttons)
                //btn_decrease.color = btn_decrease.color == "#ffffff" ? "#c8c8c8" : "#ffffff";
                btn_decrease.color = btn_decrease.color == color_cfg.cashlessPaymentBtns1 ?
                            color_cfg.cashlessPaymentBtns8 : color_cfg.cashlessPaymentBtns1;
        }
    }


    MouseArea {
        id: mouseArea_s10
        anchors.fill: btn_step_10

        onClicked: {
            if (!enable_buttons)
                return

            step = step_10;
            /*
            btn_step_50.color = "#fff"
            btn_step_50.border.color = "#fe7709"
            btn_step_50_step.color = "#fe7709"
            btn_step_50_price.color = "#fe7709"

            btn_step_10.color = "#fe7709"
            btn_step_10.border.color = "#e46a07"
            btn_step_10_step.color = "#fff"
            btn_step_10_price.color = "#fff"
            */

            btn_step_50.color = color_cfg.cashlessPaymentBtns1
            btn_step_50.border.color = color_cfg.cashlessPaymentBtns5
            btn_step_50_step.color = color_cfg.cashlessPaymentBtns5
            btn_step_50_price.color = color_cfg.cashlessPaymentBtns5

            btn_step_10.color = color_cfg.cashlessPaymentBtns5
            btn_step_10.border.color = color_cfg.cashlessPaymentBtns4
            btn_step_10_step.color = color_cfg.cashlessPaymentBtns1
            btn_step_10_price.color = color_cfg.cashlessPaymentBtns1

            root.btnS10Clicked();
        }
    }

    MouseArea {
        id: mouseArea_s50
        anchors.fill: btn_step_50

        onClicked: {
            if (!enable_buttons)
                return

            step = step_50;
            /*
            btn_step_10.color = "#fff"
            btn_step_10.border.color = "#fe7709"
            btn_step_10_step.color = "#fe7709"
            btn_step_10_price.color = "#fe7709"

            btn_step_50.color = "#fe7709"
            btn_step_50.border.color = "#e46a07"
            btn_step_50_step.color = "#fff"
            btn_step_50_price.color = "#fff"
            */

            btn_step_10.color = color_cfg.cashlessPaymentBtns1
            btn_step_10.border.color = color_cfg.cashlessPaymentBtns5
            btn_step_10_step.color = color_cfg.cashlessPaymentBtns5
            btn_step_10_price.color = color_cfg.cashlessPaymentBtns5

            btn_step_50.color = color_cfg.cashlessPaymentBtns5
            btn_step_50.border.color = color_cfg.cashlessPaymentBtns4
            btn_step_50_step.color = color_cfg.cashlessPaymentBtns1
            btn_step_50_price.color = color_cfg.cashlessPaymentBtns1

            root.btnS50Clicked();
        }
    }

    MouseArea {
        id: mouseArea_payment
        anchors.fill: btn_payment

        onClicked: {
            if (!enable_buttons || !enable_snd)
                return

            enable_buttons = false
            root.btnSndEnable(false);

            //btn_increase.border.color = "#b3b3b3";
            btn_increase.border.color = color_cfg.cashlessPaymentBtns7
            btn_increase_image.source = "qrc:/images/cpf_up_down_btn_icon_pressed.png"
            btn_increase_image_overlay.color = color_cfg.cashlessPaymentBtns6

            //btn_decrease.border.color = "#b3b3b3";
            btn_decrease.border.color = color_cfg.cashlessPaymentBtns7
            btn_decrease_image.source = "qrc:/images/cpf_up_down_btn_icon_pressed.png"
            btn_decrease_image_overlay.color = color_cfg.cashlessPaymentBtns6

            /*
            if (step == step_50) {
                btn_step_10.color = "#fff"
                btn_step_10.border.color = "#b3b3b3"
                btn_step_10_step.color = "#9b9b9b"
                btn_step_10_price.color = "#9b9b9b"

                btn_step_50.color = "#c8c8c8"
                btn_step_50.border.color = "#b3b3b3"
                btn_step_50_step.color = "#fff"
                btn_step_50_price.color = "#fff"
            } else {
                btn_step_10.color = "#c8c8c8"
                btn_step_10.border.color = "#b3b3b3"
                btn_step_10_step.color = "#fff"
                btn_step_10_price.color = "#fff"

                btn_step_50.color = "#fff"
                btn_step_50.border.color = "#b3b3b3"
                btn_step_50_step.color = "#9b9b9b"
                btn_step_50_price.color = "#9b9b9b"
            }
            */

            if (step == step_50) {
                btn_step_10.color = color_cfg.cashlessPaymentBtns1
                btn_step_10.border.color = color_cfg.cashlessPaymentBtns7
                btn_step_10_step.color = color_cfg.cashlessPaymentBtns6
                btn_step_10_price.color = color_cfg.cashlessPaymentBtns6

                btn_step_50.color = color_cfg.cashlessPaymentBtns8
                btn_step_50.border.color = color_cfg.cashlessPaymentBtns7
                btn_step_50_step.color = color_cfg.cashlessPaymentBtns1
                btn_step_50_price.color = color_cfg.cashlessPaymentBtns1
            } else {
                btn_step_10.color = color_cfg.cashlessPaymentBtns8
                btn_step_10.border.color = color_cfg.cashlessPaymentBtns7
                btn_step_10_step.color = color_cfg.cashlessPaymentBtns1
                btn_step_10_price.color = color_cfg.cashlessPaymentBtns1

                btn_step_50.color = color_cfg.cashlessPaymentBtns1
                btn_step_50.border.color = color_cfg.cashlessPaymentBtns7
                btn_step_50_step.color = color_cfg.cashlessPaymentBtns6
                btn_step_50_price.color = color_cfg.cashlessPaymentBtns6
            }

            root.btnSndClicked();
        }
    }

    onSlideInit: {
        enable_buttons = true;
        root.btnSndEnable(false);

        step = step_50;
        /*
        btn_step_10.color = "#fff"
        btn_step_10.border.color = "#fe7709"
        btn_step_10_step.color = "#fe7709"
        btn_step_10_price.color = "#fe7709"

        btn_step_50.color = "#fe7709"
        btn_step_50.border.color = "#e46a07"
        btn_step_50_step.color = "#fff"
        btn_step_50_price.color = "#fff"
        */

        btn_step_10.color = color_cfg.cashlessPaymentBtns1
        btn_step_10.border.color = color_cfg.cashlessPaymentBtns5
        btn_step_10_step.color = color_cfg.cashlessPaymentBtns5
        btn_step_10_price.color = color_cfg.cashlessPaymentBtns5

        btn_step_50.color = color_cfg.cashlessPaymentBtns5
        btn_step_50.border.color = color_cfg.cashlessPaymentBtns4
        btn_step_50_step.color = color_cfg.cashlessPaymentBtns1
        btn_step_50_price.color = color_cfg.cashlessPaymentBtns1

        //btn_increase.border.color = "#0088c6";
        btn_increase.border.color = color_cfg.cashlessPaymentBtns2
        btn_increase_image.source = "qrc:/images/cpf_up_down_btn_icon.png"
        btn_increase_image_overlay.color = color_cfg.cashlessPaymentBtns3

        //btn_decrease.border.color = "#0088c6";
        btn_decrease.border.color = color_cfg.cashlessPaymentBtns2
        btn_decrease_image.source = "qrc:/images/cpf_up_down_btn_icon.png"
        btn_decrease_image_overlay.color = color_cfg.cashlessPaymentBtns3

    }

    onBtnSndEnable: {
        enable_snd = value;
        if (value) {
            /*
            btn_payment.color = "#fff"
            btn_payment.border.color = "#0088c6"
            btn_payment_text.color = "#0088c6"
            */
            btn_payment.color = color_cfg.cashlessPaymentBtns1
            btn_payment.border.color = color_cfg.cashlessPaymentBtns2
            btn_payment_text.color = color_cfg.cashlessPaymentBtns2
        } else {
            /*
            btn_payment.color = "#0088c6"
            btn_payment.border.color = "#007cb5"
            btn_payment_text.color = "#fff"
            */
            btn_payment.color = color_cfg.cashlessPaymentBtns2
            btn_payment.border.color = color_cfg.cashlessPaymentBtns3
            btn_payment_text.color = color_cfg.cashlessPaymentBtns1
        }
    }
}
