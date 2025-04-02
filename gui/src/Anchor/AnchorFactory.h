#ifndef ANCHOR_FACTORY_H
#define ANCHOR_FACTORY_H

#include "Anchor.h"


class AnchorFactory : public QObject
{
    Q_OBJECT

public:
    explicit AnchorFactory(QQmlEngine* engine, QObject* parent = nullptr)
        : QObject(parent), m_engine(engine)
    {
    }

    Q_INVOKABLE QObject* newComponent(QObject* parent = nullptr)
    {
        QObject* block = new Anchor(qobject_cast<QQuickItem*>(parent));
        return block;
    };

private:
    QQmlEngine* m_engine;
};


#endif //ANCHOR_FACTORY_H
