#ifndef CLASSSTATEMENT_H
#define CLASSSTATEMENT_H

#include <memory>

#include "Statement.h"

class FunctionStatement;

// @TODO: remove ClassStatement
class ClassStatement : public Statement, public std::enable_shared_from_this<ClassStatement>
{
public:
    ClassStatement(Token name, std::vector<std::shared_ptr<FunctionStatement>> methods);

    ~ClassStatement();

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Statement& other) const override;

    Token name;
    std::vector<std::shared_ptr<FunctionStatement>> methods;
};

#endif
