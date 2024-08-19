// LiteralInt.h

#ifndef LITERAL_INT_H
#define LITERAL_INT_H

#include "Literal.h"

class LiteralInt : public Literal {
 public:
  LiteralInt(int value);

  int value;

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

  friend std::ostream& operator<<(std::ostream& os, const LiteralInt* expr);
};

#endif  // LITERAL_INT_H