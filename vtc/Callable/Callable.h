#ifndef CALLABLE_H
#define CALLABLE_H

#include <memory>
#include <span>


class Interpreter;
class Expression;

class Callable
{
public:
    Callable();
    virtual ~Callable();

    virtual int arity() = 0;
    virtual std::shared_ptr<Expression> call(Interpreter& interpreter,
                                             std::span<std::shared_ptr<Expression> const> arguments) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Callable& expr);
    friend std::ostream& operator<<(std::ostream& os, const Callable* expr);
};

#endif  // CALLABLE_H
