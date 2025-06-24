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
    LIBS += -L"$$QTQRCODE_PATH/release-i386/lib" -lqtqrcode
}
contains(QT_ARCH, x86_64) {
    # 64-битная версия
    LIBS += -L"$$QTQRCODE_PATH/release/lib" -lqtqrcode -llibqrencode
    #INCLUDEPATH += $$PWD/../qt-qrcode/include

}

# Специфичные настройки для MacOS
# Для MacOS
macx {
    LIBS += "/Users/temamodder/Documents/Repositories/CarWashTerminals/config_manager/build/lib/libconfigmanager.dylib"

    QMAKE_LFLAGS += -Wl,-rpath,$$PWD/../config_manager/build/lib
}

# Для других ОС
!macx {
    LIBS += "/Users/temamodder/Documents/Repositories/CarWashTerminals/config_manager/build/lib/libconfigmanager.so"
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
    accountmanager/accountmanager.cpp \
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
