#include "colorconfig.h"
#include <QRegularExpression>
colorconfig::colorconfig(const QString& appdir, QObject *parent)
    : QObject(parent),
      appdir(appdir)
{

}


QString colorconfig::first() const {
    return m_first;
}

void colorconfig::setFirst(const QString& color) {
    if (color == m_first)
        return;

    m_first = color;
    emit firstChanged();
}



QString colorconfig::second() const {
    return m_second;
}

void colorconfig::setSecond(const QString& color) {
    if (color == m_second)
        return;

    m_second = color;
    emit secondChanged();
}






QString colorconfig::third() const {
    return m_third;
}

void colorconfig::setThird(const QString& color) {
    if (color == m_third)
        return;

    m_third = color;
    emit thirdChanged();
}





QString colorconfig::fourth() const {
    return m_fourth;
}

void colorconfig::setFourth(const QString& color) {
    if (color == m_fourth)
        return;

    m_fourth = color;
    emit fourthChanged();
}


QString colorconfig::fifth() const {
    return m_fifth;
}

void colorconfig::setFifth(const QString& color) {
    if (color == m_fifth)
        return;

    m_fifth = color;
    emit fifthChanged();
}












QString colorconfig::error() const {
    return m_error;
}

void colorconfig::setError(const QString& color) {
    if (color == m_error)
        return;

    m_error = color;
    emit errorChanged();
}


QString colorconfig::header() const {
    return m_header;
}

void colorconfig::setHeader(const QString& color) {
    if (color == m_header)
        return;

    m_header = color;
    emit headerChanged();
}


QString colorconfig::collectionImg() const {
    return m_collectionImg;
}

void colorconfig::setCollectionImg(const QString& color) {
    if (color == m_collectionImg)
        return;

    m_collectionImg = color;
    emit collectionImgChanged();
}







QString colorconfig::background() const {
    return m_background;
}

void colorconfig::setBackground(const QString& color) {
    if (color == m_background)
        return;

    m_background = color;
    emit backgroundChanged();
}




bool colorconfig::isWalletOverlay() const {
    return m_isWalletOverlay;
}

void colorconfig::setIsWalletOverlay(const bool& visible) {
    if (visible == m_isWalletOverlay)
        return;

    m_isWalletOverlay = visible;
    emit isWalletOverlayChanged();
}





bool colorconfig::isButtonOverlay() const {
    return m_isButtonOverlay;
}

void colorconfig::setIsButtonOverlay(const bool& visible) {
    if (visible == m_isButtonOverlay)
        return;

    m_isButtonOverlay = visible;
    emit isButtonOverlayChanged();
}


bool colorconfig::isCollectionOverlay() const {
    return m_isCollectionOverlay;
}

void colorconfig::setIsCollectionOverlay(const bool& visible) {
    if (visible == m_isCollectionOverlay)
        return;

    m_isCollectionOverlay = visible;
    emit isCollectionOverlayChanged();
}


bool colorconfig::isSessionOverlay() const {
    return m_isSessionOverlay;
}

void colorconfig::setIsSessionOverlay(const bool& visible) {
    if (visible == m_isSessionOverlay)
        return;

    m_isSessionOverlay = visible;
    emit isSessionOverlayChanged();
}


bool colorconfig::isErrorOverlay() const {
    return m_isErrorOverlay;
}

void colorconfig::setIsErrorOverlay(const bool& visible) {
    if (visible == m_isErrorOverlay)
        return;

    m_isErrorOverlay = visible;
    emit isErrorOverlayChanged();
}

bool colorconfig::isCashlessOverlay() const {
    return m_isCashlessOverlay;
}

void colorconfig::setIsCashlessOverlay(const bool& visible) {
    if (visible == m_isCashlessOverlay)
        return;

    m_isCashlessOverlay = visible;
    emit isCashlessOverlayChanged();
}


bool colorconfig::isFooterOverlay() const {
    return m_isFooterOverlay;
}

void colorconfig::setIsFooterOverlay(const bool& visible) {
    if (visible == m_isFooterOverlay)
        return;

    m_isFooterOverlay = visible;
    emit isFooterOverlayChanged();
}










QString colorconfig::cashlessPaymentBtns1() const {
    return m_cashlessPaymentBtns1;
}

void colorconfig::setCashlessPaymentBtns1(const QString& visible) {
    if (visible == m_cashlessPaymentBtns1)
        return;

    m_cashlessPaymentBtns1 = visible;
    emit cashlessPaymentBtns1Changed();
}

QString colorconfig::cashlessPaymentBtns2() const {
    return m_cashlessPaymentBtns2;
}

