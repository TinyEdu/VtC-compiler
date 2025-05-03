#ifndef FORLOOP_H
#define FORLOOP_H

#include "Block.h"

class ForLoop : public Block
{
public:
    DEFINE_BLOCK_TYPE(ForLoop);

    QUuid startAnchor;

    QString fromField;
    QString toField;
    QString stepField;
    QString indexName;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["startAnchor"] =  startAnchor.toString();

        json["fromField"] =  fromField;
        json["toField"] =  toField;
        json["stepField"] =  stepField;
        json["indexName"] = indexName;

        return json;
    }
};
#endif //FORLOOP_H
