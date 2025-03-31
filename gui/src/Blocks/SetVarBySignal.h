#ifndef SETVARBYSIGNAL_H
#define SETVARBYSIGNAL_H

#include "Block.h"

class SetVarBySignal : public Block
{
public:
    DEFINE_BLOCK_TYPE(SetVarBySignal);

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

#endif //SETVARBYSIGNAL_H