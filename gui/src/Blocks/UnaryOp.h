#ifndef UNARYOP_H
#define UNARYOP_H

#include "Block.h"

class UnaryOp : public Block
{
public:
    DEFINE_BLOCK_TYPE(UnaryOp);

    QUuid inputValue;
    QString operation;
    QUuid outputValue;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["inputValue"] =  inputValue.toString();
        json["operation"] =  operation;
        json["outputValue"] =  outputValue.toString();

        return json;
    }
};

#endif //UNARYOP_H