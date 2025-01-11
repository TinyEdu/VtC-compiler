#ifndef VISITOR_H
#define VISITOR_H

#include <Expressions/ExpressionsWorld.h>
#include <Statements/StatementsWorld.h>

#include <any>
#include <memory>

class BaseVisitor
{
public:
    virtual ~BaseVisitor() = default;
};

class Visitor : public BaseVisitor
{
public:
    virtual std::shared_ptr<Expression> visit(std::shared_ptr<Assign> expr) = 0;
    virtual std::shared_ptr<Expression> visit(std::shared_ptr<Binary> expr) = 0;
    virtual std::shared_ptr<Expression> visit(std::shared_ptr<Grouping> expr) = 0;
    virtual std::shared_ptr<Expression> visit(std::shared_ptr<Literal> expr) = 0;
    virtual std::shared_ptr<Expression> visit(std::shared_ptr<Unary> expr) = 0;
    virtual std::shared_ptr<Expression> visit(std::shared_ptr<Variable> expr) = 0;
    virtual std::shared_ptr<Expression> visit(std::shared_ptr<Logical> expr) = 0;
    virtual std::shared_ptr<Expression> visit(std::shared_ptr<Call> expr) = 0;
};

class StatementVisitor : public BaseVisitor
{
public:
    // @TODO: change return type
    virtual std::any visit(std::shared_ptr<ExpressionStatement> statement) = 0;
    virtual std::any visit(std::shared_ptr<IfStatement> statement) = 0;
    virtual std::any visit(std::shared_ptr<PrintStatement> statement) = 0;
    virtual std::any visit(std::shared_ptr<VarStatement> statement) = 0;
    virtual std::any visit(std::shared_ptr<BlockStatement> statement) = 0;
    virtual std::any visit(std::shared_ptr<FunctionStatement> statement) = 0;
    virtual std::any visit(std::shared_ptr<ClassStatement> statement) = 0;
    virtual std::any visit(std::shared_ptr<WhileStatement> statement) = 0;
    virtual std::any visit(std::shared_ptr<ReturnStatement> statement) = 0;
};

#endif  // VISITOR_H
