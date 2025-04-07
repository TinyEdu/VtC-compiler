#ifndef BEZIERCONNECTIONFACTORY_H
#define BEZIERCONNECTIONFACTORY_H

#include "BezierConnection.h"


class BezierConnectionFactory : public QObject
{
    Q_OBJECT

public:
    explicit BezierConnectionFactory(QQmlEngine* engine, QObject* parent = nullptr)
        : QObject(parent), m_engine(engine)
    {
    }

    Q_INVOKABLE QObject* newComponent(QObject* parent = nullptr)
    {
        QObject* block = new BezierConnection(qobject_cast<QQuickItem*>(parent));
        return block;
    };

private:
    QQmlEngine* m_engine;
};


#endif //BEZIERCONNECTIONFACTORY_H
