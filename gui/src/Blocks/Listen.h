#ifndef LISTEN_H
#define LISTEN_H

#include "Block.h"

class Listen : public Block
{
public:
    DEFINE_BLOCK_TYPE(Listen);

    QString eventName;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["eventName"] =  eventName;

        return json;
    }
};

#endif //LISTEN_H