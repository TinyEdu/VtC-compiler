#include "Interpreter.h"

#include "LogManager/LogManager.h"
#include "Token/Token.h"
#include "Compiler/Compiler.h"

#include "Callable/Callable.h"
#include "Callable/Return.h"
#include "Callable/Natives/ClockCallable.h"
#include "Callable/Natives/FunctionCallable.h"

#include "ArityMismatchException.h"
#include "NonBooleanConditionException.h"
#include "MissingInitializerException.h"

#include <any>
#include <iostream>


Interpreter::Interpreter()
{
    environment = std::make_shared<Environment>();

    // define a builtin clock function
    environment->define("clock", std::make_shared<ClockCallable>());
}

Interpreter::~Interpreter() = default;

std::shared_ptr<Expression> Interpreter::evaluateExpression(const std::shared_ptr<Expression>& expression)
{
    return expression->accept(*this);
}

std::shared_ptr<Literal> Interpreter::evaluateLiteral(const std::shared_ptr<Expression>& expression)
{
    // Evaluate the expression first
    auto result = expression->accept(*this);

    // Check if the result is a Literal
    auto castedResult = std::dynamic_pointer_cast<Literal>(result);
    if (!castedResult)
    {
        // Handle non-literal results by recursively evaluating them
        if (auto binaryExpr = std::dynamic_pointer_cast<Binary>(result))
        {
            return evaluateLiteral(binaryExpr);
        }
        else if (auto variableExpr = std::dynamic_pointer_cast<Variable>(result))
        {
            return environment->lookup<std::shared_ptr<Literal>>(variableExpr->name.lexeme);
        }
        else if (auto callExpr = std::dynamic_pointer_cast<Call>(result))
        {
            auto callResult = callExpr->accept(*this);
            return std::dynamic_pointer_cast<Literal>(callResult);
        }
        else
        {
            throw std::runtime_error("evaluateLiteral: Invalid cast, type mismatch. Result is not a Literal.");
        }
    }

    return castedResult;
}

void Interpreter::interpret(const std::shared_ptr<Expression>& expression)
{
    try
    {
        const auto value = evaluateLiteral(expression);

        LogManager::log() << value;
    }
    catch (std::runtime_error& e)
    {
        Compiler::runtimeError(e);
    }
}

void Interpreter::interpret(const std::vector<std::shared_ptr<Statement>>& statements)
{
    try
    {
        for (auto& statement : statements)
        {
            statement->accept(this);
        }
    }
    catch (std::exception& e)
    {
        LogManager::crit() << e.what();
    }
}


void Interpreter::execute(const std::vector<std::shared_ptr<Statement>>& statements,
                          const std::shared_ptr<Environment>& env)
{
    const std::shared_ptr<Environment> previous = environment;
    /*
    Manually changing and restoring a mutable environment field feels inelegant.
    Another classic approach is to explicitly pass the environment as a parameter to each visit method.
    To “change” the environment, you pass a different one as you recurse down the tree.
    You don’t have to restore the old one, since the new one lives on the Java stack and
    is implicitly discarded when the interpreter returns from the block’s visit method.

    ~ https://craftinginterpreters.com/statements-and-state.html
    */

    environment = env;

    // Execute the block
    for (auto& statement : statements)
    {
        statement->accept(this);
    }

    environment = previous;
}

void Interpreter::execute(const std::shared_ptr<Statement>& statement)
{
    statement->accept(this);
}

// ______________________________________________________________

std::shared_ptr<Expression> Interpreter::visit(std::shared_ptr<Assign> expression)
{
    const auto value = evaluateLiteral(expression->value);
    environment->assign(expression->name.lexeme, value);
    return value;
}

std::shared_ptr<Expression> Interpreter::visit(std::shared_ptr<Binary> expression)
{
    const auto left = evaluateLiteral(expression->left);
    const auto right = evaluateLiteral(expression->right);

    const auto result = left->process(right, expression->op);

    return result;
}

std::shared_ptr<Expression> Interpreter::visit(std::shared_ptr<Literal> expression)
{
    return expression;
}

std::shared_ptr<Expression> Interpreter::visit(std::shared_ptr<Grouping> expression)
{
    return evaluateLiteral(expression->expression);
}

std::shared_ptr<Expression> Interpreter::visit(std::shared_ptr<Unary> expression)
{
    const auto right = evaluateLiteral(expression->right);

    switch (expression->op.type)
    {
    case TokenType::BANG:
    case TokenType::MINUS:
        return std::shared_ptr(right->process(expression->op));
    default:
        break;
    }

    LogManager::log() << "Unreachable code reached in Interpreter::visit(Unary* expr) ";
    return {};
}