void colorconfig::setCashlessPaymentBtns2(const QString& visible) {
    if (visible == m_cashlessPaymentBtns2)
        return;

    m_cashlessPaymentBtns2 = visible;
    emit cashlessPaymentBtns2Changed();
}

QString colorconfig::cashlessPaymentBtns3() const {
    return m_cashlessPaymentBtns3;
}

void colorconfig::setCashlessPaymentBtns3(const QString& visible) {
    if (visible == m_cashlessPaymentBtns3)
        return;

    m_cashlessPaymentBtns3 = visible;
    emit cashlessPaymentBtns3Changed();
}

QString colorconfig::cashlessPaymentBtns4() const {
    return m_cashlessPaymentBtns4;
}

void colorconfig::setCashlessPaymentBtns4(const QString& visible) {
    if (visible == m_cashlessPaymentBtns4)
        return;

    m_cashlessPaymentBtns4 = visible;
    emit cashlessPaymentBtns4Changed();
}

QString colorconfig::cashlessPaymentBtns5() const {
    return m_cashlessPaymentBtns5;
}

void colorconfig::setCashlessPaymentBtns5(const QString& visible) {
    if (visible == m_cashlessPaymentBtns5)
        return;

    m_cashlessPaymentBtns5 = visible;
    emit cashlessPaymentBtns5Changed();
}

QString colorconfig::cashlessPaymentBtns6() const {
    return m_cashlessPaymentBtns6;
}

void colorconfig::setCashlessPaymentBtns6(const QString& visible) {
    if (visible == m_cashlessPaymentBtns6)
        return;

    m_cashlessPaymentBtns6 = visible;
    emit cashlessPaymentBtns6Changed();
}

QString colorconfig::cashlessPaymentBtns7() const {
    return m_cashlessPaymentBtns7;
}

void colorconfig::setCashlessPaymentBtns7(const QString& visible) {
    if (visible == m_cashlessPaymentBtns7)
        return;

    m_cashlessPaymentBtns7 = visible;
    emit cashlessPaymentBtns7Changed();
}

QString colorconfig::cashlessPaymentBtns8() const {
    return m_cashlessPaymentBtns8;
}

void colorconfig::setCashlessPaymentBtns8(const QString& visible) {
    if (visible == m_cashlessPaymentBtns8)
        return;

    m_cashlessPaymentBtns8 = visible;
    emit cashlessPaymentBtns8Changed();
}










QString colorconfig::InitProcessingImg() const {
    return "file:/" + appdir + "images/" + m_InitProcessingImg;
}

void colorconfig::setInitProcessingImg(const QString& visible) {
    if (visible == m_InitProcessingImg)
        return;

    m_InitProcessingImg = visible;
    emit InitProcessingImgChanged();
}



QString colorconfig::InitPreFinishImg() const {
    return "file:/" + appdir + "images/" + m_InitPreFinishImg;
}

void colorconfig::setInitPreFinishImg(const QString& visible) {
    if (visible == m_InitPreFinishImg)
        return;

    m_InitPreFinishImg = visible;
    emit InitPreFinishImgChanged();
}

QString colorconfig::InitFinishImg() const {
    return "file:/" + appdir + "images/" + m_InitFinishImg;
}

void colorconfig::setInitFinishImg(const QString& visible) {
    if (visible == m_InitFinishImg)
        return;

    m_InitFinishImg = visible;
    emit InitFinishImgChanged();
}


