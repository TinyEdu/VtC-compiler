#include "Token.h"
#include <any>
#include <string>

// Forward declaration of Visitor class
class Visitor;

class Expression {
public:
    Expression() = default;
    virtual ~Expression()= default;
    virtual std::any accept(Visitor* visitor) = 0;
};

class Binary : public Expression {
public:
    Binary(Expression* left, Token op, Expression* right) : left(left), op(op), right(right) {}

    std::any accept(Visitor* visitor) override;

    Expression* left;
    Token op;
    Expression* right;
};

class Grouping : public Expression {
public:
    Grouping(Expression* expression) : expression(expression) {}

    std::any accept(Visitor* visitor) override;

    Expression* expression;
};

class Literal : public Expression {
public:
    Literal(std::string value) : value(value) {}

    std::any accept(Visitor* visitor) override;

    template<typename V>
    V getValue() {
        return std::any_cast<V>(value);
    }

    std::any value;
};

class Unary : public Expression {
public:
    Unary(Token op, Expression* right) : op(op), right(right) {}

    std::any accept(Visitor* visitor) override;

    Token op;
    Expression* right;
};

// Include the Visitor class definition
class Visitor {
public:
    virtual std::any visit(Binary* expr) = 0;
    virtual std::any visit(Grouping* expr) = 0;
    virtual std::any visit(Literal* expr) = 0;
    virtual std::any visit(Unary* expr) = 0;
};
