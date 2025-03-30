#ifndef BINARYOP_H
#define BINARYOP_H

#include "Block.h"

class BinaryOp : public Block
{
public:
    DEFINE_BLOCK_TYPE(BinaryOp);

    QUuid leftValue;
    QString operation;
    QUuid rightValue;
    QUuid result;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["leftValue"] =  leftValue.toString();
        json["operation"] =  operation;
        json["rightValue"] =  rightValue.toString();
        json["result"] =  result.toString();

        return json;
    }
};

#endif //BINARYOP_H
