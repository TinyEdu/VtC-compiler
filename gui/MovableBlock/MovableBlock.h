#ifndef MOVABLEBLOCK_H
#define MOVABLEBLOCK_H

#include <QQuickItem>
#include <QString>
#include <QDebug>
#include "Collision/CollisionManager.h"


class MovableBlock : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString qmlName READ qmlName CONSTANT)
    Q_PROPERTY(qreal initialX READ initialX WRITE setInitialX NOTIFY initialXChanged)
    Q_PROPERTY(qreal initialY READ initialY WRITE setInitialY NOTIFY initialYChanged)

public:
    explicit MovableBlock(QQuickItem* parent = nullptr)
        : QQuickItem(parent)
    {
    }

    QString qmlName() const { return m_qmlName; }

    qreal initialX() const { return m_initialX; }

    void setInitialX(qreal x)
    {
        if (m_initialX != x)
        {
            m_initialX = x;
            emit initialXChanged();
        }
    }

    qreal initialY() const { return m_initialY; }

    void setInitialY(qreal y)
    {
        if (m_initialY != y)
        {
            m_initialY = y;
            emit initialYChanged();
        }
    }

    Q_INVOKABLE void ReleasedMouse()
    {
        qDebug() << "Mouse released on MovableBlock!";

        QObject const* collidedAnchor = CollisionManager::instance()->checkCollision(this);
        if (collidedAnchor)
        {
            // Align to the collided anchor's position
            setX(collidedAnchor->property("x").toReal());
            setY(collidedAnchor->property("y").toReal());
        }
        else
        {
            // Revert to initial position
            setX(m_initialX);
            setY(m_initialY);
        }
    }

signals:
    void initialXChanged();
    void initialYChanged();

private:
    const QString m_qmlName = QString("MovableBlock.qml");
    qreal m_initialX = 0;
    qreal m_initialY = 0;
};

#endif // MOVABLEBLOCK_H
