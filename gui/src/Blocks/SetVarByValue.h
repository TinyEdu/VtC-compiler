#ifndef SETVARBYVALUE_H
#define SETVARBYVALUE_H

#include "Block.h"

class SetVarByValue : public Block
{
public:
    DEFINE_BLOCK_TYPE(SetVarBySignal);

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

#endif //SETVARBYVALUE_H