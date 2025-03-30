#ifndef GETVAR_H
#define GETVAR_H

#include "Block.h"

class GetVar : public Block
{
public:
    DEFINE_BLOCK_TYPE(GetVar);

    QString variable;
    QUuid passingAnchor;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["variable"] =  variable;
        json["passingAnchor"] =  passingAnchor.toString();

        return json;
    }
};

#endif //GETVAR_H