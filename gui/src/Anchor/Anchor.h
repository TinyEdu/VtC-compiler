#ifndef ANCHOR_H
#define ANCHOR_H

#include "Collision/CollisionManager.h"

class Anchor : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString qmlName READ qmlName CONSTANT)

public:
    explicit Anchor(QQuickItem* parent = nullptr) : QQuickItem(parent)
    {
    }

    Q_INVOKABLE void Associate(QObject* qml, const QString& type)
    {
        if(type != "anchor" && type != "data")
        {
            throw std::invalid_argument("Invalid type (anchor | data).");
        }

        m_type = type;

        qml_obj = qobject_cast<QQuickItem*>(qml);
        CollisionManager::instance()->registerAnchor(qml_obj);
    }

    QString qmlName() const { return m_qmlName; }

private:
    QString m_type;
    QQuickItem* qml_obj;
    const QString m_qmlName = QString("Anchor.qml");
};

#endif // ANCHOR_H
