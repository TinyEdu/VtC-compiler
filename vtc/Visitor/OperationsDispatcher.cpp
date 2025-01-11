#include "Visitor/OperationsDispatcher.h"

#include "Expressions/ExpressionsWorld.h"

// Function: add
std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralInt | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralDouble> left,
                                                   std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralDouble | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralFloat> left,
                                                   std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralFloat | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralString> left,
                                                   std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralString | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralBool> left,
                                                   std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralBool | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralInt> left,
                                                   std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralInt | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralDouble> left,
                                                   std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralDouble | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralFloat> left,
                                                   std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralFloat | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralString> left,
                                                   std::shared_ptr<LiteralString> right)
{
    return std::make_shared<LiteralString>(left->value + right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralBool> left,
                                                   std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralBool | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralInt> left,
                                                   std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralFloat>(left->value + right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralDouble> left,
                                                   std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralDouble>(left->value + right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralFloat> left,
                                                   std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralFloat>(left->value + right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralString> left,
                                                   std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralString | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralBool> left,
                                                   std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralBool | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralInt> left,
                                                   std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value + right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralDouble> left,
                                                   std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value + right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralFloat> left,
                                                   std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value + right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralString> left,
                                                   std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralString | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralBool> left,
                                                   std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralBool | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralInt> left, std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralInt>(left->value + right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralDouble> left,
                                                   std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralDouble>(left->value + right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralFloat> left,
                                                   std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralFloat>(left->value + right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralString> left,
                                                   std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralString | LiteralInt!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::add(std::shared_ptr<LiteralBool> left, std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[add] LiteralBool | LiteralInt!");
    return nullptr;
}


// Function: subtract
std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralInt> left,
                                                        std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralInt | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralDouble> left,
                                                        std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralDouble | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralFloat> left,
                                                        std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralFloat | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralString> left,
                                                        std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralString | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralBool> left,
                                                        std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralBool | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralInt> left,
                                                        std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralInt | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralDouble> left,
                                                        std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralDouble | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralFloat> left,
                                                        std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralFloat | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralString> left,
                                                        std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralString | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralBool> left,
                                                        std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralBool | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralInt> left,
                                                        std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralFloat>(left->value - right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralDouble> left,
                                                        std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralDouble>(left->value - right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralFloat> left,
                                                        std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralFloat>(left->value - right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralString> left,
                                                        std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralString | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralBool> left,
                                                        std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralBool | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralInt> left,
                                                        std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value - right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralDouble> left,
                                                        std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value - right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralFloat> left,
                                                        std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value - right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralString> left,
                                                        std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralString | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralBool> left,
                                                        std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralBool | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralInt> left,
                                                        std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralInt>(left->value - right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralDouble> left,
                                                        std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralDouble>(left->value - right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralFloat> left,
                                                        std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralFloat>(left->value - right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralString> left,
                                                        std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralString | LiteralInt!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::subtract(std::shared_ptr<LiteralBool> left,
                                                        std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[subtract] LiteralBool | LiteralInt!");
    return nullptr;
}


// Function: multiply
std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralInt> left,
                                                        std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralInt>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralDouble> left,
                                                        std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralDouble>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralFloat> left,
                                                        std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralFloat>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralString> left,
                                                        std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralString | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralBool> left,
                                                        std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralBool | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralInt> left,
                                                        std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralInt | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralDouble> left,
                                                        std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralDouble | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralFloat> left,
                                                        std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralFloat | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralString> left,
                                                        std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralString | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralBool> left,
                                                        std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralBool | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralInt> left,
                                                        std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralFloat>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralDouble> left,
                                                        std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralDouble>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralFloat> left,
                                                        std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralFloat>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralString> left,
                                                        std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralString | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralBool> left,
                                                        std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralBool | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralInt> left,
                                                        std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralDouble> left,
                                                        std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralFloat> left,
                                                        std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralString> left,
                                                        std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralString | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralBool> left,
                                                        std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralBool | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralInt> left,
                                                        std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralInt>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralDouble> left,
                                                        std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralDouble>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralFloat> left,
                                                        std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralFloat>(left->value * right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralString> left,
                                                        std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralString | LiteralInt!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::multiply(std::shared_ptr<LiteralBool> left,
                                                        std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[multiply] LiteralBool | LiteralInt!");
    return nullptr;
}


// Function: divide
std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralInt> left,
                                                      std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralInt>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralDouble> left,
                                                      std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralDouble>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralFloat> left,
                                                      std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralFloat>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralString> left,
                                                      std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralString | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralBool> left,
                                                      std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralBool | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralInt> left,
                                                      std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralInt | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralDouble> left,
                                                      std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralDouble | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralFloat> left,
                                                      std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralFloat | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralString> left,
                                                      std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralString | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralBool> left,
                                                      std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralBool | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralInt> left,
                                                      std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralFloat>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralDouble> left,
                                                      std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralDouble>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralFloat> left,
                                                      std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralFloat>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralString> left,
                                                      std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralString | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralBool> left,
                                                      std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralBool | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralInt> left,
                                                      std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralDouble> left,
                                                      std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralFloat> left,
                                                      std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralString> left,
                                                      std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralString | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralBool> left,
                                                      std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralBool | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralInt> left,
                                                      std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralInt>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralDouble> left,
                                                      std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralDouble>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralFloat> left,
                                                      std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralFloat>(left->value / right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralString> left,
                                                      std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralString | LiteralInt!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::divide(std::shared_ptr<LiteralBool> left,
                                                      std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[divide] LiteralBool | LiteralInt!");
    return nullptr;
}


// Function: equal
std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralInt> left,
                                                     std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralDouble> left,
                                                     std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralFloat> left,
                                                     std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralString> left,
                                                     std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[equal] LiteralString | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralBool> left,
                                                     std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralInt> left,
                                                     std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[equal] LiteralInt | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralDouble> left,
                                                     std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[equal] LiteralDouble | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralFloat> left,
                                                     std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[equal] LiteralFloat | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralString> left,
                                                     std::shared_ptr<LiteralString> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralBool> left,
                                                     std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[equal] LiteralBool | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralInt> left,
                                                     std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralDouble> left,
                                                     std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralFloat> left,
                                                     std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralString> left,
                                                     std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[equal] LiteralString | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralBool> left,
                                                     std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[equal] LiteralBool | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralInt> left,
                                                     std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralDouble> left,
                                                     std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralFloat> left,
                                                     std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralString> left,
                                                     std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[equal] LiteralString | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralBool> left,
                                                     std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[equal] LiteralBool | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralInt> left,
                                                     std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralDouble> left,
                                                     std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralFloat> left,
                                                     std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value == right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralString> left,
                                                     std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[equal] LiteralString | LiteralInt!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::equal(std::shared_ptr<LiteralBool> left,
                                                     std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[equal] LiteralBool | LiteralInt!");
    return nullptr;
}


// Function: not_equal
std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralInt> left,
                                                         std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralDouble> left,
                                                         std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralFloat> left,
                                                         std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralString> left,
                                                         std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[not_equal] LiteralString | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralBool> left,
                                                         std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralInt> left,
                                                         std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[not_equal] LiteralInt | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralDouble> left,
                                                         std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[not_equal] LiteralDouble | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralFloat> left,
                                                         std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[not_equal] LiteralFloat | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralString> left,
                                                         std::shared_ptr<LiteralString> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralBool> left,
                                                         std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[not_equal] LiteralBool | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralInt> left,
                                                         std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralDouble> left,
                                                         std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralFloat> left,
                                                         std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralString> left,
                                                         std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[not_equal] LiteralString | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralBool> left,
                                                         std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[not_equal] LiteralBool | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralInt> left,
                                                         std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralDouble> left,
                                                         std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralFloat> left,
                                                         std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralString> left,
                                                         std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[not_equal] LiteralString | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralBool> left,
                                                         std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[not_equal] LiteralBool | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralInt> left,
                                                         std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralDouble> left,
                                                         std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralFloat> left,
                                                         std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value != right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralString> left,
                                                         std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[not_equal] LiteralString | LiteralInt!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::not_equal(std::shared_ptr<LiteralBool> left,
                                                         std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[not_equal] LiteralBool | LiteralInt!");
    return nullptr;
}


// Function: greater_than
std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralInt> left,
                                                            std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralDouble> left,
                                                            std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralFloat> left,
                                                            std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralString> left,
                                                            std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[greater_than] LiteralString | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralBool> left,
                                                            std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralInt> left,
                                                            std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[greater_than] LiteralInt | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralDouble> left,
                                                            std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[greater_than] LiteralDouble | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralFloat> left,
                                                            std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[greater_than] LiteralFloat | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralString> left,
                                                            std::shared_ptr<LiteralString> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralBool> left,
                                                            std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[greater_than] LiteralBool | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralInt> left,
                                                            std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralDouble> left,
                                                            std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralFloat> left,
                                                            std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralString> left,
                                                            std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[greater_than] LiteralString | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralBool> left,
                                                            std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[greater_than] LiteralBool | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralInt> left,
                                                            std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralDouble> left,
                                                            std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralFloat> left,
                                                            std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralString> left,
                                                            std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[greater_than] LiteralString | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralBool> left,
                                                            std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[greater_than] LiteralBool | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralInt> left,
                                                            std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralDouble> left,
                                                            std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralFloat> left,
                                                            std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value > right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralString> left,
                                                            std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[greater_than] LiteralString | LiteralInt!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than(std::shared_ptr<LiteralBool> left,
                                                            std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[greater_than] LiteralBool | LiteralInt!");
    return nullptr;
}


// Function: less_than
std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralInt> left,
                                                         std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralDouble> left,
                                                         std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralFloat> left,
                                                         std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralString> left,
                                                         std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[less_than] LiteralString | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralBool> left,
                                                         std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralInt> left,
                                                         std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[less_than] LiteralInt | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralDouble> left,
                                                         std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[less_than] LiteralDouble | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralFloat> left,
                                                         std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[less_than] LiteralFloat | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralString> left,
                                                         std::shared_ptr<LiteralString> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralBool> left,
                                                         std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[less_than] LiteralBool | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralInt> left,
                                                         std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralDouble> left,
                                                         std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralFloat> left,
                                                         std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralString> left,
                                                         std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[less_than] LiteralString | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralBool> left,
                                                         std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[less_than] LiteralBool | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralInt> left,
                                                         std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralDouble> left,
                                                         std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralFloat> left,
                                                         std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralString> left,
                                                         std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[less_than] LiteralString | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralBool> left,
                                                         std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[less_than] LiteralBool | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralInt> left,
                                                         std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralDouble> left,
                                                         std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralFloat> left,
                                                         std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value < right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralString> left,
                                                         std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[less_than] LiteralString | LiteralInt!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than(std::shared_ptr<LiteralBool> left,
                                                         std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[less_than] LiteralBool | LiteralInt!");
    return nullptr;
}


// Function: greater_than_or_equal
std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                                     std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                                     std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                                     std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralString> left,
                                                                     std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralString | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                                     std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                                     std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralInt | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                                     std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralDouble | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                                     std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralFloat | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralString> left,
                                                                     std::shared_ptr<LiteralString> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                                     std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralBool | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                                     std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                                     std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                                     std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralString> left,
                                                                     std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralString | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                                     std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralBool | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                                     std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                                     std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                                     std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralString> left,
                                                                     std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralString | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                                     std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralBool | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                                     std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                                     std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                                     std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value >= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralString> left,
                                                                     std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralString | LiteralInt!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::greater_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                                     std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralBool | LiteralInt!");
    return nullptr;
}


// Function: less_than_or_equal
std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                                  std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                                  std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                                  std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralString> left,
                                                                  std::shared_ptr<LiteralBool> right)
{
    throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralString | LiteralBool!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                                  std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                                  std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralInt | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                                  std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralDouble | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                                  std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralFloat | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralString> left,
                                                                  std::shared_ptr<LiteralString> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                                  std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralBool | LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                                  std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                                  std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                                  std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralString> left,
                                                                  std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralString | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                                  std::shared_ptr<LiteralFloat> right)
{
    throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralBool | LiteralFloat!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                                  std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                                  std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                                  std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralString> left,
                                                                  std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralString | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                                  std::shared_ptr<LiteralDouble> right)
{
    throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralBool | LiteralDouble!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralInt> left,
                                                                  std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralDouble> left,
                                                                  std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralFloat> left,
                                                                  std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralBool>(left->value <= right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralString> left,
                                                                  std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralString | LiteralInt!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::less_than_or_equal(std::shared_ptr<LiteralBool> left,
                                                                  std::shared_ptr<LiteralInt> right)
{
    throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralBool | LiteralInt!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::negate(std::shared_ptr<LiteralInt> right)
{
    return std::make_shared<LiteralInt>(-right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::negate(std::shared_ptr<LiteralFloat> right)
{
    return std::make_shared<LiteralFloat>(-right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::negate(std::shared_ptr<LiteralString> right)
{
    throw std::runtime_error("Illegal operation[negate] LiteralString!");
    return nullptr;
}

std::shared_ptr<Literal> OperationsDispatcher::negate(std::shared_ptr<LiteralBool> right)
{
    return std::make_shared<LiteralBool>(!right->value);
}

std::shared_ptr<Literal> OperationsDispatcher::negate(std::shared_ptr<LiteralDouble> right)
{
    return std::make_shared<LiteralDouble>(-right->value);
}
