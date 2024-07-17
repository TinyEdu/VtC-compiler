#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Visitor.h"

class Interpreter : public VisitorT<std::any> {
public:
    Interpreter();
    ~Interpreter();
public:
  std::any visit(Binary* expr);
  std::any visit(Grouping* expr);
  std::any visit(Literal* expr);
  std::any visit(Unary* expr);

    void interpret(Expression* expr);
    std::any evaluate(Expression* expr); 
    std::variant<bool, double, int, std::string> evaluate(Literal* expr);
    void checkNumberOperand(Token op, std::any operand);
    bool isEqual(std::any a, std::any b);
    void checkNumberOperands(Token op, std::any left, std::any right);
    bool isTruthy(std::any value);
    std::string stringify(std::any value);
};

#endif  // INTERPRETER_H 
