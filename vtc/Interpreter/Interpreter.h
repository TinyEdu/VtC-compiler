#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Environment/Environment.h"
#include "Visitor/Visitor.h"


class Interpreter final : public Visitor, public StatementVisitor
{
public:
    Interpreter();
    ~Interpreter() override;

    Environment* environment;

    // ------------------------------------------------
    // Visitor Interface Methods
    // ------------------------------------------------

    std::any visit(Assign* expression) override;
    std::any visit(Binary* expression) override;
    std::any visit(Grouping* expression) override;
    std::any visit(Literal* expression) override;
    std::any visit(Unary* expression) override;
    std::any visit(Variable* expression) override;
    std::any visit(Logical* expression) override;
    std::any visit(Call* expression) override;

    std::any visit(ExpressionStatement* statement) override;
    std::any visit(IfStatement* statement) override;
    std::any visit(PrintStatement* statement) override;
    std::any visit(VarStatement* statement) override;
    std::any visit(BlockStatement* statement) override;
    std::any visit(FunctionStatement* statement) override;
    std::any visit(ClassStatement* statement) override;
    std::any visit(WhileStatement* statement) override;
    std::any visit(ReturnStatement* statement) override;

    // ------------------------------------------------

    template <typename T>
    T evaluate(Expression* expr);

    std::any evaluate(Expression* statement);

    void interpret(Expression* expression);
    void interpret(const std::vector<Statement*>& statements);
    void executeBlock(const std::vector<Statement*>& statements, Environment* env);
    void execute(Statement* statement);
};

#endif  // INTERPRETER_H
