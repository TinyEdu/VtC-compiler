#ifndef RETURNSTATEMENT_H
#define RETURNSTATEMENT_H

#include <memory>

#include "Statement.h"

class ReturnStatement : public Statement, public std::enable_shared_from_this<ReturnStatement>
{
public:
    ReturnStatement(Token keyword, std::shared_ptr<Expression> value);

    ~ReturnStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    Token keyword;
    std::shared_ptr<Expression> value;
};

#endif
