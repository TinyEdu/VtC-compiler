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

Unary::Unary(Token op, Expression* right) : op(op), right(right) {}

std::any Unary::accept(Visitor* visitor) {
  return visitor->visit(this);
}


Literal::Literal(void* value) {

}

Literal::Literal(bool value) {
  type = Type::BOOL;
  value = value;
}

Literal::Literal(std::string value) {
  type = Type::STRING;
  value = value;
}

Literal::Literal(int value) {
  type = Type::INT;
  value = value;
}

Literal::Literal(double value) {
  type = Type::DOUBLE;
  value = value;
}

Literal::Literal(Type type, std::any value) {
  type = type;
  value = value;
}

std::any Literal::getValue() {
  return value;
}

Literal* operator+(const Literal& other) {
  if (this->type == Type::BOOL || other.type == Type::BOOL) throw std::invalid_argument("Literal operation. Wrong types"); 
  if (this->type == Type::STRING ^ other.type == Type::STRING) throw std::invalid_argument("Literal wrong string adding");

  Literal* result;
  if (this->type == Type::DOUBLE || other->type == Type::DOUBLE) {
    double value = std::any_cast<double>(this->getValue() + std::any_cast<double>(other.getValue()));
    result = new Literal(Type::DOUBLE, value);
  } 
  else if (this->type == Type::INT && this->type == Type::INT) {
    int value = std::any_cast<int>(this->getValue() + std::any_cast<int>(other.getValue()));
    result = new Literal(Type::INT, value);
  }
  else {
    std::cout << "SOMETHING IS OFF + Literal.\n";
  }
  return result;
}
Literal* operator-(const Literal& other) {

}

Literal* operator*(const Literal& other) {

}

Literal* operator/(const Literal& other) {

}

bool operator<(const Literal& l1, const Literal& l2) {

}

bool operator>(const Literal& l1, const Literal& l2) {

}

bool operator==(const Literal& l1, const Literal& l2) {

}