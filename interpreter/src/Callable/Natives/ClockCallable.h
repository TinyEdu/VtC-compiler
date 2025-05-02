#ifndef CLOCKFUNCTION_H
#define CLOCKFUNCTION_H

#include "Callable/Callable.h"


class ClockCallable final : public Callable
{
public:
    ClockCallable();
    ~ClockCallable() override;

    int arity() override;
    std::shared_ptr<Expression>
    call(Interpreter& interpreter, std::span<std::shared_ptr<Expression> const> arguments) override;
};

#endif  // CLOCKFUNCTION_H
