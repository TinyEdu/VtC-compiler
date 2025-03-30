#ifndef CALL_H
#define CALL_H
#include "Block.h"


class Call : public Block
{
public:
    DEFINE_BLOCK_TYPE(Call);

    std::string eventName;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["eventName"] =  QString::fromStdString(eventName);

        return json;
    }
};
#endif //CALL_H
