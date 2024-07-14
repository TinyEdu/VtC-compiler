#include "Token.h"
#include "any"

// Forward declaration
template<typename R>
class Visitor;


template<typename R>
class Expression {
public:
    virtual ~Expression() = default;
    virtual R accept(Visitor<R>* visitor) = 0;
};


template<typename R>
class Binary : public Expression<R> {
public:
    Binary(Expression<R>* left, Token op, Expression<R>* right) : left(left), op(op), right(right) {}
    R accept(Visitor<R>* visitor) override {
        return visitor->visit(this);
    }

    Expression<R>* left;
    Token op;
    Expression<R>* right;
};


template<typename R>
class Grouping : public Expression<R> {
public:
    Grouping(Expression<R>* expression) : expression(expression) {}
    R accept(Visitor<R>* visitor) override {
        return visitor->visit(this);
    }

    Expression<R>* expression;
};


template<typename R>
class Literal : public Expression<R> {
public:
    Literal(std::any value) : value(value) {}
    R accept(Visitor<R>* visitor) override {
        return visitor->visit(this);
    }

    std::any value;
};

template<typename R>
class Unary : public Expression<R> {
public:
    Unary(Token op, Expression<R>* right) : op(op), right(right) {}
    R accept(Visitor<R>* visitor) override {
        return visitor->visit(this);
    }

    Token op;
    Expression<R>* right;
};




template<typename R>
class Visitor {
public:
    virtual R visit(class Binary<R>* expr) = 0;
    virtual R visit(class Grouping<R>* expr) = 0;
    virtual R visit(class Literal<R>* expr) = 0;
    virtual R visit(class Unary<R>* expr) = 0;
};

