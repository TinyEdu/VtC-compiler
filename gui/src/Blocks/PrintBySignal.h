#ifndef PRINTBYSIGNAL_H
#define PRINTBYSIGNAL_H

#include "Block.h"

class PrintBySignal : public Block
{
public:
    DEFINE_BLOCK_TYPE(PrintBySignal);

    QUuid value;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["value"] =  value.toString();

        return json;
    }
};

#endif // PRINTBYSIGNAL_H