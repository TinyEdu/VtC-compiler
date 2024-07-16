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
    auto value = expr->getValue();
    std::any result = std::visit(
        [](auto&& arg) -> std::any {
          using T = std::decay_t<decltype(arg)>;
          if constexpr (std::is_same_v<T, bool>) {
            return arg ? "true" : "false";
          } else if constexpr (std::is_same_v<T, double>) {
            return std::to_string(arg);
          } else if constexpr (std::is_same_v<T, int>) {
            return std::to_string(arg);
          } else if constexpr (std::is_same_v<T, std::string>) {
            return arg;
          }
        },
        value);
    return std::any_cast<std::string>(result);
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
