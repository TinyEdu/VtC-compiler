#ifndef CREATEVARBYVALUE_H
#define CREATEVARBYVALUE_H

#include "Block.h"

class CreateVarByValue : public Block
{
public:
    DEFINE_BLOCK_TYPE(CreateVarByValue);

    QString variable;
    QString value;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["variable"] =  variable;
        json["value"] =  value;

        return json;
    }
};

#endif //CREATEVARBYVALUE_H