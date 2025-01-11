#ifndef FUNCTIONSTATEMENT_H
#define FUNCTIONSTATEMENT_H

#include <memory>

#include "Statement.h"

class FunctionStatement : public Statement, public std::enable_shared_from_this<FunctionStatement>
{
public:
    FunctionStatement(Token name, std::vector<Token> params,
                      std::vector<std::shared_ptr<Statement>> body);

    ~FunctionStatement() override;

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    Token name;
    std::vector<Token> params;
    std::vector<std::shared_ptr<Statement>> body;
};

#endif
