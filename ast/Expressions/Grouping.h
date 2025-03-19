#ifndef GROUPING_H
#define GROUPING_H

#include "Expression.h"

class Visitor;

class Grouping : public Expression, public std::enable_shared_from_this<Grouping>
{
public:
    Grouping(std::shared_ptr<Expression> expression);

    std::shared_ptr<Expression> accept(Visitor& visitor) override;

    std::shared_ptr<Expression> expression;

    bool equals(const Expression& other) const override;

    friend std::ostream& operator<<(std::ostream& os, const Grouping* expr);
    friend std::ostream& operator<<(std::ostream& os, const Grouping& expr);
};

#endif  // GROUPING_H
