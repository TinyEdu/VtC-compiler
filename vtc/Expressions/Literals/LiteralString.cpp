#include "Expressions/Literals/LiteralString.h"

#include "Expressions/Literals/LiteralBool.h"
#include "Expressions/Literals/LiteralDouble.h"
#include "Expressions/Literals/LiteralFloat.h"
#include "Expressions/Literals/LiteralInt.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"

std::any LiteralString::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Expression* LiteralString::process(LiteralInt* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralFloat* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralString* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralBool* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(LiteralDouble* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralString::process(Token token) {
  return OperationsDispatcher::dispatch(this, token);
}