#include "configmanager.h"

ConfigManager::ConfigManager(QObject *parent) : QObject(parent)
{

}


//=========================================
// Function for work with configs
int ConfigManager::createModbusConfig(QString file_path) {
    int error = Errors::No;
    QFile config(file_path);

    if (!config.exists()){
        if (config.open(QIODevice::ReadWrite)){
            QTextStream cfgwrite(&config);
            QJsonObject root;
            root.insert("BaudRate", 19200);
            root.insert("DataBits", 8);
            root.insert("Parity", 2);
            root.insert("PortName", "/dev/ttyUSB0");
            root.insert("ServerAddress", 1);
            root.insert("StopBits", 1);
            root.insert("Timeout", 8); // seconds

            QJsonDocument doc;
            doc.setObject(root);

            cfgwrite << doc.toJson();
            config.close();
        } else {
            error = Errors::CMFileOpen;
        }
    } else {
        error = Errors::CMFileExist;
    }

    return error;
}


int ConfigManager::createUIConfig(QString file_path) {
    int error = Errors::No;
    QFile config(file_path);

    if (!config.exists()){
        if (config.open(QIODevice::ReadWrite)){
            QTextStream cfgwrite(&config);
            QJsonObject root;
            root.insert("ProgramName1", "Name1");
            root.insert("ProgramName2", "Name2");
            root.insert("ProgramName3", "Name3");
            root.insert("ProgramName4", "Name4");
            root.insert("ProgramName5", "Name5");
            root.insert("ProgramName6", "Name6");
            root.insert("ProgramName7", "Name7");
            root.insert("NumberOfPrograms", 7); // 1-7
            root.insert("QrCodeTiming", 15); //seconds
            root.insert("QrCodeDataTimeout", 10); //seconds
            root.insert("UILogo", "logo.png");
            root.insert("UIMediaBitmap", "MediaBitmap.png");
            root.insert("UIMediaVideo", "MediaVideo.png");
            root.insert("Title", "Title");
            root.insert("Phone", "8 000 000 00 00");
            root.insert("TerminalID", "000");
            root.insert("PauseCost", 0);
            root.insert("EnableMediaBitmap", true);
            root.insert("EnableMediaVideo", false);
            // Timeout between change pause timer slides in session
            root.insert("SlideChangeTimeout", 1000);
            // multiple for "timeout between change pause timer slides" in init session
            root.insert("InitSlideChangeMult", 3);
            // Pressed Button Timeout
            root.insert("ButtonTimeout", 5000);
            root.insert("BankTerminalBackTimeout", 30);
            root.insert("BankTerminalErrorTimeout", 5);
            root.insert("BankTerminalSuccessTimeout", 5);



            QJsonDocument doc;
            doc.setObject(root);

            cfgwrite << doc.toJson();
            config.close();
        } else {
            error = Errors::CMFileOpen;
        }
    } else {
        error = Errors::CMFileExist;
    }

    return error;
}


ConfigManager::s_modbus_config ConfigManager::readModbusConfig(QString file_path, int *error) {
    *error = Errors::No;
    QFile configFile(file_path);
    QJsonObject root;
    s_modbus_config config;

    if (configFile.exists()){
        if (configFile.open(QIODevice::ReadOnly)){
            QTextStream cfgread(&configFile);
            QJsonDocument doc = QJsonDocument::fromJson(cfgread.readAll().toLocal8Bit());
            root = doc.object();
            configFile.close();

            *error = checkModbusConfig(root);
            if (*error)
                return config;

            config.BaudRate = root.value("BaudRate").toInt();
            config.DataBits = root.value("DataBits").toInt();
            config.Parity = root.value("Parity").toInt();
            config.PortName = root.value("PortName").toString();
            config.ServerAddress = root.value("ServerAddress").toInt();
            config.StopBits = root.value("StopBits").toInt();
            config.Timeout = root.value("Timeout").toInt() * 1000; // seconds
        } else {
            *error = Errors::CMFileOpen;
        }
    } else {
        *error = Errors::CMFileNotExist;
    }


    //last_error = ModbusPLC::MPLCErrorNo;
    return config;
}



