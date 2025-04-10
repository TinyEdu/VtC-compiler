#include "Anchor.h"

#include <iostream>

#include "../vo/Connection.h"

std::vector<Anchor> Anchor::anchors;
std::vector<Connection> Anchor::connections;

Anchor::Anchor(const std::string& uuid, Block* reference)
    : uuid(uuid),
      reference(reference)
{
    anchors.push_back(*this);
}

Block* Anchor::getNextBlock(const std::string& uuid)
{
    std::string oppositeUuid = findTheEndOf(uuid);

    for (const Anchor anchor : anchors)
    {
        if (anchor.uuid == oppositeUuid)
        {
            return anchor.reference;
        }
    }

    throw std::runtime_error("Anchor not found");
}

void Anchor::loadConnections(std::vector<Connection> _connections)
{
    connections = std::move(_connections);
}

Block* Anchor::getNextBlock(const Anchor& input)
{
    const std::string uuid = input.uuid;
    const std::string oppositeUuid = findTheEndOf(uuid);

    std::cout << "Found opposite UUID: " << oppositeUuid << std::endl;
    std::vector<Anchor> a = anchors;

    for (auto anchor : anchors)
    {
        if (anchor.uuid == oppositeUuid)
        {
            return anchor.reference;
        }
    }

    throw std::runtime_error("Anchor not found");
}

std::string Anchor::findTheEndOf(const std::string& value)
{
    for (Connection connection : connections)
    {
        if (value == connection.from)
        {
            return connection.to;
        }

        if (value == connection.to)
        {
            return connection.from;
        }
    }

    throw std::runtime_error("Anchor not found");
}

void Anchor::clearAnchors()
{
    anchors = {};
}
