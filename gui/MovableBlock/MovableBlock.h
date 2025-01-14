#ifndef MOVABLEBLOCK_H
#define MOVABLEBLOCK_H

#include <iostream>
#include <QQuickItem>
#include <QString>


class MovableBlock : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString qmlName READ qmlName CONSTANT)
public:
    explicit MovableBlock(QQuickItem* parent = nullptr)
        : QQuickItem(parent), m_name("DefaultName")
    {
        std::cout << "hej tu MovableBlock";
    }

    QString name() const { return m_name; }

    void setName(const QString& newName)
    {
        if (m_name != newName)
        {
            m_name = newName;
            emit nameChanged();
        }
    }

    QString qmlName() const { return m_qmlName; }
signals:
    void nameChanged();

private:
    const QString m_qmlName = "MovableBlock.qml";
    QString m_name;
};
#endif // MOVABLEBLOCK_H
