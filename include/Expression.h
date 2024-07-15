#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Token.h"
#include <any>
#include <string>

// Forward declaration of Visitor class
class Visitor;

class Expression {
public:
    Expression() = default;
    virtual ~Expression() = default;
    virtual std::any accept(Visitor* visitor) = 0;
};

class Binary : public Expression {
public:
    Binary(Expression* left, Token op, Expression* right);
    std::any accept(Visitor* visitor) override;

    Expression* left;
    Token op;
    Expression* right;
};

class Grouping : public Expression {
public:
    Grouping(Expression* expression);
    std::any accept(Visitor* visitor) override;

    Expression* expression;
};

// @TODO maybe change to a template class
class Literal : public Expression {
public:
    Literal(std::string value);
    std::any accept(Visitor* visitor) override;

    template<typename V>
    V getValue() {
        return std::any_cast<V>(value);
    }

    std::any value;
};

class Unary : public Expression {
public:
    Unary(Token op, Expression* right);
    std::any accept(Visitor* visitor) override;

    Token op;
    Expression* right;
};

#endif // EXPRESSION_H
