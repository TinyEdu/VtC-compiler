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

    using Handler = std::function<Block(const QQuickItem&, std::string)>;
    std::map<std::string, Handler> functionMap;

    // Handlers
    static Block function1(const QQuickItem& block, std::string name);
    static Block function2(const QQuickItem& block, std::string name);
};

#endif //BLOCKREADER_H
