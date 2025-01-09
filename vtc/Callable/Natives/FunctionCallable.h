#ifndef FUNCTIONCALLABLE_H
#define FUNCTIONCALLABLE_H

#include "Callable/Callable.h"

// Forward declaration
class FunctionStatement;


class FunctionCallable final : public Callable
{
public:
    explicit FunctionCallable(FunctionStatement* declaration);

    ~FunctionCallable() override = default;;

    int arity() override;
    std::any call(Interpreter* interpreter, std::span<Expression* const> arguments) override;

    friend std::ostream& operator<<(std::ostream& os, const FunctionCallable& expr);
    friend std::ostream& operator<<(std::ostream& os, const FunctionCallable* expr);

private:
    FunctionStatement* declaration;
};

#endif  // FUNCTIONCALLABLE_H
