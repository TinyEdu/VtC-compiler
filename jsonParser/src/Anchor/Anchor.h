#ifndef ANCHOR_H
#define ANCHOR_H

#include <string>
#include <vector>
#include <stdexcept>

struct Connection;
class Block;

class Anchor
{
public:
    Anchor(const std::string& uuid, Block* reference);

    static Block* getNextBlock(const std::string& uuid);
    static void loadConnections(static std::vector<Connection> _connections);
    static std::string findTheEndOf(const std::string& value);

private:
    static std::vector<Anchor*> anchors;
    static std::vector<Connection> connections;

    std::string uuid;
    Block* reference;
};

#endif //ANCHOR_H
