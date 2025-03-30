#ifndef BLOCKREADER_H
#define BLOCKREADER_H

#include <QQuickItem>
#include "Blocks/Block.h"


class BlockReader
{
public:
    BlockReader();
    Block* extract(QQuickItem* block) const;

private:
    Block* extract(QQuickItem* block, const QString& name) const;
    void initializeHandlerRegister();

    static QString readChildProperty(QQuickItem* block, QString childName, QString propertyName);
    static QString readProperty(QQuickItem* block, QString propertyName)
    static QUuid emptyQUuid();

    using Handler = std::function<Block*(QQuickItem*, QString)>;
    std::map<QString, Handler> functionMap;

    // Handlers
    static Block* BuildBreak(QQuickItem* block, QString name);
    static Block* BuildCall(QQuickItem* block, QString name);
    static Block* BuildCreateVar(QQuickItem* block, QString name);
    static Block* BuildEnd(QQuickItem* block, QString name);
    static Block* BuildForLoop(QQuickItem* block, QString name);
    static Block* BuildGetVar(QQuickItem* block, QString name);
    static Block* BuildIf(QQuickItem* block, QString name);
    static Block* BuildListen(QQuickItem* block, QString name);
    static Block* BuildPrint(QQuickItem* block, QString name);
    static Block* BuildSetVar(QQuickItem* block, QString name);
    static Block* BuildSkip(QQuickItem* block, QString name);
    static Block* BuildStart(QQuickItem* block, QString name);
    static Block* BuildValue(QQuickItem* block, QString name);
    static Block* BuildWhile(QQuickItem* block, QString name);
    static Block* BuildBinaryOp(QQuickItem* block, QString name);
    static Block* BuildUnaryOp(QQuickItem* block, QString name);
};

#endif //BLOCKREADER_H
