#ifndef PRINT_H
#define PRINT_H

#include "Block.h"

class Print : public Block
{
public:
    DEFINE_BLOCK_TYPE(Print);

    QUuid value;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["value"] =  value.toString();

        return json;
    }
};

#endif //PRINT_H