import QtQuick 2.4


WaitingForm {
    id: form
    signal show()
    signal hide()

    onShow: {
        if (envideo && enimage) {
            form.state = "svideo"
            form.video_waiting.seek(0);
            form.video_waiting.play();
        } else if (envideo) {
            form.state = "svideo"
            form.video_waiting.seek(0);
            form.video_waiting.play();
        } else if (enimage) {
            form.state = "simage"
            form.image_waiting.currentFrame = 0
            form.image_waiting.playing = true;
        }
    }

    onHide: {
        if (envideo && enimage) {
            form.video_waiting.stop();
        } else if (envideo) {
            form.video_waiting.stop();
        } else if (enimage) {
            form.image_waiting.playing = false;
        }
    }

    Connections {
        target: backend
        function onSetUIConfig(config) {
            envideo = config["UIEnableMediaVideo"];
            enimage = config["UIEnableMediaBitmap"];

            form.image_waiting.source = "file:" + applicationDirPath + "media/" + config["UIMediaBitmap"];
            form.video_waiting.source = "file:" + applicationDirPath + "media/" + config["UIMediaVideo"];
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
