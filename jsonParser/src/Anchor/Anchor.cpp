#include "Anchor.h"

std::vector<Anchor*> Anchor::anchors;


Anchor::Anchor(const std::string& uuid, Block* reference)
        : uuid(uuid),
          reference(reference)
{
    anchors.push_back(this);
}

Block* Anchor::getNextBlock(const std::string& uuid)
{
    for (Anchor* anchor : anchors)
    {
        if (anchor->uuid == uuid)
        {
            return anchor->reference;
        }
    }

    throw std::runtime_error("Anchor not found");
}
