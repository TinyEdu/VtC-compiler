#include "Expression.h"
#include "Visitor.h"

// Define constructors and accept methods
Binary::Binary(Expression* left, Token op, Expression* right)
    : left(left), op(op), right(right) {}

std::any Binary::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Grouping::Grouping(Expression* expression) : expression(expression) {}

std::any Grouping::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Literal::Literal(bool value) {
  this->value = value;
  type = Type::BOOL;
}

Literal::Literal(double value) {
  this->value = value;
  type = Type::DOUBLE;
}

Literal::Literal(int value) {
  this->value = value;
  type = Type::INT;
}

Literal::Literal(std::string value) : value(value) {
  this->value = value;
  type = Type::STRING;
}

std::any Literal::accept(Visitor* visitor) {
  return visitor->visit(this);
}

std::variant<bool, double, int, std::string> Literal::getValue() {
  if (type == Type::BOOL) {
    return std::any_cast<bool>(value);
  } else if (type == Type::DOUBLE) {
    return std::any_cast<double>(value);
  } else if (type == Type::INT) {
    return std::any_cast<int>(value);
  } else if (type == Type::STRING) {
    return std::any_cast<std::string>(value);
  }

  // Optionally, throw an exception if type is not handled
  throw std::bad_any_cast();
}

Unary::Unary(Token op, Expression* right) : op(op), right(right) {}

std::any Unary::accept(Visitor* visitor) {
  return visitor->visit(this);
}
