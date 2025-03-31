#ifndef FORLOOP_H
#define FORLOOP_H

#include "Block.h"

class ForLoop : public Block
{
public:
    DEFINE_BLOCK_TYPE(ForLoop);

    QString fromField;
    QString toField;
    QString incrementField;

    QUuid startAnchor;
    QUuid endAnchor;
    QUuid incrementAnchor;

public:
    QJsonObject toJson() const override
    {
        QJsonObject json = Block::toJson();
        json["startAnchor"] =  startAnchor.toString();
        json["endAnchor"] =  endAnchor.toString();
        json["condition"] =  incrementAnchor.toString();

        json["fromField"] =  fromField;
        json["toField"] =  toField;
        json["incrementField"] =  incrementField;

        return json;
    }
};
#endif //FORLOOP_H
