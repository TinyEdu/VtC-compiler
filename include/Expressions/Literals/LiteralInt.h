// LiteralInt.h

#ifndef LiteralInt_H
#define LiteralInt_H

#include "string.h"

class Expression;
class Literal;
class LiteralFloat;
class LiteralString;
class LiteralBool;
class LiteralDouble;

class LiteralInt : public Literal {

LiteralInt(int value) : value(value) {};

int value;

virtual Expression* process(Literal* expr, Token token) override {
return expr->process(this, token);
};

virtual Expression* process(LiteralInt* expr, Token token);
virtual Expression* process(LiteralFloat* expr, Token token);
virtual Expression* process(LiteralString* expr, Token token);
virtual Expression* process(LiteralBool* expr, Token token);
virtual Expression* process(LiteralDouble* expr, Token token);

friend std::ostream& operator<<(std::ostream& os, const LiteralInt* expr) {
  os << expr->value;
  return os;
};

friend std::ostream& operator<<(std::ostream& os, const LiteralInt& expr) {
  os << expr.value;
  return os;
};

};
#endif  // LiteralInt_H
