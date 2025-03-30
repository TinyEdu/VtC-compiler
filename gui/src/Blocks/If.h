#ifndef IF_H
#define IF_H

#include "Block.h"

class If : public Block
{
public:
    DEFINE_BLOCK_TYPE(If);

    QUuid condition;
    QUuid trueAnchor;
    QUuid falseAnchor;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["condition"] =  condition.toString();
        json["trueAnchor"] =  trueAnchor.toString();
        json["falseAnchor"] =  falseAnchor.toString();

        return json;
    }
};

#endif //IF_H