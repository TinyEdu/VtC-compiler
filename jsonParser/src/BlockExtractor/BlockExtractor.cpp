#include "BlockExtractor.h"

#include "ReachedEnd.h"
#include <iostream>

std::vector<std::shared_ptr<Statement>> BlockExtractor::buildAST()
{
    auto startBlock = findStartBlock();

    std::vector<std::shared_ptr<Statement>> result = {};

    try
    {
        auto a = startBlock->buildAST(result);
    }
    catch(const ReachedEnd e)
    {
        std::cout<< "Reached end of block: " << e.what() << std::endl;
    }

    return result;
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
