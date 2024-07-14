#include <string>


class AstPrinter : public Visitor {
public:
    std::any print(Expression* expr) {
        return expr->accept(this);
    }

    std::any visit(Binary* expr) {
        return parenthesize(expr->op.lexeme, expr->left, expr->right);
    }

    std::any visit(Grouping* expr) {
        return parenthesize("group", expr->expression);
    }

    std::any visit(Literal* expr) {
        return expr->getValue<std::string>();
    }

    std::any visit(Unary* expr) {
        return parenthesize(expr->op.lexeme, expr->right);
    }

    template<typename T>
    std::string parenthesize(std::string name, T* expr) {
        std::any r = expr->accept(this);
        if(r.type() == typeid(std::string)) {
            return "(" + name + " " + std::any_cast<std::string>(r) + ")";
        }
        return "";
    }


    template<typename T>
    std::string parenthesize(std::string name, T* expr1, T* expr2) {
        std::any r1 = expr1->accept(this);
        std::any r2 = expr2->accept(this);

        if(r1.type() == typeid(std::string) && r2.type() == typeid(std::string)) {
            return "(" + std::any_cast<std::string>(r1) + " " + name + " " + std::any_cast<std::string>(r2) + ")";
        }
        return "";
   }
};