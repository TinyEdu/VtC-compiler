// LiteralString.h

#ifndef LITERAL_STRING_H
#define LITERAL_STRING_H

#include "Literal.h"

class LiteralString : public Literal {
 public:
  LiteralString(int value);

  std::string value;

  virtual Expression* process(Literal* expr, Token token) override {
    return expr->process(this, token);
  };

  virtual Expression* process(LiteralInt* expr, Token token) override {
    return OperationsDispatcher::dispatch(expr, this, token);
  };
  virtual Expression* process(LiteralFloat* expr, Token token) override {
    return OperationsDispatcher::dispatch(expr, this, token);
  };
  virtual Expression* process(LiteralString* expr, Token token) override {
    return OperationsDispatcher::dispatch(expr, this, token);
  };
  virtual Expression* process(LiteralBool* expr, Token token) override {
    return OperationsDispatcher::dispatch(expr, this, token);
  };
  virtual Expression* process(LiteralDouble* expr, Token token) override {
    return OperationsDispatcher::dispatch(expr, this, token);
  };

  friend std::ostream& operator<<(std::ostream& os, const LiteralString* expr);
};

#endif  // LITERAL_STRING_H