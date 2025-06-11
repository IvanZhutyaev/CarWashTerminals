#ifndef COLORCONFIG_H
#define COLORCONFIG_H

#include <QObject>
#include <QString>
#include <functional>
#include <QFileInfo>

#include "configmanager.h"
#include "engine/logmanager.h"


#define FILE_PATH_CFG "config/color_scheme.conf"

class colorconfig : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString background READ background WRITE setBackground NOTIFY backgroundChanged)
    Q_PROPERTY(QString first READ first WRITE setFirst NOTIFY firstChanged)
    Q_PROPERTY(QString second READ second WRITE setSecond NOTIFY secondChanged)
    Q_PROPERTY(QString third READ third WRITE setThird NOTIFY thirdChanged)
    Q_PROPERTY(QString fourth READ fourth WRITE setFourth NOTIFY fourthChanged)
    Q_PROPERTY(QString fifth READ fifth WRITE setFifth NOTIFY fifthChanged)

    Q_PROPERTY(QString error READ error WRITE setError NOTIFY errorChanged)
    Q_PROPERTY(QString header READ header WRITE setHeader NOTIFY headerChanged)
    Q_PROPERTY(QString collectionImg READ collectionImg WRITE setCollectionImg NOTIFY collectionImgChanged)


    Q_PROPERTY(QString cashlessPaymentBtns1 READ cashlessPaymentBtns1 WRITE setCashlessPaymentBtns1 NOTIFY cashlessPaymentBtns1Changed)
    Q_PROPERTY(QString cashlessPaymentBtns2 READ cashlessPaymentBtns2 WRITE setCashlessPaymentBtns2 NOTIFY cashlessPaymentBtns2Changed)
    Q_PROPERTY(QString cashlessPaymentBtns3 READ cashlessPaymentBtns3 WRITE setCashlessPaymentBtns3 NOTIFY cashlessPaymentBtns3Changed)
    Q_PROPERTY(QString cashlessPaymentBtns4 READ cashlessPaymentBtns4 WRITE setCashlessPaymentBtns4 NOTIFY cashlessPaymentBtns4Changed)
    Q_PROPERTY(QString cashlessPaymentBtns5 READ cashlessPaymentBtns5 WRITE setCashlessPaymentBtns5 NOTIFY cashlessPaymentBtns5Changed)
    Q_PROPERTY(QString cashlessPaymentBtns6 READ cashlessPaymentBtns6 WRITE setCashlessPaymentBtns6 NOTIFY cashlessPaymentBtns6Changed)
    Q_PROPERTY(QString cashlessPaymentBtns7 READ cashlessPaymentBtns7 WRITE setCashlessPaymentBtns7 NOTIFY cashlessPaymentBtns7Changed)
    Q_PROPERTY(QString cashlessPaymentBtns8 READ cashlessPaymentBtns8 WRITE setCashlessPaymentBtns8 NOTIFY cashlessPaymentBtns8Changed)



    Q_PROPERTY(bool isWalletOverlay READ isWalletOverlay WRITE setIsWalletOverlay NOTIFY isWalletOverlayChanged)
    Q_PROPERTY(bool isButtonOverlay READ isButtonOverlay WRITE setIsButtonOverlay NOTIFY isButtonOverlayChanged)
    Q_PROPERTY(bool isSessionOverlay READ isSessionOverlay WRITE setIsSessionOverlay NOTIFY isSessionOverlayChanged)
    Q_PROPERTY(bool isCollectionOverlay READ isCollectionOverlay WRITE setIsCollectionOverlay NOTIFY isCollectionOverlayChanged)
    Q_PROPERTY(bool isErrorOverlay READ isErrorOverlay WRITE setIsErrorOverlay NOTIFY isErrorOverlayChanged)
    Q_PROPERTY(bool isCashlessOverlay READ isCashlessOverlay WRITE setIsCashlessOverlay NOTIFY isCashlessOverlayChanged)
    Q_PROPERTY(bool isFooterOverlay READ isFooterOverlay WRITE setIsFooterOverlay NOTIFY isFooterOverlayChanged)


    Q_PROPERTY(QString InitProcessingImg READ InitProcessingImg WRITE setInitProcessingImg NOTIFY InitProcessingImgChanged)
    Q_PROPERTY(QString InitPreFinishImg READ InitPreFinishImg WRITE setInitPreFinishImg NOTIFY InitPreFinishImgChanged)
    Q_PROPERTY(QString InitFinishImg READ InitFinishImg WRITE setInitFinishImg NOTIFY InitFinishImgChanged)