QJsonObject ConfigManager::readUIConfig(QString file_path, int *error) {
    *error = Errors::No;
    QFile configFile(file_path);
    QJsonObject root;

    if (configFile.exists()){
        if (configFile.open(QIODevice::ReadOnly)){
            QTextStream cfgread(&configFile);
            QJsonDocument doc = QJsonDocument::fromJson(cfgread.readAll().toLocal8Bit());
            root = doc.object();
            configFile.close();

            *error = checkUIConfig(root);
            if (*error)
                return root;

        } else {
            *error = Errors::CMFileOpen;
        }
    } else {
        *error = Errors::CMFileNotExist;
    }

    return root;
}


int ConfigManager::checkModbusConfig(QJsonObject config) {
    const int BaudRates[] = {1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400};

    if (config.empty())
        return Errors::CMSyntaxMBS;

    int ba = config.value("BaudRate").toInt();
    int error = 1;

    for (unsigned int i = 0; i < (sizeof(BaudRates)/sizeof(BaudRates[0])); i++)
        if (BaudRates[i] == ba)
            error = 0;
    if (error)
        return Errors::CMBaudRate;

    int p = config.value("Parity").toInt();
    if (!((p == 0) || (p == 2) || (p == 3)))
        return Errors::CMConfigParity;

    int db = config.value("DataBits").toInt();
    if ((db < 7) || (db > 8))
        return Errors::CMConfigDataBits;

    int sa = config.value("ServerAddress").toInt();
    if ((sa < 1) || (sa > 255))
        return Errors::CMConfigServerAddress;

    int sb = config.value("StopBits").toInt();
    if ((sb < 1) || (sb > 255))
        return Errors::CMConfigStopBits;

    int tm = config.value("Timeout").toInt(); // seconds
    if ((tm < 1) || (tm > 255))
        return Errors::CMConfigTimeout;

    return 0;
}


int ConfigManager::checkUIConfig(QJsonObject config) {
    if (config.empty())
        return Errors::CMSyntaxUI;

    if (config.value("ProgramName1").toString() == "")
        return Errors::UIProgramName1;

    if (config.value("ProgramName2").toString() == "")
        return Errors::UIProgramName2;

    if (config.value("ProgramName3").toString() == "")
        return Errors::UIProgramName3;

    if (config.value("ProgramName4").toString() == "")
        return Errors::UIProgramName4;

    if (config.value("ProgramName5").toString() == "")
        return Errors::UIProgramName5;

    if (config.value("ProgramName6").toString() == "")
        return Errors::UIProgramName6;

    if (config.value("ProgramName7").toString() == "")
        return Errors::UIProgramName7;

    if (config.value("ProgramName8").toString() == "")
        return Errors::UIProgramName8;

    if (config.value("Logo").toString() == "")
        return Errors::UILogo;

    if (config.value("Title").toString() == "")
        return Errors::UITitle;

    int sct = config.value("SlideChangeTimeout").toInt();
    if ((sct < 1) || (sct > 30000))
        return Errors::UISlideChangeTimeout;

    int iscm = config.value("InitSlideChangeMult").toInt();
    if ((iscm < 1) || (iscm > 10))
        return Errors::UIInitSlideChangeMult;

    int bt = config.value("ButtonTimeout").toInt();
    if ((bt < 1) || (bt > 30000))
        return Errors::UIButtonTimeout;


    if (config.value("ProgramImage1").toString() == "")
        return Errors::UIProgramImage1;

    if (config.value("ProgramImage2").toString() == "")
        return Errors::UIProgramImage2;

    if (config.value("ProgramImage3").toString() == "")
        return Errors::UIProgramImage3;

    if (config.value("ProgramImage4").toString() == "")
        return Errors::UIProgramImage4;

    if (config.value("ProgramImage5").toString() == "")
        return Errors::UIProgramImage5;

    if (config.value("ProgramImage6").toString() == "")
        return Errors::UIProgramImage6;

    if (config.value("ProgramImage7").toString() == "")
        return Errors::UIProgramImage7;

    if (config.value("ProgramImage8").toString() == "")
        return Errors::UIProgramImage8;


    return 0;
}

//=========================================
