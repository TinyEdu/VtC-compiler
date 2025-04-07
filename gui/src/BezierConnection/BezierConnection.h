#ifndef BEZIERCONNECTION_H
#define BEZIERCONNECTION_H

#include "BezierConnectionManager.h"

class BezierConnection : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString qmlName READ qmlName CONSTANT)

public:
    explicit BezierConnection(QQuickItem* parent = nullptr) : QQuickItem(parent)
    {
    }

    Q_INVOKABLE void Associate(QObject* qml)
    {
        qml_obj = qobject_cast<QQuickItem*>(qml);
        BezierConnectionManager::instance()->registerBezierConnection(qml_obj);
    }

    QString qmlName() const { return m_qmlName; }

private:
    QString m_type;
    QQuickItem* qml_obj;
    const QString m_qmlName = QString("BezierConnection.qml");
};

#endif // BEZIERCONNECTION_H
