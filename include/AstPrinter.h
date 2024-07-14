#include <string>

class AstPrinter : public Visitor<std::string> {
public:
    std::string visit(Binary<std::string>* expr) {
        return parenthesize(expr->op.lexeme, expr->left, expr->right);
    }

    std::string visit(Grouping<std::string>* expr) {
        return parenthesize("group", expr->expression);
    }

    std::string visit(Literal<std::string>* expr) {
        if (!expr->value.has_value()) return "nil";
        
        try {
            // Attempt to cast the std::any to a string
            return std::any_cast<std::string>(expr->value);
        } catch (const std::bad_any_cast& e) {
            // Handle the case where the std::any does not hold a string
            std::cerr << "Bad any_cast: " << e.what() << std::endl;
        }

        return "";
    }

    std::string visit(Unary<std::string>* expr) {
        return parenthesize(expr->op.lexeme, expr->right);
    }

    std::string parenthesize(std::string name, Expression<std::string>* expr) {
        return "(" + name + " " + expr->accept(this) + ")";
    }

    std::string parenthesize(std::string name, Expression<std::string>* expr1, Expression<std::string>* expr2) {
        return "(" + name + " " + expr1->accept(this) + " " + expr2->accept(this) + ")";
    }
};