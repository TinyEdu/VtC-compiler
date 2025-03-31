#ifndef WHILE_H
#define WHILE_H

#include "Block.h"

class While : public Block {
public:
    DEFINE_BLOCK_TYPE(While);

    QUuid condition;
    QUuid startAnchor;
    QUuid endAnchor;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["condition"] =  condition.toString();
        json["startAnchor"] =  startAnchor.toString();
        json["endAnchor"] =  endAnchor.toString();

        return json;
    }
};

#endif //WHILE_H