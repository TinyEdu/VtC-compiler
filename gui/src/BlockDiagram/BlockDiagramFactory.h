#ifndef BLOCKDIAGRAMFACTORY_H
#define BLOCKDIAGRAMFACTORY_H

#include "BlockDiagram.h"


class BlockDiagramFactory : public QObject
{
    Q_OBJECT

public:
    explicit BlockDiagramFactory(QQmlEngine* engine, QObject* parent = nullptr)
        : QObject(parent), m_engine(engine)
    {
    }

    Q_INVOKABLE QObject* newComponent(QObject* parent = nullptr)
    {
        QObject* block = new BlockDiagram(qobject_cast<QQuickItem*>(parent));
        return block;
    };

private:
    QQmlEngine* m_engine;
};


#endif //BLOCKDIAGRAMFACTORY_H
