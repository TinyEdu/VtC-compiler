#ifndef PRINTBYVALUE_H
#define PRINTBYVALUE_H

#include "Block.h"

class PrintByValue : public Block
{
public:
    DEFINE_BLOCK_TYPE(PrintByValue);

    QString value;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["value"] =  value;

        return json;
    }
};

#endif //PRINTBYVALUE_H