#ifndef BINARYOP_H
#define BINARYOP_H

#include "Block.h"

class BinaryOp : public Block
{
public:
    DEFINE_BLOCK_TYPE(BinaryOp);

    QUuid rightInputValue;
    QUuid leftInputValue;
    QString operation;
    QUuid outputValue;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["rightInputValue"] =  rightInputValue.toString();
        json["leftInputValue"] =  leftInputValue.toString();
        json["operation"] =  operation;
        json["outputValue"] =  outputValue.toString();

        return json;
    }
};

#endif //BINARYOP_H
