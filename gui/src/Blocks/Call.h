#ifndef CALL_H
#define CALL_H

#include "Block.h"

class Call : public Block
{
public:
    DEFINE_BLOCK_TYPE(Call);

    QString eventName;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["eventName"] =  eventName;

        return json;
    }
};

#endif //CALL_H
