#ifndef FUNCTIONCALLABLE_H
#define FUNCTIONCALLABLE_H

#include "Callable/Callable.h"
#include <memory>
#include <vector>

class FunctionStatement;

class FunctionCallable final : public Callable
{
public:
    explicit FunctionCallable(std::shared_ptr<FunctionStatement> declaration);
    ~FunctionCallable() override = default;

    int arity() override;
    std::shared_ptr<Expression>
    call(BaseInterpreter& interpreter, const std::vector<std::shared_ptr<Expression>>& arguments) override;

    friend std::ostream& operator<<(std::ostream& os, const FunctionCallable& expr);
    friend std::ostream& operator<<(std::ostream& os, const FunctionCallable* expr);

private:
    std::shared_ptr<FunctionStatement> declaration;
};

#endif  // FUNCTIONCALLABLE_H
