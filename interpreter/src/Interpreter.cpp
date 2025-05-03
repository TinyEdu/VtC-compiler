#include "Interpreter.h"

#include "Interpreter/BaseInterpreter.h"

std::string Interpreter::execute(const std::vector<std::shared_ptr<Statement>>& statements)
{
    BaseInterpreter interpreter;
    interpreter.interpret(statements);

    // @TODO: capture std::cout output and return it
    return "executed.";
}
