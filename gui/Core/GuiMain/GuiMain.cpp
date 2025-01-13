#include "GuiMain.h"

#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <QtCore/QUrl>
#include <QtCore/QString>

#include "MovableBlock/MovableBlock.h"


using namespace Qt::StringLiterals;

int GuiMain::run(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<MovableBlock>("com.example.movableblock", 1, 0, "MovableBlock");


    auto url1 = QUrl(QStringLiteral("qrc:/qt/qml/cpp/MovableBlock/gui/qmls/MovableBlock.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url1](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url1 == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);
    engine.load(url1);


    auto url2 = QUrl(QStringLiteral("qrc:/qt/qml/cpp/MovableBlock/gui/qmls/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url2](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url2 == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);
    engine.load(url2);


    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
