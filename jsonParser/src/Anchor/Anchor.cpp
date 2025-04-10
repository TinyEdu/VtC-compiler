#include "Anchor.h"

#include "../vo/Connection.h"

std::vector<Anchor*> Anchor::anchors;
std::vector<Connection> Anchor::connections;

Anchor::Anchor(const std::string& uuid, Block* reference)
    : uuid(uuid),
      reference(reference)
{
    anchors.push_back(this);
}

Block* Anchor::getNextBlock(const std::string& uuid)
{
    std::string oppositeUuid = findTheEndOf(uuid);

    for (Anchor* anchor : anchors)
    {
        if (anchor->uuid == oppositeUuid)
        {
            return anchor->reference;
        }
    }

    throw std::runtime_error("Anchor not found");
}

void Anchor::loadConnections(std::vector<Connection> _connections)
{
    connections = std::move(_connections);
}

std::string Anchor::findTheEndOf(const std::string& value)
{
    for (Connection connection : connections)
    {
        if (value == connection.from.toString())
        {
            return connection.to.toString().toStdString();
        }

        if (value == connection.to.toString())
        {
            return connection.from.toString().toStdString();
        }
    }

    throw std::runtime_error("Anchor not found");
}
