#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQuickControls2/QQuickStyle>
#include <QtQuick/QQuickView>

#include "engine/engine.h"
#include "accountmanager/accountmanager.h"
#include "yookassa.h"
#include "qrcodeprovider.h"

#include "QtQrCode"
#include "../qt-qrcode/quickitem/QtQrCodeQuickItem.hpp"


int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");

    /*QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    paths.append("sqldrivers");
    QCoreApplication::setLibraryPaths(paths);
    */
    QtQrCodeQuickItem::registerQmlTypes();


    QString appdir = QGuiApplication::applicationDirPath();
    #ifdef __linux__
        appdir = appdir + "/../";
    #elif _WIN32
        appdir = appdir + "/../../";
    #endif

    LogManager logManager(appdir + FILE_PATH_LOG);
    Engine engine_backend(appdir, &logManager);

    // Регистрируем провайдер QR-кодов
    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("qr"), new QRCodeProvider());

    // Создаем и настраиваем экземпляр YooKassa
    YooKassa yooKassa;
    yooKassa.setShopId("1031378");
    yooKassa.setSecretKey("test_x-b5O6tQsP2nz0zDoZ5YKCWo9XbPzUIvRH9vkAeCvoc");

    engine.rootContext()->setContextProperty("backend", &engine_backend);
    engine.rootContext()->setContextProperty("applicationDirPath", appdir);
    engine.rootContext()->setContextProperty("accountManager", engine_backend.accountManager());
    engine.rootContext()->setContextProperty("yooKassa", &yooKassa);
    engine.addImportPath(":/imports");


    qApp->setOverrideCursor(QCursor( Qt::BlankCursor ));
    if (argc > 1) {
        qDebug() << "argv: " << argv[1];
        if (QVariant(argv[1]).toString() == "-c")
            qApp->setOverrideCursor(QCursor( Qt::ArrowCursor));
    }


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    QObject *item = engine.rootObjects().at(0);
    QObject::connect(item, SIGNAL(qmlSetButtons(int)),
                     &engine_backend, SLOT(cppSetButtons(int)));

    QObject::connect(item, SIGNAL(qmlClerButtonStateQr()),
                     &engine_backend, SLOT(cppClerButtonStateQr()));
    QObject::connect(item, SIGNAL(qmlClerButtonStateWallet()),
                     &engine_backend, SLOT(cppClerButtonStateWallet()));

    QObject::connect(item, SIGNAL(qmlSendPayment(int, int)),
                     &engine_backend, SLOT(cppSendPayment(int,int)));


    engine_backend.initEvent();

    return app.exec();
}
