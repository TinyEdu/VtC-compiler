#include "Expressions/Literals/LiteralInt.h"

#include "Expressions/Literals/LiteralBool.h"
#include "Expressions/Literals/LiteralDouble.h"
#include "Expressions/Literals/LiteralFloat.h"
#include "Expressions/Literals/LiteralString.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"

std::any LiteralInt::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Expression* LiteralInt::process(LiteralInt* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralFloat* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralString* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralBool* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(LiteralDouble* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralInt::process(Token token) {
  return OperationsDispatcher::dispatch(this, token);
}