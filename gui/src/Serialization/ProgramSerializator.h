#ifndef PROGRAMSERIALIZATOR_H
#define PROGRAMSERIALIZATOR_H

#include <QQmlEngine>


class ProgramSerializator : public QObject {
    Q_OBJECT

public:
    explicit ProgramSerializator(QQmlEngine* engine, QObject* parent = nullptr)
    : QObject(parent), m_engine(engine)
    {
    }

    Q_INVOKABLE void save();
    Q_INVOKABLE void load();

private:
    QJsonObject readBlocks(QJsonObject root);
    QJsonObject readConnections(QJsonObject root);

    QQmlEngine* m_engine;
};



#endif //PROGRAMSERIALIZATOR_H
