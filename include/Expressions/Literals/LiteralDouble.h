// LiteralDouble.h

#ifndef LITERAL_DOUBLE_H
#define LITERAL_DOUBLE_H

#include "Literal.h"

class LiteralDouble : public Literal {
 public:
  LiteralDouble(double value);

  double value;

  virtual Expression* process(Literal* expr, Token token) override { return expr->process(this, token); };
  
  virtual Expression* process(LiteralInt* expr, Token token) override { return OperationsDispatcher::dispatch(expr, this, token); };
  virtual Expression* process(LiteralFloat* expr, Token token) override { return OperationsDispatcher::dispatch(expr, this, token); };
  virtual Expression* process(LiteralString* expr, Token token) override { return OperationsDispatcher::dispatch(expr, this, token); };
  virtual Expression* process(LiteralBool* expr, Token token) override { return OperationsDispatcher::dispatch(expr, this, token); };
  virtual Expression* process(LiteralDouble* expr, Token token) override { return OperationsDispatcher::dispatch(expr, this, token); };

  friend std::ostream& operator<<(std::ostream& os, const LiteralDouble* expr);
};

#endif // LITERAL_DOUBLE_H