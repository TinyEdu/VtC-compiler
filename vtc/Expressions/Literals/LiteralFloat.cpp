#include "Expressions/Literals/LiteralFloat.h"

#include "Expressions/Literals/LiteralBool.h"
#include "Expressions/Literals/LiteralDouble.h"
#include "Expressions/Literals/LiteralInt.h"
#include "Expressions/Literals/LiteralString.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"


std::any LiteralFloat::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Expression* LiteralFloat::process(LiteralInt* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralFloat* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralString* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralBool* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(LiteralDouble* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralFloat::process(Token token) {
  return OperationsDispatcher::dispatch(this, token);
}