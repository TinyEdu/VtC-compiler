// AstPrinter.h

#ifndef AST_PRINTER_H
#define AST_PRINTER_H

#include <string>

#include "Visitor.h"

class AstPrinter : public Visitor {
 public:
  std::string print(Expression* expr) {
    return std::any_cast<std::string>(expr->accept(this));
  }

  std::any visit(Binary* expr) {
    return parenthesize(expr->op.lexeme, expr->left, expr->right);
  }

  std::any visit(Grouping* expr) {
    return parenthesize("group", expr->expression);
  }

  std::any visit(Literal* expr) { return expr->getValue(); }

  std::any visit(Unary* expr) {
    return parenthesize(expr->op.lexeme, expr->right);
  }

  std::string parenthesize(std::string name, Expression* expr) {
    return "(" + name + " " + std::any_cast<std::string>(expr->accept(this)) +
           ")";
  }

  std::string parenthesize(std::string name, Expression* expr1,
                           Expression* expr2) {
    return "(" + std::any_cast<std::string>(expr1->accept(this)) + " " + name +
           " " + std::any_cast<std::string>(expr2->accept(this)) + ")";
  }
};

#endif  // AST_PRINTER_H
