#ifndef BLOCKDIAGRAM_H
#define BLOCKDIAGRAM_H

#include "BlockDiagramManager/BlockDiagramManager.h"

class BlockDiagram : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString qmlName READ qmlName CONSTANT)

public:
    explicit BlockDiagram(QQuickItem* parent = nullptr) : QQuickItem(parent)
    {
    }

    Q_INVOKABLE void Associate(QObject* qml)
    {
        qml_obj = qobject_cast<QQuickItem*>(qml);
        BlockDiagramManager::instance()->registerBlockDiagram(qml_obj);
    }

    Q_INVOKABLE void Disassociate(QObject* qml)
    {
        qml_obj = qobject_cast<QQuickItem*>(qml);
        BlockDiagramManager::instance()->unregisterBlockDiagram(qml_obj);
    }

    QString qmlName() const { return m_qmlName; }

private:
    QQuickItem* qml_obj;
    const QString m_qmlName = QString("BlockDiagram.qml");
};

#endif // BLOCKDIAGRAM_H
