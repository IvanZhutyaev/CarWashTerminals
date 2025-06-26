    # Определение базовых параметров проекта
QT += core gui widgets \
      qml quick \
      serialport serialbus \
      multimedia multimediawidgets \
      sql \
      quickcontrols2 \
      network networkauth \
      svg \

CONFIG += c++17

# Для отладки (убрать в релизе)
CONFIG += qml_debug

# Базовые пути
QTQRCODE_PATH = $$PWD/../qt-qrcode
CONFIGMANAGER_PATH = $$PWD/../config_manager
YOOKASSA_PATH = $$PWD/../include

# Общие пути включения для всех платформ
INCLUDEPATH += $$QTQRCODE_PATH \
               $$QTQRCODE_PATH/quickitem \
               $$QTQRCODE_PATH/include \
               $$QTQRCODE_PATH/lib \
               $$CONFIGMANAGER_PATH/build/include \
               $$YOOKASSA_PATH

# Проверка существования необходимых файлов
!exists($$QTQRCODE_PATH/quickitem/QtQrCodeQuickItem.hpp) {
    error("Qt QR Code header not found at $$QTQRCODE_PATH/quickitem/QtQrCodeQuickItem.hpp")
}

# Настройки для разных архитектур
contains(QT_ARCH, i386) {
    # 32-битная версия
    LIBS += -L"$$QTQRCODE_PATH/release-i386/lib"
}
contains(QT_ARCH, x86_64) {
    # 64-битная версия
    LIBS += -L"$$QTQRCODE_PATH/release/lib"
    #INCLUDEPATH += $$PWD/../qt-qrcode/include

}
QMAKE_MACOSX_DEPLOYMENT_TARGET = 15.0
# Специфичные настройки для MacOS
# Для MacOS
macx {
    # Явное указание пути к библиотеке
    LIBS += "$$QTQRCODE_PATH/release/lib/libqtqrcode.dylib"
    LIBS += -L/opt/homebrew/lib -lqrencode
    INCLUDEPATH += $$QTQRCODE_PATH/lib /opt/homebrew/include
    QMAKE_LFLAGS += -Wl,-rpath,$$QTQRCODE_PATH/release/lib
    QMAKE_LFLAGS += -Wl,-rpath,/opt/homebrew/lib
}

# Для других ОС
!macx {
    LIBS += -L/usr/local/lib -lqrencode
    LIBS += "/Users/temamodder/Documents/Repositories/CarWashTerminals/config_manager/build/lib/libconfigmanager.so"
    INCLUDEPATH += /usr/local/include
    QMAKE_LFLAGS += -Wl,-rpath,/usr/local/lib
}


# Исходные файлы
SOURCES += \
    accountmanager/accountmanager.cpp \
    $$QTQRCODE_PATH/quickitem/QtQrCodeQuickItem.cpp \
    controller/modbuscontroller.cpp \
    engine/configmanager.cpp \
    engine/engine.cpp \
    engine/logmanager.cpp \
    interfacecfg/colorconfig.cpp \
    main.cpp \
    pilotnt/pilotnt.cpp \
    db_manager/database_manager.cpp \
    $$QTQRCODE_PATH/lib/qtqrcode.cpp \
    $$QTQRCODE_PATH/lib/qtqrcodepainter.cpp \
    ../src/yookassa.cpp \

# Ресурсы
RESOURCES += qml.qrc

# Заголовочные файлы
HEADERS += \
    accountmanager/accountmanager.h \
    $$QTQRCODE_PATH/quickitem/QtQrCodeQuickItem.hpp \
    controller/modbuscontroller.h \
    engine/configmanager.h \
    engine/engine.h \
    engine/logmanager.h \
    errors.h \
    interfacecfg/colorconfig.h \
    pilotnt/pilotnt.h \
    db_manager/database_manager.h \
    qnetworkconfigurationmanager.h \
    ../include/yookassa.h

# QML файлы (можно оставить как было)
DISTFILES += \
    imports/IPS4MCO/Constants.qml \
    imports/IPS4MCO/qmldir \
    main.qml \
    qml/BackgroundCust.qml \
    # ... остальные qml файлы ...

# Настройки путей для QML
QML_IMPORT_PATH = $$PWD/imports
QML_DESIGNER_IMPORT_PATH =

# Правила деплоя
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Отключение deprecated API (по желанию)
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
