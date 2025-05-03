#ifndef CALLABLE_H
#define CALLABLE_H

#include <memory>
#include <vector>

class BaseInterpreter;
class Expression;

class Callable
{
public:
    Callable();
    virtual ~Callable();

    virtual int arity() = 0;
    virtual std::shared_ptr<Expression> call(BaseInterpreter& interpreter,
                                             const std::vector<std::shared_ptr<Expression>>& arguments) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Callable& expr);
    friend std::ostream& operator<<(std::ostream& os, const Callable* expr);
};

#endif  // CALLABLE_H
