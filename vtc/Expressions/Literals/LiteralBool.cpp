#include "Expressions/Literals/LiteralBool.h"

#include "Expressions/Literals/LiteralDouble.h"
#include "Expressions/Literals/LiteralFloat.h"
#include "Expressions/Literals/LiteralInt.h"
#include "Expressions/Literals/LiteralString.h"

#include "Visitor/OperationsDispatcher.h"
#include "Visitor/Visitor.h"

std::any LiteralBool::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Expression* LiteralBool::process(LiteralInt* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralFloat* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralString* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralBool* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(LiteralDouble* expr, Token token) {
  return OperationsDispatcher::dispatch(expr, this, token);
};

Expression* LiteralBool::process(Token token) {
  return OperationsDispatcher::dispatch(this, token);
}