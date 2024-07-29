#ifndef AST_PRINTER_H
#define AST_PRINTER_H
#include <Visitor.h>
#include <string>

class AstPrinter : public VisitorT<std::string> {
 public:
  std::string print(Expression* expr) { return this->visiting(expr); }

  std::any visit(Binary* expr) {
    return parenthesize(expr->op.lexeme, expr->left, expr->right);
  }

  std::any visit(Grouping* expr) {
    return parenthesize("group", expr->expression);
  }

  std::any visit(Literal* expr) {
    return expr->getValue();
  }

  std::any visit(Unary* expr) {
    return parenthesize(expr->op.lexeme, expr->right);
  }

  template <typename T>
  std::string parenthesize(std::string name, T* expr) {
    return "(" + name + " " + visiting(expr) + ")";
  }

  template <typename T>
  std::string parenthesize(std::string name, T* expr1, T* expr2) {
    return "(" + visiting(expr1) + " " + name + " " + visiting(expr2) + ")";
  }
};

#endif  // AST_PRINTER_H
