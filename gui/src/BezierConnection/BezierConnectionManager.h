#ifndef BEZIERCONNECTIONMANAGER_H
#define BEZIERCONNECTIONMANAGER_H

#include <QQuickItem>
#include <QPointer>
#include <QList>

class BezierConnectionManager : public QObject
{
    Q_OBJECT

public:
    static BezierConnectionManager* instance();
    void registerBezierConnection(QQuickItem* block);
    void unregisterBezierConnection(QQuickItem* block);

    QList<QPointer<QQuickItem>> getBlocks() const { return m_connections; }
private:
    explicit BezierConnectionManager(QObject* parent = nullptr);

    QList<QPointer<QQuickItem>> m_connections;
};

#endif // BEZIERCONNECTIONMANAGER_H
