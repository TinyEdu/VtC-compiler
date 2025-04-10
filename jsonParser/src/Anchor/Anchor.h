#ifndef ANCHOR_H
#define ANCHOR_H

#include <string>
#include <vector>
#include <stdexcept>

class Block;

class Anchor
{
public:
    Anchor(const std::string& uuid, Block* reference);

    static Block* getNextBlock(const std::string& uuid);

private:
    static std::vector<Anchor*> anchors;

    std::string uuid;
    Block* reference;
};

#endif //ANCHOR_H