public:
    explicit colorconfig(const QString& appdir, QObject *parent = nullptr);


    QString background() const;
    void setBackground(const QString& color);

    QString first() const;
    void setFirst(const QString& color);

    QString second() const;
    void setSecond(const QString& color);

    QString third() const;
    void setThird(const QString& color);

    QString fourth() const;
    void setFourth(const QString& color);

    QString fifth() const;
    void setFifth(const QString& color);



    QString error() const;
    void setError(const QString& color);

    QString header() const;
    void setHeader(const QString& color);

    QString collectionImg() const;
    void setCollectionImg(const QString& color);



    QString cashlessPaymentBtns1() const;
    void setCashlessPaymentBtns1(const QString& color);

    QString cashlessPaymentBtns2() const;
    void setCashlessPaymentBtns2(const QString& color);

    QString cashlessPaymentBtns3() const;
    void setCashlessPaymentBtns3(const QString& color);

    QString cashlessPaymentBtns4() const;
    void setCashlessPaymentBtns4(const QString& color);

    QString cashlessPaymentBtns5() const;
    void setCashlessPaymentBtns5(const QString& color);

    QString cashlessPaymentBtns6() const;
    void setCashlessPaymentBtns6(const QString& color);

    QString cashlessPaymentBtns7() const;
    void setCashlessPaymentBtns7(const QString& color);

    QString cashlessPaymentBtns8() const;
    void setCashlessPaymentBtns8(const QString& color);





    bool isWalletOverlay() const;
    void setIsWalletOverlay(const bool& visible);


    bool isButtonOverlay() const;
    void setIsButtonOverlay(const bool& visible);

    bool isSessionOverlay() const;
    void setIsSessionOverlay(const bool& visible);

    bool isCollectionOverlay() const;
    void setIsCollectionOverlay(const bool& visible);

    bool isErrorOverlay() const;
    void setIsErrorOverlay(const bool& visible);

    bool isCashlessOverlay() const;
    void setIsCashlessOverlay(const bool& visible);

    bool isFooterOverlay() const;
    void setIsFooterOverlay(const bool& visible);



    QString InitProcessingImg() const;
    void setInitProcessingImg(const QString& visible);

    QString InitPreFinishImg() const;
    void setInitPreFinishImg(const QString& visible);

    QString InitFinishImg() const;
    void setInitFinishImg(const QString& visible);


    bool readConf(LogManager& logmanager);

signals:
    void backgroundChanged();
    void firstChanged();
    void secondChanged();
    void thirdChanged();
    void fourthChanged();
    void fifthChanged();

    void errorChanged();
    void headerChanged();
    void collectionImgChanged();


    void cashlessPaymentBtns1Changed();
    void cashlessPaymentBtns2Changed();
    void cashlessPaymentBtns3Changed();
    void cashlessPaymentBtns4Changed();
    void cashlessPaymentBtns5Changed();
    void cashlessPaymentBtns6Changed();
    void cashlessPaymentBtns7Changed();
    void cashlessPaymentBtns8Changed();


    void isWalletOverlayChanged();
    void isButtonOverlayChanged();
    void isSessionOverlayChanged();
    void isCollectionOverlayChanged();
    void isErrorOverlayChanged();
    void isCashlessOverlayChanged();
    void isFooterOverlayChanged();



    void InitProcessingImgChanged();
    void InitPreFinishImgChanged();
    void InitFinishImgChanged();


    void isError(bool error);
private:
    QString appdir;


    QString m_background { "#fdfdfd" };


    QString m_first { "#0087c6" };
    QString m_second { "#0bb232" };
    QString m_third { "#f4720c" };
    QString m_fourth { "#ffffff" };
    QString m_fifth { "#838384" };

    QString m_error { "#db030c" };
    QString m_header { "#000000" };
    QString m_collectionImg { "#7c35c1" };



    QString m_cashlessPaymentBtns1 { "#ffffff" };
    QString m_cashlessPaymentBtns2 { "#0088c6" };
    QString m_cashlessPaymentBtns3 { "#007cb5" };
    QString m_cashlessPaymentBtns4 { "#e46a07" };
    QString m_cashlessPaymentBtns5 { "#fe7709" };
    QString m_cashlessPaymentBtns6 { "#9b9b9b" };
    QString m_cashlessPaymentBtns7 { "#b3b3b3" };
    QString m_cashlessPaymentBtns8 { "#c8c8c8" };


    bool m_isWalletOverlay { false };
    bool m_isButtonOverlay { false };
    bool m_isSessionOverlay { false };
    bool m_isCollectionOverlay { false };
    bool m_isErrorOverlay { false };
    bool m_isCashlessOverlay { true };
    bool m_isFooterOverlay { false };


    QString m_InitProcessingImg { "init.gif" };
    QString m_InitPreFinishImg { "init_prefinish.gif" };
    QString m_InitFinishImg { "init_finish.gif" };


    bool checkParam(const std::string& option,
                    ConfigManager& cfg,
                    LogManager& logmanager,
                    std::function<void (const QString&)> setter,
                    std::function<QString ()> getter);

    bool checkParam(const std::string& option,
                    ConfigManager& cfg,
                    LogManager& logmanager,
                    std::function<void (const bool&)> setter,
                    std::function<bool ()> getter);

};

#endif // COLORCONFIG_H
