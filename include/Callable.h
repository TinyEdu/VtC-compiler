// Callable.h

#ifndef CALLABLE_H
#define CALLABLE_H

#include <any>
#include <vector>
#include <iostream>


class Interpreter;
class Expression;

class Callable {
 public:
  Callable() {};
  ~Callable() {};

  virtual int arity()=0;
  virtual std::any call(Interpreter* interpreter, std::vector<Expression*> arguments)=0;

  friend std::ostream& operator<<(std::ostream& os, const Callable& expr);
  friend std::ostream& operator<<(std::ostream& os, const Callable* expr);
};

#endif  // CALLABLE_H