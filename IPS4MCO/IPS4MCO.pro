QT += qml quick serialport serialbus multimedia multimediawidgets

CONFIG += c++14

#for debug TODO: Remove!
CONFIG+=qml_debug

contains(QT_ARCH, i386) {
    # inclue lib for generate qr code x32
    INCLUDEPATH += ../qt-qrcode/lib
    LIBS += -L"../qt-qrcode/release-i386/lib" -lqtqrcode
    SOURCES += ../qt-qrcode/quickitem/QtQrCodeQuickItem.cpp
    HEADERS += ../qt-qrcode/quickitem/QtQrCodeQuickItem.hpp
}
contains(QT_ARCH, x86_64) {
    # inclue lib for generate qr code x64
    INCLUDEPATH += ../qt-qrcode/lib
    LIBS += -L"../qt-qrcode/release/lib" -lqtqrcode
    SOURCES += ../qt-qrcode/quickitem/QtQrCodeQuickItem.cpp
    HEADERS += ../qt-qrcode/quickitem/QtQrCodeQuickItem.hpp
}

#include config_manager library
INCLUDEPATH += ../config_manager/build/include
LIBS += -L"../config_manager/build/lib" -lconfigmanager


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        controller/modbuscontroller.cpp \
    engine/configmanager.cpp \
        engine/engine.cpp \
    engine/logmanager.cpp \
    interfacecfg/colorconfig.cpp \
        main.cpp \
    pilotnt/pilotnt.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD/imports


# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    controller/modbuscontroller.h \
    engine/configmanager.h \
    engine/engine.h \
    engine/logmanager.h \
    errors.h \
    interfacecfg/colorconfig.h \
    pilotnt/pilotnt.h

DISTFILES += \
    imports/IPS4MCO/Constants.qml \
    imports/IPS4MCO/qmldir \
    main.qml \
    qml/BackgroundCust.qml \
    qml/BackgroundCustForm.ui.qml \
    qml/CashlessPayment.qml \
    qml/CashlessPaymentButtons.qml \
    qml/CashlessPaymentButtonsForm.ui.qml \
    qml/CashlessPaymentForm.ui.qml \
    qml/CashlessPaymentStatus.qml \
    qml/CashlessPaymentStatusForm.ui.qml \
    qml/Collection.qml \
    qml/CollectionForm.ui.qml \
    qml/Error.qml \
    qml/ErrorForm.ui.qml \
    qml/ErrorStatic.qml \
    qml/ErrorStaticForm.ui.qml \
    qml/Footer.qml \
    qml/FooterForm.ui.qml \
    qml/Header.qml \
    qml/HeaderForm.ui.qml \
    qml/Initialization.qml \
    qml/InitializationForm.ui.qml \
    qml/PauseButton.qml \
    qml/PauseButtonForm.ui.qml \
    qml/ProgButton.qml \
    qml/ProgButtonForm.ui.qml \
    qml/QR.qml \
    qml/QRForm.ui.qml \
    qml/QRGenerating.ui.qml \
    qml/Session.qml \
    qml/SessionForm.ui.qml \
    qml/Waiting.qml \
    qml/WaitingForm.ui.qml \
    qml/Wallet.qml \
    qml/WalletForm.ui.qml \
    qml/payment/BackgroundCust.qml \
    qml/payment/BackgroundCustForm.ui.qml \
    qml/payment/CashlessPayment.qml \
    qml/payment/CashlessPaymentButtons.qml \
    qml/payment/CashlessPaymentButtonsForm.ui.qml \
    qml/payment/CashlessPaymentForm.ui.qml \
    qml/payment/CashlessPaymentStatus.qml \
    qml/payment/CashlessPaymentStatusForm.ui.qml \
    qml/payment/Collection.qml \
    qml/payment/CollectionForm.ui.qml \
    qml/payment/Error.qml \
    qml/payment/ErrorForm.ui.qml \
    qml/payment/ErrorStatic.qml \
    qml/payment/ErrorStaticForm.ui.qml \
    qml/payment/Footer.qml \
    qml/payment/FooterForm.ui.qml \
    qml/payment/Header.qml \
    qml/payment/HeaderForm.ui.qml \
    qml/payment/Initialization.qml \
    qml/payment/InitializationForm.ui.qml \
    qml/payment/PauseButton.qml \
    qml/payment/PauseButtonForm.ui.qml \
    qml/payment/PauseButton_back.zip \
    qml/payment/ProgButton.qml \
    qml/payment/ProgButtonForm.ui.qml \
    qml/payment/QR.qml \
    qml/payment/QRForm.ui.qml \
    qml/payment/QRGenerating.ui.qml \
    qml/payment/Session.qml \
    qml/payment/SessionForm.ui.qml \
    qml/payment/Waiting.qml \
    qml/payment/WaitingForm.ui.qml \
    qml/payment/Wallet.qml \
    qml/payment/WalletForm.ui.qml \
    qml/single/Balance.qml \
    qml/single/BalanceForm.ui.qml \
    qml/single/Error.qml \
    qml/single/ErrorForm.ui.qml \
    qml/single/GradientBorder.qml \
    qml/single/GradientBorderForm.ui.qml \
    qml/single/Initialization.qml \
    qml/single/InitializationForm.ui.qml \
    qml/single/PauseButton.qml \
    qml/single/PauseButtonForm.ui.qml \
    qml/single/ProgramButton.qml \
    qml/single/ProgramButtonForm.ui.qml \
    qml/single/Session.qml \
    qml/single/SessionForm.ui.qml \
    qml/single/Voiceover.qml
