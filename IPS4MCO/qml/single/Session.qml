import QtQuick 2.4
import QtQuick.Controls 2.5
import IPS4MCO 1.0

SessionForm {
    id: form
    readonly property int cbtn1_msk: 0x1
    readonly property int cbtn2_msk: 0x2
    readonly property int cbtn3_msk: 0x4
    readonly property int cbtn4_msk: 0x8
    readonly property int cbtn5_msk: 0xC
    readonly property int cbtn6_msk: 0x10
    readonly property int cbtn7_msk: 0x20
    readonly property int cbtn8_msk: 0x40
    readonly property int cbtn_pause_msk: 0x80
    signal resetButtons();

    onResetButtons: {
        btn_turbosushka.checked = false
        btn_vacuum_cleaner.checked = false
        btn_high_pressure.checked = false
        btn_medium_pressure.checked = false
        btn_weak_pressure.checked = false
        btn_active_chemistry.checked = false
        btn_foam.checked = false
        btn_wax_polish.checked = false
        btn_pause.checked = true;
    }

    function clikedButton(current_button) {
        if (isWaiting) {
            btn_pause.checked = true;
            return;
        }

        var lpressedbuttons = current_button

        btn_turbosushka.checked = current_button === cbtn1_msk
        btn_vacuum_cleaner.checked = current_button === cbtn2_msk
        btn_high_pressure.checked = current_button === cbtn3_msk
        btn_medium_pressure.checked = current_button === cbtn4_msk
        btn_weak_pressure.checked = current_button === cbtn5_msk
        btn_active_chemistry.checked = current_button === cbtn6_msk
        btn_foam.checked = current_button === cbtn7_msk
        btn_wax_polish.checked = current_button === cbtn8_msk
        btn_pause.checked = current_button === cbtn_pause_msk

        window.qmlSetButtons(lpressedbuttons)
    }

    btn_turbosushka.onButtonClicked: {
        clikedButton(cbtn1_msk);
    }
    btn_vacuum_cleaner.onButtonClicked: {
        clikedButton(cbtn2_msk);
    }
    btn_high_pressure.onButtonClicked: {
        clikedButton(cbtn3_msk);
    }
    btn_medium_pressure.onButtonClicked: {
        clikedButton(cbtn4_msk);
    }
    btn_weak_pressure.onButtonClicked: {
        clikedButton(cbtn5_msk);
    }
    btn_active_chemistry.onButtonClicked: {
        clikedButton(cbtn6_msk);
    }
    btn_foam.onButtonClicked: {
        clikedButton(cbtn7_msk);
    }
    btn_wax_polish.onButtonClicked: {
        clikedButton(cbtn8_msk);
    }
    btn_pause.onButtonClicked: {
        clikedButton(cbtn_pause_msk);
    }

    Connections {
        target: backend
        function onSetUIConfig(config) {
            btn_turbosushka.buttonText = config["ProgramName1"]
            btn_vacuum_cleaner.buttonText = config["ProgramName2"]
            btn_high_pressure.buttonText = config["ProgramName3"]
            btn_medium_pressure.buttonText = config["ProgramName4"]
            btn_weak_pressure.buttonText = config["ProgramName5"]
            btn_active_chemistry.buttonText = config["ProgramName6"]
            btn_foam.buttonText = config["ProgramName7"]
            btn_wax_polish.buttonText = config["ProgramName8"]

            balance.titleText = config["Title"]
            balance.logoImage = "file:/" + applicationDirPath + "/" + config["Logo"]
        }

        function onSetPressedButtons(button) {
            btn_turbosushka.checked = button === cbtn1_msk
            btn_vacuum_cleaner.checked = button === cbtn2_msk
            btn_high_pressure.checked = button === cbtn3_msk
            btn_medium_pressure.checked = button === cbtn4_msk
            btn_weak_pressure.checked = button === cbtn5_msk
            btn_active_chemistry.checked = button === cbtn6_msk
            btn_foam.checked = button === cbtn7_msk
            btn_wax_polish.checked = button === cbtn8_msk
            btn_pause.checked = button === cbtn_pause_msk
            window.qmlSetButtons(button)
        }

        function onShowSession(state) {
            clikedButton(cbtn_pause_msk);
        }
    }
}





/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
