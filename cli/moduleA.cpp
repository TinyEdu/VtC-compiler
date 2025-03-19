#include "moduleA.h"
#include <iostream>
#include <qstringliteral.h>
#include <qurl.h>

ModuleA::ModuleA() = default;

void ModuleA::doSomething()
{
    std::cout << "HEJ" << std::endl;
    auto url = QUrl(QStringLiteral("qrc:main.qml"));
}
