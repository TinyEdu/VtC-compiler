#include "Assign.h"

Assign::Assign(Variable* var, Expression* expr) : var(var), expr(expr) {}

Assign::~Assign() {}

std::any Assign::accept(Visitor* visitor) {
    return visitor->visit(this);
}

std::ostream& operator<<(std::ostream& os, const Assign& assign) {
    os << *assign.var << " = " << *assign.expr;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Assign* assign) {
    os << assign.var << " = " << assign.expr;
    return os;
}


