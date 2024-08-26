#include "FunctionCallable.h"

#include "Interpreter.h"
#include "ExpressionWorld.h"
#include "Environment.h"
#include "Statement.h"

int FunctionCallable::arity() {
  return declaration->params.size();
}

std::any FunctionCallable::call(Interpreter* interpreter,
                                std::vector<Expression*> arguments) {
  
  Environment* environment = new Environment(interpreter->globals);

  for (int i = 0; i < declaration->params.size(); i++) {
    environment->define(declaration->params[i].lexeme, arguments[i]);
  }

  interpreter->executeBlock(declaration->body, environment);

  return std::any();
}

    std::ostream& operator<<(std::ostream& os, const FunctionCallable& expr) {
        os << "FunctionCallable - " << expr.declaration->name.lexeme;
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const FunctionCallable* expr) {
        os << "FunctionCallable - " << expr->declaration->name.lexeme;
        return os;
    }