// FunctionCallable.h

#ifndef FUNCTIONCALLABLE_H
#define FUNCTIONCALLABLE_H

#include "Callable.h"

// Forward declaration
class FunctionStatement;

class FunctionCallable : public Callable {
 public:
  FunctionCallable(FunctionStatement* declaration) : declaration(declaration) {};
  ~FunctionCallable() {};

  int arity() override;
  std::any call(Interpreter* interpreter, std::vector<Expression*> arguments) override;

    // print
    friend std::ostream& operator<<(std::ostream& os, const FunctionCallable& expr); 
    friend std::ostream& operator<<(std::ostream& os, const FunctionCallable* expr);
private:
    FunctionStatement* declaration;
};

#endif  // FUNCTIONCALLABLE_H