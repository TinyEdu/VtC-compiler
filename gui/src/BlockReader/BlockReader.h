#ifndef BLOCKREADER_H
#define BLOCKREADER_H

#include <QQuickItem>
#include "Blocks/Block.h"


class BlockReader
{
public:
    BlockReader();
    Block extract(const QQuickItem& block) const;

private:
    Block extract(const QQuickItem& block, const std::string& name) const;
    void initializeHandlerRegister();

    using Handler = std::function<Block(const QQuickItem&, std::string)>;
    std::map<std::string, Handler> functionMap;

    // Handlers
    static Block Break(const QQuickItem& block, std::string name);
    static Block Call(const QQuickItem& block, std::string name);
    static Block CreateVar(const QQuickItem& block, std::string name);
    static Block End(const QQuickItem& block, std::string name);
    static Block ForLoop(const QQuickItem& block, std::string name);
    static Block GetVar(const QQuickItem& block, std::string name);
    static Block If(const QQuickItem& block, std::string name);
    static Block Listen(const QQuickItem& block, std::string name);
    static Block Print(const QQuickItem& block, std::string name);
    static Block SetVar(const QQuickItem& block, std::string name);
    static Block Skip(const QQuickItem& block, std::string name);
    static Block Start(const QQuickItem& block, std::string name);
    static Block Var(const QQuickItem& block, std::string name);
    static Block While(const QQuickItem& block, std::string name);
    static Block BinaryOp(const QQuickItem& block, std::string name);
    static Block UnaryOp(const QQuickItem& block, std::string name);
};

#endif //BLOCKREADER_H
