#include "BlockExtractor.h"

std::vector<std::shared_ptr<Statement>> BlockExtractor::buildAST()
{
    auto startBlock = BlockExtractor::findStartBlock();
    return {};
}

Block* BlockExtractor::findNodeWithName(std::string name)
{
    return nullptr;
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
