import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0

SessionForm {
    id: form


    function clikedButton(current_button) {
        var lpressedbuttons = 1 << current_button

        button_prog1.checked = current_button === 0
        button_prog2.checked = current_button === 1
        button_prog3.checked = current_button === 2
        button_prog4.checked = current_button === 3
        button_prog5.checked = current_button === 4
        button_prog6.checked = current_button === 5
        button_prog7.checked = current_button === 6
        button_pause.checked = current_button === 7

        window.qmlSetButtons(lpressedbuttons)


        // it move block where getting current button from plc
        //if (current_button < 7 && (form.state == "pause_free" || form.state == "pause"))
        //    form.state = "washing";

        //backend.pressedbuttons = lpressedbuttons

    }


    function checkPause() {
        if (form.state == "washing")
            if (backend.pause_time === "00:00")
                form.state = "pause"
            else
                form.state = "pause_free"
    }



    button_prog1.onButtonClicked: {
        clikedButton(0);
    }
    button_prog2.onButtonClicked: {
        clikedButton(1);
    }
    button_prog3.onButtonClicked: {
        clikedButton(2);
    }
    button_prog4.onButtonClicked: {
        clikedButton(3);
    }
    button_prog5.onButtonClicked: {
        clikedButton(4);
    }
    button_prog6.onButtonClicked: {
        clikedButton(5);
    }
    button_prog7.onButtonClicked: {
        clikedButton(6);
    }

    button_pause.onButtonClicked: {
        clikedButton(7);
        //checkPause();
    }

    text_time.onTextChanged: {
        var time = text_time.text.slice(0, text_time.text.indexOf(':') - 1);
        if (time >= 2) {
            //text_time.color = "#0BB232"
            //text_balance.color = "#0BB232"
            text_time.color = color_cfg.second
            text_balance.color = color_cfg.second
        } else if (time == 1) {
            //text_time.color = "#F4720C"
            //text_balance.color = "#F4720C"
            text_time.color = color_cfg.third
            text_balance.color = color_cfg.third
        } else {
            //text_time.color = "#DB030C"
            //text_balance.color = "#DB030C"
            text_time.color = color_cfg.error
            text_balance.color = color_cfg.error
        }

        if (form.state == "pause_free") {
            if (text_time.text == "00:00")
                form.state = "pause"
        }
    }

    Connections {
        target: backend
        function onSetUIConfig(config) {
            var NumberOfPrograms = config["NumberOfPrograms"];
            var button_rows = Math.ceil((NumberOfPrograms + 1) / 2);
            var margin_space = (buttons.height - button_prog1.height * button_rows) / button_rows;


            pause_cost = config["PauseCost"]
            button_prog1.text = config["ProgramName1"]
            button_prog1.visible = 0 < NumberOfPrograms
            button_prog2.text = config["ProgramName2"]
            button_prog2.visible = 1 < NumberOfPrograms
            button_prog3.text = config["ProgramName3"]
            button_prog3.visible = 2 < NumberOfPrograms
            button_prog4.text = config["ProgramName4"]
            button_prog4.visible = 3 < NumberOfPrograms
            button_prog5.text = config["ProgramName5"]
            button_prog5.visible = 4 < NumberOfPrograms
            button_prog6.text = config["ProgramName6"]
            button_prog6.visible = 5 < NumberOfPrograms
            button_prog7.text = config["ProgramName7"]
            button_prog7.visible = 6 < NumberOfPrograms


            button_prog1.anchors.topMargin = margin_space / 2;
            button_prog2.anchors.topMargin = margin_space / 2;
            button_prog3.anchors.topMargin = button_prog1.y + button_prog1.height + margin_space;
            button_prog4.anchors.topMargin = button_prog1.y + button_prog1.height + margin_space;
            button_prog5.anchors.topMargin = button_prog3.y + button_prog3.height + margin_space;
            button_prog6.anchors.topMargin = button_prog3.y + button_prog3.height + margin_space;
            button_prog7.anchors.topMargin = button_prog5.y + button_prog5.height + margin_space;
            switch (button_rows) {
                case 1:
                    button_pause.anchors.topMargin = margin_space / 2;
                    break;
                case 2:
                    button_pause.anchors.topMargin = button_prog1.y + button_prog5.height + margin_space;
                    break;
                case 3:
                    button_pause.anchors.topMargin = button_prog3.y + button_prog5.height + margin_space;
                    break;
                case 4:
                    button_pause.anchors.topMargin = button_prog5.y + button_prog5.height + margin_space;
                    break;
            }


        }

        function onSetPressedButtons(button) {
            /*for (var i = 0; i < 7; i++) {
                    buttons_group.buttons[6-i].checked = button & (1 << i)
            }*/
            button_prog1.checked = button & (1 << 0)
            button_prog2.checked = button & (1 << 1)
            button_prog3.checked = button & (1 << 2)
            button_prog4.checked = button & (1 << 3)
            button_prog5.checked = button & (1 << 4)
            button_prog6.checked = button & (1 << 5)
            button_prog7.checked = button & (1 << 6)
            button_pause.checked = button & (1 << 7)
            if (button_pause.checked)
                checkPause()
            else
                form.state = "washing";
            window.qmlSetButtons(button)

            //if ((current_button < button & (1 << 7)) && (form.state == "pause_free" || form.state == "pause"))


        }

        function onShowSession(state) {
            //window.qmlSetButtons(0);
            if (state & 0x2)
                form.state = "service"
            else if (state & 0x4)
                form.state = "unlimit"
            else if (state & 0x8 && button_pause.checked)
                form.state = "pause_free"
            else if (state & 0x1)
                form.state = "washing"
        }

    }

}





/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
