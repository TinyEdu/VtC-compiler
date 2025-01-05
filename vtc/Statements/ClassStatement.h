#ifndef CLASSSTATEMENT_H
#define CLASSSTATEMENT_H

#include "Statement.h"

class FunctionStatement;

// @TODO: remove ClassStatement
class ClassStatement : public Statement
{
public:
    ClassStatement(Token name, std::vector<FunctionStatement*> methods)
        : name(name), methods(methods)
    {
    }

    ~ClassStatement() = default;

    std::any accept(StatementVisitor* visitor) override;

    bool equals(const Expression& other) const override;

    Token name;
    std::vector<FunctionStatement*> methods;
};

#endif
