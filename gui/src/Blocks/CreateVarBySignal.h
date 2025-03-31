#ifndef CREATEVARBYSIGNAL_H
#define CREATEVARBYSIGNAL_H

#include "Block.h"

class CreateVarBySignal : public Block
{
public:
    DEFINE_BLOCK_TYPE(CreateVarBySignal);

    QString variableName;
    QUuid value;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["variable"] =  variableName;
        json["value"] =  value.toString();

        return json;
    }
};

#endif //CREATEVARBYSIGNAL_H
