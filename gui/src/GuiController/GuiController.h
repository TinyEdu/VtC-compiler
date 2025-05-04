#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <QObject>

#include "IInterpreter.h"
#include "IParser.h"

class QQmlEngine;

class GuiController : public QObject {
    Q_OBJECT

public:
    GuiController(std::shared_ptr<vtc::parser::IParser> parser,
        std::shared_ptr<vtc::interpreter::IInterpreter> interpreter)
    {
        this->parser = std::move(parser);
        this->interpreter = std::move(interpreter);
    }

    Q_INVOKABLE void save();
    Q_INVOKABLE QString run();
    Q_INVOKABLE void load() {}
    Q_INVOKABLE void center() {}

private:
    std::shared_ptr<vtc::parser::IParser> parser;
    std::shared_ptr<vtc::interpreter::IInterpreter> interpreter;
};

#endif //GUICONTROLLER_H