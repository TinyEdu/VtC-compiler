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

    // Register MovableBlock with QML
    // qmlRegisterType<MovableBlock>("qrc:/gui/qmls/MovableBlock.qml", 1, 0, "ABC_ABC_ABC");
    qmlRegisterType<MovableBlock>("CustomControls", 1, 0, "MovableBlock");

    engine.load(QUrl(QStringLiteral("qrc:/gui/qmls/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
