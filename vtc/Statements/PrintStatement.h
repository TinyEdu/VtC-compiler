#ifndef PRINTSTATEMENT_H
#define PRINTSTATEMENT_H

#include <memory>

#include "Statement.h"

class PrintStatement : public Statement, public std::enable_shared_from_this<PrintStatement>
{
public:
    explicit PrintStatement(std::shared_ptr<Expression> expression);

    ~PrintStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    std::shared_ptr<Expression> expression;
};

#endif
