#ifndef BLOCKREADER_H
#define BLOCKREADER_H

#include <QQuickItem>
#include "Blocks/Block.h"


class BlockReader
{
public:
    BlockReader();
    Block* extract(const QQuickItem& block) const;

private:
    Block* extract(const QQuickItem& block, const std::string& name) const;
    void initializeHandlerRegister();

    using Handler = std::function<Block*(const QQuickItem&, std::string)>;
    std::map<std::string, Handler> functionMap;

    // Handlers
    static Block* BuildBreak(const QQuickItem& block, std::string name);
    static Block* BuildCall(const QQuickItem& block, std::string name);
    static Block* BuildCreateVar(const QQuickItem& block, std::string name);
    static Block* BuildEnd(const QQuickItem& block, std::string name);
    static Block* BuildForLoop(const QQuickItem& block, std::string name);
    static Block* BuildGetVar(const QQuickItem& block, std::string name);
    static Block* BuildIf(const QQuickItem& block, std::string name);
    static Block* BuildListen(const QQuickItem& block, std::string name);
    static Block* BuildPrint(const QQuickItem& block, std::string name);
    static Block* BuildSetVar(const QQuickItem& block, std::string name);
    static Block* BuildSkip(const QQuickItem& block, std::string name);
    static Block* BuildStart(const QQuickItem& block, std::string name);
    static Block* BuildVar(const QQuickItem& block, std::string name);
    static Block* BuildWhile(const QQuickItem& block, std::string name);
    static Block* BuildBinaryOp(const QQuickItem& block, std::string name);
    static Block* BuildUnaryOp(const QQuickItem& block, std::string name);
};

#endif //BLOCKREADER_H
