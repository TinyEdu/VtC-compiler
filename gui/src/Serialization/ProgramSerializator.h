#ifndef PROGRAMSERIALIZATOR_H
#define PROGRAMSERIALIZATOR_H

#include <IParser.h>
#include <QQmlEngine>


class ProgramSerializator : public QObject {
    Q_OBJECT

public:
    static ProgramSerializator* instance();

    explicit ProgramSerializator(QQmlEngine* engine, QObject* parent = nullptr)
    : QObject(parent), m_engine(engine)
    {
    }

    Q_INVOKABLE void save();
    Q_INVOKABLE void load();

    std::shared_ptr<vtc::parser::IParser> parser;
private:
    ProgramSerializator(QObject* parent) : QObject(parent) {}
    ProgramSerializator() {}
    QJsonObject readBlocks(QJsonObject root);
    QJsonObject readConnections(QJsonObject root);

    QQmlEngine* m_engine;
};



#endif //PROGRAMSERIALIZATOR_H
