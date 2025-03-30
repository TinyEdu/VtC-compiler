#ifndef GETVAR_H
#define GETVAR_H

#include "Block.h"

class If : public Block
{
public:
    DEFINE_BLOCK_TYPE(GetVar);

    QString variable;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["variable"] =  variable;

        return json;
    }
};

#endif //GETVAR_H