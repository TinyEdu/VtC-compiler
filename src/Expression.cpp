#include "Expression.h"
#include "Visitor.h"

// Define constructors and accept methods
Binary::Binary(Expression* left, Token op, Expression* right)
    : left(left), op(op), right(right) {}

std::any Binary::accept(Visitor* visitor) {
    return visitor->visit(this);
}

Grouping::Grouping(Expression* expression)
    : expression(expression) {}

std::any Grouping::accept(Visitor* visitor) {
    return visitor->visit(this);
}

Literal::Literal(std::string value)
    : value(value) {}

std::any Literal::accept(Visitor* visitor) {
    return visitor->visit(this);
}

Unary::Unary(Token op, Expression* right)
    : op(op), right(right) {}

std::any Unary::accept(Visitor* visitor) {
    return visitor->visit(this);
}
