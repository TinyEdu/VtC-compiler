#ifndef BLOCKDIAGRAMMANAGER_H
#define BLOCKDIAGRAMMANAGER_H

#include <QQuickItem>
#include <QPointer>
#include <QList>

class BlockDiagramManager : public QObject
{
    Q_OBJECT

public:
    static BlockDiagramManager* instance();
    void registerBlockDiagram(QQuickItem* block);
    void unregisterBlockDiagram(QQuickItem* block);

    Q_INVOKABLE QQuickItem* checkCollision(QQuickItem* movable);
    Q_INVOKABLE QQuickItem* isOverAnAnchor(int x, int y, QQuickItem* excludeItem);

private:
    explicit BlockDiagramManager(QObject* parent = nullptr);

    bool isColliding(QQuickItem* a, QQuickItem* b);
    bool isColliding(int x, int y, QQuickItem* b);

    QList<QPointer<QQuickItem>> m_blocks;
};

#endif // BLOCKDIAGRAMMANAGER_H