bool colorconfig::checkParam(const std::string& option,
                             ConfigManager& cfg,
                             LogManager& logmanager,
                             std::function<void (const QString&)> setter,
                             std::function<QString ()> getter) {

    if (!cfg.rootObject()->isExist(option)) {
        logmanager.addMsg("Параметр: \"" + QString::fromStdString(option) + "\" не существует в конфигурационном файле.", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }
    if (!cfg.rootObject()->value(option)->isString()) {
        logmanager.addMsg("Некорректный тип параметра: \"" + QString::fromStdString(option) + "\". Возможно пропущен \" в начале или конце строки.", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }

    setter(QString::fromStdString(cfg.rootObject()->value(option)->toString()).toLower());
    if (!getter().contains(QRegularExpression("^#[0-9A-Fa-f]{6}$"))) {
        logmanager.addMsg("Некорректный формат параметра: \"" + QString::fromStdString(option) + "\".", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }

    return false;
}


bool colorconfig::checkParam(const std::string& option,
                             ConfigManager& cfg,
                             LogManager& logmanager,
                             std::function<void (const bool&)> setter,
                             std::function<bool ()> getter) {

    if (!cfg.rootObject()->isExist(option)) {
        logmanager.addMsg("Параметр: \"" + QString::fromStdString(option) + "\" не существует в конфигурационном файле.", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }
    if (!cfg.rootObject()->value(option)->isBool()) {
        logmanager.addMsg("Некорректный тип параметра: \"" + QString::fromStdString(option) + "\". Возможны значения true или false.", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }

    setter(cfg.rootObject()->value(option)->toBool());

    return false;
}


bool colorconfig::readConf(LogManager& logmanager) {
    ConfigManager cfg;

    QString file {appdir + FILE_PATH_CFG};

    if (!(QFileInfo::exists(file) && QFileInfo(file).isFile())) {
        logmanager.addMsg(QString("Ошибка чтения файла конфигурации: \"") + FILE_PATH_CFG + "\".", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }

    try {
        cfg.read(file.toStdString());
    }  catch (std::exception& e) {
    }

    if (checkParam("background", cfg, logmanager,
                   std::bind(&colorconfig::setBackground, this, std::placeholders::_1),
                   std::bind(&colorconfig::background, this)))
        return true;

    if (checkParam("first", cfg, logmanager,
                   std::bind(&colorconfig::setFirst, this, std::placeholders::_1),
                   std::bind(&colorconfig::first, this)))
        return true;

    if (checkParam("second", cfg, logmanager,
                   std::bind(&colorconfig::setSecond, this, std::placeholders::_1),
                   std::bind(&colorconfig::second, this)))
        return true;

    if (checkParam("third", cfg, logmanager,
                   std::bind(&colorconfig::setThird, this, std::placeholders::_1),
                   std::bind(&colorconfig::third, this)))
        return true;


    if (checkParam("fourth", cfg, logmanager,
                   std::bind(&colorconfig::setFourth, this, std::placeholders::_1),
                   std::bind(&colorconfig::fourth, this)))
        return true;

    if (checkParam("fifth", cfg, logmanager,
                   std::bind(&colorconfig::setFifth, this, std::placeholders::_1),
                   std::bind(&colorconfig::fifth, this)))
        return true;

    if (checkParam("error", cfg, logmanager,
                   std::bind(&colorconfig::setError, this, std::placeholders::_1),
                   std::bind(&colorconfig::error, this)))
        return true;

    if (checkParam("header", cfg, logmanager,
                   std::bind(&colorconfig::setHeader, this, std::placeholders::_1),
                   std::bind(&colorconfig::header, this)))
        return true;

    if (checkParam("collectionImg", cfg, logmanager,
                   std::bind(&colorconfig::setCollectionImg, this, std::placeholders::_1),
                   std::bind(&colorconfig::collectionImg, this)))
        return true;

    if (checkParam("cashlessPaymentBtns1", cfg, logmanager,
                   std::bind(&colorconfig::setCashlessPaymentBtns1, this, std::placeholders::_1),
                   std::bind(&colorconfig::cashlessPaymentBtns1, this)))
        return true;

    if (checkParam("cashlessPaymentBtns2", cfg, logmanager,
                   std::bind(&colorconfig::setCashlessPaymentBtns2, this, std::placeholders::_1),
                   std::bind(&colorconfig::cashlessPaymentBtns2, this)))
        return true;

    if (checkParam("cashlessPaymentBtns3", cfg, logmanager,
                   std::bind(&colorconfig::setCashlessPaymentBtns3, this, std::placeholders::_1),
                   std::bind(&colorconfig::cashlessPaymentBtns3, this)))
        return true;

    if (checkParam("cashlessPaymentBtns4", cfg, logmanager,
                   std::bind(&colorconfig::setCashlessPaymentBtns4, this, std::placeholders::_1),
                   std::bind(&colorconfig::cashlessPaymentBtns4, this)))
        return true;

    if (checkParam("cashlessPaymentBtns5", cfg, logmanager,
                   std::bind(&colorconfig::setCashlessPaymentBtns5, this, std::placeholders::_1),
                   std::bind(&colorconfig::cashlessPaymentBtns5, this)))
        return true;

    if (checkParam("cashlessPaymentBtns6", cfg, logmanager,
                   std::bind(&colorconfig::setCashlessPaymentBtns6, this, std::placeholders::_1),
                   std::bind(&colorconfig::cashlessPaymentBtns6, this)))
        return true;

    if (checkParam("cashlessPaymentBtns7", cfg, logmanager,
                   std::bind(&colorconfig::setCashlessPaymentBtns7, this, std::placeholders::_1),
                   std::bind(&colorconfig::cashlessPaymentBtns7, this)))
        return true;

    if (checkParam("cashlessPaymentBtns8", cfg, logmanager,
                   std::bind(&colorconfig::setCashlessPaymentBtns8, this, std::placeholders::_1),
                   std::bind(&colorconfig::cashlessPaymentBtns8, this)))
        return true;

    if (checkParam("isWalletOverlay", cfg, logmanager,
                   std::bind(&colorconfig::setIsWalletOverlay, this, std::placeholders::_1),
                   std::bind(&colorconfig::isWalletOverlay, this)))
        return true;

    if (checkParam("isButtonOverlay", cfg, logmanager,
                   std::bind(&colorconfig::setIsButtonOverlay, this, std::placeholders::_1),
                   std::bind(&colorconfig::isButtonOverlay, this)))
        return true;

    if (checkParam("isSessionOverlay", cfg, logmanager,
                   std::bind(&colorconfig::setIsSessionOverlay, this, std::placeholders::_1),
                   std::bind(&colorconfig::isSessionOverlay, this)))
        return true;

    if (checkParam("isCollectionOverlay", cfg, logmanager,
                   std::bind(&colorconfig::setIsCollectionOverlay, this, std::placeholders::_1),
                   std::bind(&colorconfig::isCollectionOverlay, this)))
        return true;

    if (checkParam("isErrorOverlay", cfg, logmanager,
                   std::bind(&colorconfig::setIsErrorOverlay, this, std::placeholders::_1),
                   std::bind(&colorconfig::isErrorOverlay, this)))
        return true;

    if (checkParam("isCashlessOverlay", cfg, logmanager,
                   std::bind(&colorconfig::setIsCashlessOverlay, this, std::placeholders::_1),
                   std::bind(&colorconfig::isCashlessOverlay, this)))
        return true;

    if (checkParam("isFooterOverlay", cfg, logmanager,
                   std::bind(&colorconfig::setIsFooterOverlay, this, std::placeholders::_1),
                   std::bind(&colorconfig::isFooterOverlay, this)))
        return true;




/*
    if (checkParam("InitProcessingImg", cfg, logmanager,
                   std::bind(&colorconfig::setInitProcessingImg, this, std::placeholders::_1),
                   std::bind(&colorconfig::InitProcessingImg, this)))
        return true;
*/
    const std::string c_InitProcessingImg { "InitProcessingImg" };
    if (!cfg.rootObject()->isExist(c_InitProcessingImg)) {
        logmanager.addMsg("Параметр: \"" + QString::fromStdString(c_InitProcessingImg) + "\" не существует в конфигурационном файле.", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }
    if (!cfg.rootObject()->value(c_InitProcessingImg)->isString()) {
        logmanager.addMsg("Некорректный тип параметра: \"" + QString::fromStdString(c_InitProcessingImg) + "\". Возможно пропущен \" в начале или конце строки.", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }
    setInitProcessingImg(QString::fromStdString(cfg.rootObject()->value(c_InitProcessingImg)->toString()).toLower());


/*
    if (checkParam("InitPreFinishImg", cfg, logmanager,
                   std::bind(&colorconfig::setInitPreFinishImg, this, std::placeholders::_1),
                   std::bind(&colorconfig::InitPreFinishImg, this)))
        return true;
*/
    const std::string c_InitPreFinishImg { "InitPreFinishImg" };
    if (!cfg.rootObject()->isExist(c_InitPreFinishImg)) {
        logmanager.addMsg("Параметр: \"" + QString::fromStdString(c_InitPreFinishImg) + "\" не существует в конфигурационном файле.", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }
    if (!cfg.rootObject()->value(c_InitPreFinishImg)->isString()) {
        logmanager.addMsg("Некорректный тип параметра: \"" + QString::fromStdString(c_InitPreFinishImg) + "\". Возможно пропущен \" в начале или конце строки.", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }
    setInitPreFinishImg(QString::fromStdString(cfg.rootObject()->value(c_InitPreFinishImg)->toString()).toLower());


/*
    if (checkParam("InitFinishImg", cfg, logmanager,
                   std::bind(&colorconfig::setInitFinishImg, this, std::placeholders::_1),
                   std::bind(&colorconfig::InitFinishImg, this)))
        return true;
*/
    const std::string c_InitFinishImg { "InitFinishImg" };
    if (!cfg.rootObject()->isExist(c_InitFinishImg)) {
        logmanager.addMsg("Параметр: \"" + QString::fromStdString(c_InitFinishImg) + "\" не существует в конфигурационном файле.", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }
    if (!cfg.rootObject()->value(c_InitFinishImg)->isString()) {
        logmanager.addMsg("Некорректный тип параметра: \"" + QString::fromStdString(c_InitFinishImg) + "\". Возможно пропущен \" в начале или конце строки.", logmanager.SYBSYS_COLORSCHEME);
        return true;
    }
    setInitFinishImg(QString::fromStdString(cfg.rootObject()->value(c_InitFinishImg)->toString()).toLower());

    return false;
}

