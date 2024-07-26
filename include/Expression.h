#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <any>
#include <string>
#include <typeinfo>
#include <variant>
#include "Token.h"

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


class Unary : public Expression {
 public:
  Unary(Token op, Expression* right);
  std::any accept(Visitor* visitor) override;

  Token op;
  Expression* right;
};


enum Type {STRING, INT, DOUBLE, BOOL};

class Literal : public Expression {
 public:
    Literal(void* value);
    Literal(bool value);
    Literal(std::string value);
    Literal(int value);
    Literal(double value);

    Literal(Type type, std::any value);
    
    std::any accept(Visitor* visitor);
    std::any getValue();

    std::any value; 
    Type type;

    // overloading functions
    // in "Expression.cpp"
}; 



#endif  // EXPRESSION_H
