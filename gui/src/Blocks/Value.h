#ifndef VAR_H
#define VAR_H

#include "Block.h"

class Value : public Block
{
public:
    DEFINE_BLOCK_TYPE(Value);

    QString value;
    QUuid passingAnchor;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["value"] =  value;
        json["passingAnchor"] =  passingAnchor.toString();

        return json;
    }
};

#endif //VAR_H