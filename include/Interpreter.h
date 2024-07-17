#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Visitor.h"

class Interpreter : public VisitorT<std::any> {
public:
  std::any visit(Binary* expr);
  std::any visit(Grouping* expr);
  std::any visit(Literal* expr);
  std::any visit(Unary* expr);

    std::any evaluate(Expression* expr); 
    std::variant<bool, double, int, std::string> evaluate(Literal* expr);
    
    template <typename T>
    bool isEqual(T* a, T* b);
    
    bool isTruthy(std::any value);
};

#endif  // INTERPRETER_H 
