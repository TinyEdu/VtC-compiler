#include "BlockExtractor.h"

#include <iostream>

std::vector<std::shared_ptr<Statement>> BlockExtractor::buildAST()
{
    auto startBlock = BlockExtractor::findStartBlock();

    std::cout << "startBlock:" << startBlock->buildAST()<< std::endl;
    return {};
}

Block* BlockExtractor::findNodeWithName(std::string name)
{
    for (auto& block : blocks)
    {
        if (block->name == name)
        {
            return block.get();
        }
    }

    throw std::runtime_error("Block with name " + name + " not found");
}

Block* BlockExtractor::findStartBlock()
{
    return findNodeWithName("Start");
}

Block* BlockExtractor::findEndBlock()
{
    return findNodeWithName("End");
}

Block* BlockExtractor::findConnectedBlock(const std::string& anchor)
{
    return nullptr;
}
