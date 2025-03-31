#ifndef CREATEVARBYVALUE_H
#define CREATEVARBYVALUE_H

#include "Block.h"

class CreateVarByValue : public Block
{
public:
    DEFINE_BLOCK_TYPE(CreateVarByValue);

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

#endif //CREATEVARBYVALUE_H