#include "logmanager.h"

LogManager::LogManager(QString file_path, QObject *parent) : QObject(parent)
{
    LogManager::file_path = file_path;

    map.insert(Errors::CMFileOpen, "Ошибка чтения файла конфигурации");
    map.insert(Errors::CMFileExist, "Ошибка создания файла конфигурации. Файл существует.");
    map.insert(Errors::CMFileOpen, "Ошибка чтения файла конфигурации. Файл не существует.");
    map.insert(Errors::CMSyntaxUI, "Некорректный синтаксис конфигурационного файла ui.json. Возможна пропущена или стоит лишняя запятая(,) в конце строки.");
    map.insert(Errors::CMSyntaxMBS, "Некорректный синтаксис конфигурационного файла modbus.json. Возможна пропущена или стоит лишняя запятая(,) в конце строки.");


    map.insert(Errors::CMBaudRate, "Некорректное значение параметра BaudRate или параметр отсутствует. Допустимые значения:  1200; 2400; 4800; 9600; 19200; 38400; 57600; 115200; 230400.");
    map.insert(Errors::CMConfigParity, "Некорректное значение параметра Parity или параметр отсутствует. Допустимые значения:  0 - none; 2 - even; 3 - odd.");
    map.insert(Errors::CMConfigDataBits, "Некорректное значение параметра DataBits или параметр отсутствует. Допустимые значения: 7;8.");
    map.insert(Errors::CMConfigServerAddress, "Некорректное значение параметра ServerAddress или параметр отсутствует. Допустимые значения: 1 - 255");
    map.insert(Errors::CMConfigStopBits, "Некорректное значение параметра StopBits или параметр отсутствует. Допустимые значения: 1; 2.");
    map.insert(Errors::CMConfigTimeout, "Некорректное значение параметра Timeout или параметр отсутствует. Допустимые значения: 1 - 255 ");

    map.insert(Errors::UINumberOfPrograms, "Некорректное значение параметра NumberOfPrograms или параметр отсутствует. Допустимые значения: 1 - 7.");
    map.insert(Errors::UICodeTiming, "Некорректное значение параметра QrCodeTiming или параметр отсутствует. Допустимые значения: 1 - 255.");
    map.insert(Errors::UIQrCodeDataTimeout, "Некорректное значение параметра QrCodeDataTimeout или параметр отсутствует. Допустимые значения: 1 - 255.");
    // Некорректное значение параметра UIProgramName1. Возможно строка не заключена в кавычки(\"строка\") или пропущена заятая(,) в конце строки.
    map.insert(Errors::UIProgramName1, "Некорректное значение параметра ProgramName1 или параметр отсутствует.");
    map.insert(Errors::UIProgramName2, "Некорректное значение параметра ProgramName2 или параметр отсутствует.");
    map.insert(Errors::UIProgramName3, "Некорректное значение параметра ProgramName3 или параметр отсутствует.");
    map.insert(Errors::UIProgramName4, "Некорректное значение параметра ProgramName4 или параметр отсутствует.");
    map.insert(Errors::UIProgramName5, "Некорректное значение параметра ProgramName5 или параметр отсутствует.");
    map.insert(Errors::UIProgramName6, "Некорректное значение параметра ProgramName6 или параметр отсутствует.");
    map.insert(Errors::UIProgramName7, "Некорректное значение параметра ProgramName7 или параметр отсутствует.");
    map.insert(Errors::UIProgramName8, "Некорректное значение параметра ProgramName8 или параметр отсутствует.");

    map.insert(Errors::UIProgramImage1, "Некорректное значение параметра ProgramImage1 или параметр отсутствует.");
    map.insert(Errors::UIProgramImage2, "Некорректное значение параметра ProgramImage2 или параметр отсутствует.");
    map.insert(Errors::UIProgramImage3, "Некорректное значение параметра ProgramImage3 или параметр отсутствует.");
    map.insert(Errors::UIProgramImage4, "Некорректное значение параметра ProgramImage4 или параметр отсутствует.");
    map.insert(Errors::UIProgramImage5, "Некорректное значение параметра ProgramImage5 или параметр отсутствует.");
    map.insert(Errors::UIProgramImage6, "Некорректное значение параметра ProgramImage6 или параметр отсутствует.");
    map.insert(Errors::UIProgramImage7, "Некорректное значение параметра ProgramImage7 или параметр отсутствует.");
    map.insert(Errors::UIProgramImage8, "Некорректное значение параметра ProgramImage8 или параметр отсутствует.");


    map.insert(Errors::UILogo, "Некорректное значение параметра Logo или параметр отсутствует.");
    map.insert(Errors::UIMediaBitmap, "Некорректное значение параметра UIMediaBitmap или параметр отсутствует.");
    map.insert(Errors::UIMediaVideo, "Некорректное значение параметра UIMediaVideo или параметр отсутствует.");
    map.insert(Errors::UITitle, "Некорректное значение параметра Title или параметр отсутствует.");
    map.insert(Errors::UIPhone, "Некорректное значение параметра Phone.");
    map.insert(Errors::UITerminalID, "Некорректное значение параметра TerminalID или параметр отсутствует.");
    map.insert(Errors::UIPauseCost, "Некорректное значение параметра PauseCost или параметр отсутствует. Допустимые значения: 1 - 255.");
    map.insert(Errors::UIEnableMediaBitmap, "Некорректное значение параметра UIEnableMediaBitmap или параметр отсутствует. Допустимые значения: true или false.");
    map.insert(Errors::UIEnableMediaVideo, "Некорректное значение параметра UIEnableMediaVideo или параметр отсутствует. Допустимые значения: true или false.");
    map.insert(Errors::UIEnableBitmapVideo, "Включен показ изображения(UIEnableMediaBitmap) и видео(UIEnableMediaVideo) одновременно. Возможен показ только одного источника.");
    map.insert(Errors::UIBankTerminalBackTimeout, "Некорректное значение параметра BankTerminalBackTimeout или параметр отсутствует. Допустимые значения: 1 - 255.");
    map.insert(Errors::UIBankTerminalErrorTimeout, "Некорректное значение параметра BankTerminalErrorTimeout или параметр отсутствует. Допустимые значения: 1 - 255.");
    map.insert(Errors::UIBankTerminalSuccessTimeout, "Некорректное значение параметра BankTerminalSuccessTimeout или параметр отсутствует. Допустимые значения: 1 - 255.");


    map.insert(Errors::UISlideChangeTimeout, "Некорректное значение параметра SlideChangeTimeout или параметр отсутствует. Допустимые значения: 1 - 30000(в миллисекундах).");
    map.insert(Errors::UIInitSlideChangeMult, "Некорректное значение параметра InitSlideChangeMult или параметр отсутствует. Допустимые значения: 1 - 30000(в миллисекундах).");
    map.insert(Errors::UIButtonTimeout, "Некорректное значение параметра ButtonTimeout или параметр отсутствует. Допустимые значения: 1 - 30000(в миллисекундах).");


    map.insert(Errors::MCConnect, "Невозможно занять указанный COM порт.");
    map.insert(Errors::MCDisconnect, "Невозможно освободить указанный COM порт.");
    map.insert(Errors::MCCreateDevice, "Указанный COM порт отсутствует в системе.");
    map.insert(Errors::MCTimeout, "Отсутствие связи с Modbus RTU Master.");
    map.insert(Errors::MCConnectionLost, "Неожиданное отключение COM порта.");
    map.insert(Errors::MCAlreadyConnected, "Невозможно занять указанный COM порт. COM порт уже занят.");
    map.insert(Errors::MCQRCode, "Не получены данные для формирования QR кода.");
    map.insert(Errors::MCPLC, "Авария Modbus RTU Master.");
}

