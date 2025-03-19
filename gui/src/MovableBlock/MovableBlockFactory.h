#ifndef MOVABLEBLOCKFACTORY_H
#define MOVABLEBLOCKFACTORY_H

#include <QQmlEngine>
#include "MovableBlock.h"


class MovableBlockFactory : public QObject
{
    Q_OBJECT

public:
    explicit MovableBlockFactory(QQmlEngine* engine, QObject* parent = nullptr)
        : QObject(parent), m_engine(engine)
    {
    }

    Q_INVOKABLE QObject* newComponent()
    {
        QObject* block = new MovableBlock();
        return block;
    };

private:
    QQmlEngine* m_engine;
};


#endif //MOVABLEBLOCKFACTORY_H
