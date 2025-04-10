#ifndef BLOCKEXTRACTOR_H
#define BLOCKEXTRACTOR_H

#include <memory>
#include <vector>

#include "../vo/Block.h"
#include "../vo/Connection.h"
#include "Statements/Statement.h"

class BlockExtractor {
public:
    BlockExtractor(std::vector<std::shared_ptr<Block>> blocks, std::vector<Connection> connections)
        : blocks(std::move(blocks)), connections(std::move(connections)) {}

    std::vector<std::shared_ptr<Statement>> buildAST();

private:
    std::vector<std::shared_ptr<Block>> blocks;
    std::vector<Connection> connections;

    Block* findNodeWithName(std::string name);
    Block* findConnectedBlock(const std::string& anchor);
    Block* findEndBlock();
    Block* findStartBlock();
};

#endif //BLOCKEXTRACTOR_H
