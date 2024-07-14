#include <string>

class AstPrinter : public Visitor<std::string> {
public:
    std::string print(Expression<std::string>* expr) {
        return expr->accept(this);
    }

    std::string visit(Binary<std::string>* expr) {
        return parenthesize(expr->op.lexeme, expr->left, expr->right);
    }

    std::string visit(Grouping<std::string>* expr) {
        return parenthesize("group", expr->expression);
    }

    std::string visit(Literal<std::string>* expr) {
        return expr->value;
    }

    std::string visit(Unary<std::string>* expr) {
        return parenthesize(expr->op.lexeme, expr->right);
    }

    std::string parenthesize(std::string name, Expression<std::string>* expr) {
        return "(" + name + " " + expr->accept(this) + ")";
    }

    std::string parenthesize(std::string name, Expression<std::string>* expr1, Expression<std::string>* expr2) {
        return "(" + expr1->accept(this) + " " + name + " " + expr2->accept(this) + ")";
    }
};