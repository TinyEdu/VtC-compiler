//
// Created by nikod on 14/01/2025.
//

#ifndef MOVABLEBLOCKFACTORY_H
#define MOVABLEBLOCKFACTORY_H


#include <QObject>
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

    Q_INVOKABLE QObject* createBlock()
    {
        QObject* block = new MovableBlock();
        return block;
    };

private:
    QQmlEngine* m_engine;
};


#endif //MOVABLEBLOCKFACTORY_H
