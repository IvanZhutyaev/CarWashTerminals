import QtQuick 2.0

Item {
}
/*
import QtQuick 2.0
import QtQuick.Controls 2.5
import QtMultimedia 5.15
import IPS4MCO 1.0

Item {
    readonly property int kNull: 0
    readonly property int kAudio1: 1
    readonly property int kAudio2: 2
    readonly property int kAudio3: 3
    readonly property int kAudio4: 4
    readonly property int kAudio5: 5
    readonly property int kAudio6: 6
    readonly property int kAudio7: 7
    readonly property int kAudio8: 8
    readonly property int kAudioPause: 9
    property int _play_audio_id: 0
    property bool _playing: false
    property variant audio_enabled: [ true, true, true, true, true, true, true, true, true, true ]


    id: root
    Audio {
        id: audio1
        onStopped: {
            _playing = false;
        }
        onErrorChanged: {
            audio_enabled[1] = error === Audio.NoError
        }
    }
    Audio {
        id: audio2
        onStopped: {
            _playing = false;
        }
        onErrorChanged: {
            audio_enabled[2] = error === Audio.NoError
        }
    }
    Audio {
        id: audio3
        onStopped: {
            _playing = false;
        }
        onErrorChanged: {
            audio_enabled[3] = error === Audio.NoError
        }
    }
    Audio {
        id: audio4
        onStopped: {
            _playing = false;
        }
        onErrorChanged: {
            audio_enabled[4] = error === Audio.NoError
        }
    }
    Audio {
        id: audio5
        onStopped: {
            _playing = false;
        }
        onErrorChanged: {
            audio_enabled[5] = error === Audio.NoError
        }
    }
    Audio {
        id: audio6
        onStopped: {
            _playing = false;
        }
        onErrorChanged: {
            audio_enabled[6] = error === Audio.NoError
        }
    }
    Audio {
        id: audio7
        onStopped: {
            _playing = false;
        }
        onErrorChanged: {
            audio_enabled[7] = error === Audio.NoError
        }
    }
    Audio {
        id: audio8
        onStopped: {
            _playing = false;
        }
        onErrorChanged: {
            audio_enabled[8] = error === Audio.NoError
        }
    }
    Audio {
        id: audio_pause
        onStopped: {
            _playing = false;
        }
        onErrorChanged: {
            audio_enabled[9] = error === Audio.NoError
        }
    }
    function play_audio(audio_id) {
        _playing = true;
        switch(audio_id) {
            case kAudio1:
                audio1.play();
                break;
            case kAudio2:
                audio2.play();
                break;
            case kAudio3:
                audio3.play();
                break;
            case kAudio4:
                audio4.play();
                break;
            case kAudio5:
                audio5.play();
                break;
            case kAudio6:
                audio6.play();
                break;
            case kAudio7:
                audio7.play();
                break;
            case kAudio8:
                audio8.play();
                break;
            case kAudioPause:
                audio_pause.play();
                break;
        }
    }
    function stop_audio(audio_id) {
        _playing = false;
        switch(audio_id) {
            case kAudio1:
                audio1.stop();
                break;
            case kAudio2:
                audio2.stop();
                break;
            case kAudio3:
                audio3.stop();
                break;
            case kAudio4:
                audio4.stop();
                break;
            case kAudio5:
                audio5.stop();
                break;
            case kAudio6:
                audio6.stop();
                break;
            case kAudio7:
                audio7.stop();
                break;
            case kAudio8:
                audio8.stop();
                break;
            case kAudioPause:
                audio_pause.stop();
                break;
        }
    }
    function play(audio_id) {
        if (audio_id === _play_audio_id) {
            // nop
        } else if (!_playing && !timer.running && audio_enabled[audio_id]) {
            play_audio(audio_id);
        } else if (timer.running && !audio_enabled[_play_audio_id] && audio_enabled[audio_id]) {
            play_audio(audio_id);
        } else if (!timer.running && audio_enabled[_play_audio_id]){
            stop_audio(_play_audio_id);
            if (audio_enabled[audio_id])
                timer.start();
        }

        _play_audio_id = audio_id
    }
    function playing() {
        play_audio(_play_audio_id);
    }
    Timer {
        id: timer
        interval: 1000
        running: false
        repeat: false
        onTriggered: playing()
    }
    Connections {
        target: backend
        function onSetUIConfig(config) {
            audio1.source = "file://" + applicationDirPath + "/" + config["ProgramAudio1"]
            audio2.source = "file://" + applicationDirPath + "/" + config["ProgramAudio2"]
            audio3.source = "file://" + applicationDirPath + "/" + config["ProgramAudio3"]
            audio4.source = "file://" + applicationDirPath + "/" + config["ProgramAudio4"]
            audio5.source = "file://" + applicationDirPath + "/" + config["ProgramAudio5"]
            audio6.source = "file://" + applicationDirPath + "/" + config["ProgramAudio6"]
            audio7.source = "file://" + applicationDirPath + "/" + config["ProgramAudio7"]
            audio8.source = "file://" + applicationDirPath + "/" + config["ProgramAudio8"]
            audio_pause.source = "file://" + applicationDirPath + "/" + config["ProgramAudioPause"]
        }
    }
}
*/
