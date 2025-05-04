#ifndef PROGRAMSERIALIZATOR_H
#define PROGRAMSERIALIZATOR_H

#include <IInterpreter.h>
#include <IParser.h>
#include <QQmlEngine>


class ProgramSerializator : public QObject {
    Q_OBJECT

public:
    static ProgramSerializator* instance();
    std::string saveToJson();

private:
    ProgramSerializator(QObject* parent) : QObject(parent) {}
    ProgramSerializator() {}
    QJsonObject readBlocks(QJsonObject root);
    QJsonObject readConnections(QJsonObject root);

    QQmlEngine* m_engine;
};



#endif //PROGRAMSERIALIZATOR_H
