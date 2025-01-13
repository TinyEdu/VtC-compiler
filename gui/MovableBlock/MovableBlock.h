#ifndef MOVABLEBLOCK_H
#define MOVABLEBLOCK_H

#include <iostream>
#include <QQuickItem>
#include <QString>

class MovableBlock : public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit MovableBlock(QQuickItem *parent = nullptr)
        : QQuickItem(parent), m_name("DefaultName")
    {
        std::cout << "he";
    }

    QString name() const { return m_name; }
    void setName(const QString &newName) {
        if (m_name != newName) {
            m_name = newName;
            emit nameChanged();
        }
    }

    signals:
        void nameChanged();

private:
    QString m_name;
};

#endif // MOVABLEBLOCK_H
