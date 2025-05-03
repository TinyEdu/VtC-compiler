#ifndef CLOCKFUNCTION_H
#define CLOCKFUNCTION_H

#include "Callable/Callable.h"
#include <memory>
#include <vector>

class ClockCallable final : public Callable
{
public:
    ClockCallable();
    ~ClockCallable() override;

    int arity() override;
    std::shared_ptr<Expression>
    call(BaseInterpreter& interpreter, const std::vector<std::shared_ptr<Expression>>& arguments) override;
};

#endif  // CLOCKFUNCTION_H
