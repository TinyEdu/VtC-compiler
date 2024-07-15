#ifndef VISITOR_H
#define VISITOR_H

#include "Expression.h"

// Forward declarations


class Visitor {
public:
    virtual std::any visit(Binary* expr) = 0;
    virtual std::any visit(Grouping* expr) = 0;
    virtual std::any visit(Literal* expr) = 0;
    virtual std::any visit(Unary* expr) = 0;
};

template <typename T>
class VisitorT : public Visitor {
public:
    inline T visiting(Expression* expr) {
        return std::any_cast<T>(expr->accept(this));
    }
};

#endif // VISITOR_H
