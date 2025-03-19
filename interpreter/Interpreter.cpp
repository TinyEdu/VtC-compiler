#include "Interpreter.h"

#include <iostream>

std::string Interpreter::execute(const std::vector<std::shared_ptr<Statement>>& statements)
{
    std::cout << "Interpreter::execute\n";
    return "Hello, World!";
}
