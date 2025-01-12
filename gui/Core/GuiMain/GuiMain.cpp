#include "GuiMain.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtCore/QUrl>
#include <QtCore/QString>


using namespace Qt::StringLiterals;

int GuiMain::run(int argc, char* argv[]) {

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/gui/qmls/main.qml"_s);
    engine.load(url);

    return app.exec();
}
