#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Environment/Environment.h"
#include "Visitor/Visitor.h"

#include <memory>


class Interpreter final : public Visitor, public StatementVisitor
{
public:
    Interpreter();
    ~Interpreter() override;

    std::shared_ptr<Environment> environment;

    // ------------------------------------------------
    // Visitor Interface Methods
    // ------------------------------------------------

    std::shared_ptr<Expression> visit(std::shared_ptr<Assign> expr) override;
    std::shared_ptr<Expression> visit(std::shared_ptr<Binary> expr) override;
    std::shared_ptr<Expression> visit(std::shared_ptr<Grouping> expr) override;
    std::shared_ptr<Expression> visit(std::shared_ptr<Literal> expr) override;
    std::shared_ptr<Expression> visit(std::shared_ptr<Unary> expr) override;
    std::shared_ptr<Expression> visit(std::shared_ptr<Variable> expr) override;
    std::shared_ptr<Expression> visit(std::shared_ptr<Logical> expr) override;
    std::shared_ptr<Expression> visit(std::shared_ptr<Call> expr) override;

    // ------------------------------------------------
    // StatementVisitor Interface Methods
    // ------------------------------------------------

    std::any visit(std::shared_ptr<ExpressionStatement> statement) override;
    std::any visit(std::shared_ptr<IfStatement> statement) override;
    std::any visit(std::shared_ptr<PrintStatement> statement) override;
    std::any visit(std::shared_ptr<VarStatement> statement) override;
    std::any visit(std::shared_ptr<BlockStatement> statement) override;
    std::any visit(std::shared_ptr<FunctionStatement> statement) override;
    std::any visit(std::shared_ptr<ClassStatement> statement) override;
    std::any visit(std::shared_ptr<WhileStatement> statement) override;
    std::any visit(std::shared_ptr<ReturnStatement> statement) override;

    // ------------------------------------------------

    void interpret(const std::shared_ptr<Expression>& expression);
    void interpret(const std::vector<std::shared_ptr<Statement>>& statements);
    void execute(const std::vector<std::shared_ptr<Statement>>& statements, const std::shared_ptr<Environment>& env);
    void execute(const std::shared_ptr<Statement>& statement);

    std::shared_ptr<Expression> evaluateExpression(const std::shared_ptr<Expression>& expression);
    std::shared_ptr<Literal> evaluateLiteral(const std::shared_ptr<Expression>& literal);
};

#endif  // INTERPRETER_H
