#include "Expressions/Literals/LiteralDouble.h"

#include "Expressions/Literals/LiteralBool.h"
#include "Expressions/Literals/LiteralFloat.h"
#include "Expressions/Literals/LiteralInt.h"
#include "Expressions/Literals/LiteralString.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"

std::any LiteralDouble::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Expression* LiteralDouble::process(LiteralInt* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralFloat* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralString* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralBool* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(LiteralDouble* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralDouble::process(Token token) {
  return OperationsDispatcher::dispatch(this, token);
}