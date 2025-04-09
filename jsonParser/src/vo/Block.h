#ifndef BLOCK_H
#define BLOCK_H

#include <string>

struct Block
{
    std::string blockType;
    std::string leftAnchor;
    std::string rightAnchor;
    std::string passingAnchor;
    std::string value;
    std::string variable;
};

#endif //BLOCK_H