std::shared_ptr<Expression> Interpreter::visit(std::shared_ptr<Variable> expression)
{
    return std::any_cast<std::shared_ptr<Expression>>(
        environment->lookup<std::shared_ptr<Expression>>(expression->name.lexeme));
}

std::shared_ptr<Expression> Interpreter::visit(std::shared_ptr<Logical> expression)
{
    const auto left = evaluateLiteral(expression->left);

    if (expression->op.type == TokenType::OR)
    {
        if (left)
        {
            return left;
        }
    }
    else
    {
        if (!left)
        {
            return left;
        }
    }

    return evaluateLiteral(expression->right);
}

std::shared_ptr<Expression> Interpreter::visit(std::shared_ptr<Call> expression)
{
    // Look up the function
    const auto variableExpr = std::dynamic_pointer_cast<Variable>(expression->callee);
    if (!variableExpr)
    {
        throw std::runtime_error("Callee is not a variable.");
    }

    const std::string functionName = variableExpr->name.lexeme;
    auto callableOpt = environment->lookup<std::shared_ptr<Callable>>(functionName);

    if (!callableOpt)
    {
        throw EnvironmentException("Function '" + functionName + "' is not defined.");
    }

    std::shared_ptr<Callable> function = callableOpt;

    std::vector<std::shared_ptr<Expression>> arguments;

    for (const auto& argument : expression->arguments)
    {
        arguments.push_back(evaluateLiteral(argument));
    }

    // Validate argument count
    if (arguments.size() != function->arity())
    {
        throw ArityMismatchException(
            std::format("Expected {} arguments but got {}.", function->arity(), arguments.size())
        );
    }

    return function->call(*this, arguments);
}

std::any Interpreter::visit(std::shared_ptr<IfStatement> statement)
{
    const auto r = evaluateLiteral(statement->condition);

    // check if is a LiteralBool
    if (const auto lb = std::dynamic_pointer_cast<LiteralBool>(r))
    {
        if (lb->value)
        {
            execute(statement->thenBranch);
        }
        else if (statement->elseBranch != nullptr)
        {
            execute(statement->elseBranch);
        }
    }
    else
    {
        throw NonBooleanConditionException("If statement condition must be possible to evaluate as a boolean.");
    }

    return {};
}

std::any Interpreter::visit(std::shared_ptr<ExpressionStatement> statement)
{
    evaluateLiteral(statement->expression);

    return {};
}

std::any Interpreter::visit(std::shared_ptr<PrintStatement> statement)
{
    std::stringstream ss;
    const auto lit = evaluateLiteral(statement->expression);

    if (const auto literal_string = std::dynamic_pointer_cast<LiteralString>(lit))
    {
        ss << literal_string->value;
    }
    else if (const auto literal_int = std::dynamic_pointer_cast<LiteralInt>(lit))
    {
        ss << literal_int->value;
    }
    else if (const auto literal_bool = std::dynamic_pointer_cast<LiteralBool>(lit))
    {
        if (literal_bool->value)
        {
            ss << "true";
        }
        else
        {
            ss << "false";
        }
    }
    else if (const auto literal_float = std::dynamic_pointer_cast<LiteralFloat>(lit))
    {
        ss << literal_float->value;
    }
    else if (const auto literal_double = std::dynamic_pointer_cast<LiteralDouble>(lit))
    {
        ss << literal_double->value;
    }
    else
    {
        ss << "Unknown type";
    }

    std::cout << "print: " << ss.str() << "\n";
    return {};
}

std::any Interpreter::visit(std::shared_ptr<VarStatement> statement)
{
    if (statement->initializer != nullptr)
    {
        const auto value = evaluateLiteral(statement->initializer);
        environment->define(statement->name.lexeme, value);
    }
    else
    {
        throw MissingInitializerException("Variable declaration without an initializer");
    }

    return {};
}

std::any Interpreter::visit(std::shared_ptr<BlockStatement> statement)
{
    auto newEnv = std::make_shared<Environment>(environment);

    execute(statement->statements, newEnv);

    return {};
}

std::any Interpreter::visit(std::shared_ptr<FunctionStatement> statement)
{
    const auto function = std::make_shared<FunctionCallable>(statement);

    environment->define(statement->name.lexeme, function);

    return {};
}

std::any Interpreter::visit(std::shared_ptr<ClassStatement> statement)
{
    return {};
}

std::any Interpreter::visit(std::shared_ptr<WhileStatement> statement)
{
    while (std::dynamic_pointer_cast<LiteralBool>(evaluateLiteral(statement->condition))->value)
    {
        execute(statement->body);
    }

    return {};
}

std::any Interpreter::visit(std::shared_ptr<ReturnStatement> statement)
{
    if (statement->value != nullptr)
    {
        throw Return(evaluateLiteral(statement->value));
    }

    return 0;
}
