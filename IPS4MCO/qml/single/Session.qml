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
        btn1.checked = false
        btn2.checked = false
        btn3.checked = false
        btn4.checked = false
        btn5.checked = false
        btn6.checked = false
        btn7.checked = false
        btn8.checked = false
        balance.pause_btn.checked = true;
    }

    function clikedButton(current_button) {
        if (isWaiting) {
            balance.pause_btn.checked = true;
            return;
        }

        var lpressedbuttons = current_button

        btn1.checked = current_button === cbtn1_msk
        btn2.checked = current_button === cbtn2_msk
        btn3.checked = current_button === cbtn3_msk
        btn4.checked = current_button === cbtn4_msk
        btn5.checked = current_button === cbtn5_msk
        btn6.checked = current_button === cbtn6_msk
        btn7.checked = current_button === cbtn7_msk
        btn8.checked = current_button === cbtn8_msk
        balance.pause_btn.checked = current_button === cbtn_pause_msk

        window.qmlSetButtons(lpressedbuttons)
    }
    btn1.onButtonClicked: {
        clikedButton(cbtn1_msk);
        //voiceover.play(voiceover.kAudio1)
    }
    btn2.onButtonClicked: {
        clikedButton(cbtn2_msk);
        //voiceover.play(voiceover.kAudio2)
    }
    btn3.onButtonClicked: {
        clikedButton(cbtn3_msk);
        //voiceover.play(voiceover.kAudio3)
    }
    btn4.onButtonClicked: {
        clikedButton(cbtn4_msk);
        //voiceover.play(voiceover.kAudio4)
    }
    btn5.onButtonClicked: {
        clikedButton(cbtn5_msk);
        //voiceover.play(voiceover.kAudio5)
    }
    btn6.onButtonClicked: {
        clikedButton(cbtn6_msk);
        //voiceover.play(voiceover.kAudio6)
    }
    btn7.onButtonClicked: {
        clikedButton(cbtn7_msk);
        //voiceover.play(voiceover.kAudio7)
    }

    btn8.onButtonClicked: {
        clikedButton(cbtn8_msk);
        //voiceover.play(voiceover.kAudio8)
    }

    balance.pause_btn.onButtonClicked: {
        clikedButton(cbtn_pause_msk);
        //voiceover.play(voiceover.kAudioPause)
    }

    Connections {
        target: backend
        function onSetUIConfig(config) {
            btn1.text = config["ProgramName1"]
            btn2.text = config["ProgramName2"]
            btn3.text = config["ProgramName3"]
            btn4.text = config["ProgramName4"]
            btn5.text = config["ProgramName5"]
            btn6.text = config["ProgramName6"]
            btn7.text = config["ProgramName7"]
            btn8.text = config["ProgramName8"]


            btn1.image = "file://" + applicationDirPath + "/" + config["ProgramImage1"]
            btn2.image = "file://" + applicationDirPath + "/" + config["ProgramImage2"]
            btn3.image = "file://" + applicationDirPath + "/" + config["ProgramImage3"]
            btn4.image = "file://" + applicationDirPath + "/" + config["ProgramImage4"]
            btn5.image = "file://" + applicationDirPath + "/" + config["ProgramImage5"]
            btn6.image = "file://" + applicationDirPath + "/" + config["ProgramImage6"]
            btn7.image = "file://" + applicationDirPath + "/" + config["ProgramImage7"]
            btn8.image = "file://" + applicationDirPath + "/" + config["ProgramImage8"]

            balance.titleText = config["Title"]
            balance.logoImage = "file:/" + applicationDirPath + "/" + config["Logo"]
        }

        function onSetPressedButtons(button) {
            btn1.checked = button === cbtn1_msk
            btn2.checked = button === cbtn2_msk
            btn3.checked = button === cbtn3_msk
            btn4.checked = button === cbtn4_msk
            btn5.checked = button === cbtn5_msk
            btn6.checked = button === cbtn6_msk
            btn7.checked = button === cbtn7_msk
            btn8.checked = button === cbtn8_msk
            balance.pause_btn.checked = button === cbtn_pause_msk
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
