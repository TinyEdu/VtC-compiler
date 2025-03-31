#ifndef SETVARBYVALUE_H
#define SETVARBYVALUE_H

#include "Block.h"

class SetVarByValue : public Block
{
public:
    DEFINE_BLOCK_TYPE(SetVarBySignal);

    QString variableName;
    QString value;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["variable"] =  variableName;
        json["value"] =  value;

        return json;
    }
};

#endif //SETVARBYVALUE_H