void LogManager::addMsg(int error) {
    int lerror;
    QString subsystyem;
    QString messagetype;
    if (error >= ERRORS_SUBSYSTEM_PLC) {
        lerror = error - 1000;
        subsystyem = "PLC";
        messagetype = "Ошибка";
    } else if (error >= ERRORS_SUBSYSTEM_UI) {
        lerror = error;
        subsystyem = "UI";
        messagetype = "Фатальная ошибка";
    } else {
        lerror = error;
        subsystyem = "MBS";
        messagetype = "Ошибка";
    }

    QString message = map.value(error > 1000 ? 1000 : error);

    LogManager::addMsg(message, subsystyem, messagetype, ". Код ошибки: " + QVariant(lerror).toString());
}

void LogManager::addMsg(QString text, QString subsystyem, QString messagetype, QString errorcode) {
    QDateTime timestamp = QDateTime::currentDateTime();
    QString message = "";
    QString lfile_path = file_path + "event_log_" + timestamp.toString("dd_MM_yyyy") + ".log";

    message = messagetype + ". Подсистема: " + subsystyem + errorcode + ". Сообщение: " + text + "\n";

    if (message != last_massage) {
        QFile config(lfile_path);
        if (config.open(config.exists() ? QIODevice::Append : QIODevice::ReadWrite)){
            QTextStream cfgwrite(&config);
            cfgwrite << timestamp.toString("dd.MM.yyyy hh:mm:ss ") + message;
            config.close();
        }
    }
    last_massage = message;
}
