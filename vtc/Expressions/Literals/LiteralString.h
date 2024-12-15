// LiteralString.h

#ifndef LiteralString_H
#define LiteralString_H

#include "Expressions/Literals/Literal.h"

class Expression;
class LiteralInt;
class LiteralFloat;
class LiteralBool;
class LiteralDouble;

class LiteralString : public Literal {
 public:
  LiteralString(std::string value) : value(value){};

  std::string value;

  virtual std::any accept(Visitor* visitor);

  virtual Expression* process(Literal* expr, Token token) override {
    return expr->process(this, token);
  };

  virtual Expression* process(LiteralInt* expr, Token token);
  virtual Expression* process(LiteralFloat* expr, Token token);
  virtual Expression* process(LiteralString* expr, Token token);
  virtual Expression* process(LiteralBool* expr, Token token);
  virtual Expression* process(LiteralDouble* expr, Token token);
  virtual Expression* process(Token token);

  friend std::ostream& operator<<(std::ostream& os, const LiteralString* expr) {
    os << expr->value;
    return os;
  };

  friend std::ostream& operator<<(std::ostream& os, const LiteralString& expr) {
    os << expr.value;
    return os;
  };
};
#endif  // LiteralString_H
