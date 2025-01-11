#ifndef EXPRESSIONSTATEMENT_H
#define EXPRESSIONSTATEMENT_H

#include <memory>

#include "Statement.h"

class ExpressionStatement : public Statement, public std::enable_shared_from_this<ExpressionStatement>
{
public:
    ExpressionStatement(std::shared_ptr<Expression> expression);

    ~ExpressionStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    std::shared_ptr<Expression> expression;
};

#endif
