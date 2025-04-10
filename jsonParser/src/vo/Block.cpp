#include "Block.h"

#include "../BlockExtractor/ReachedEnd.h"
#include <Expressions/Literals/LiteralString.h>
#include "Statements/PrintStatement.h"

#include <QJsonObject>
#include <QString>
#include <Expressions/Unary.h>

#include "Statements/ExpressionStatement.h"

static std::string getStringField(const QJsonObject& obj, const char* key) {
    return obj.value(key).toString().toStdString();
}

// ------------------------------------------------------------
void Break::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);
}

std::shared_ptr<Statement> Break::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    // Build an AST node corresponding to a break statement.
    return nullptr;
}

// ------------------------------------------------------------
void Call::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);
}

std::shared_ptr<Statement> Call::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    return nullptr;
}

// ------------------------------------------------------------
void CreateVar::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);

    std::string rightUuid = getStringField(obj, "rightAnchor");
    right = new Anchor(rightUuid, this);

    variableName = getStringField(obj, "variable");

    QString blockType = obj.value("blockType").toString();
    QString valueField = obj.value("value").toString();
    if (blockType == "CreateVarBySignal") {
        value = new Anchor(valueField.toStdString(), this);
    } else {
        value = valueField.toStdString();
    }
}

std::shared_ptr<Statement> CreateVar::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    return nullptr;
}

// ------------------------------------------------------------
void End::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);
}

std::shared_ptr<Statement> End::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    throw ReachedEnd("End block reached");
}

// ------------------------------------------------------------
void ForLoop::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);

    std::string rightUuid = getStringField(obj, "rightAnchor");
    right = new Anchor(rightUuid, this);

    from = getStringField(obj, "fromField");
    to = getStringField(obj, "toField");
    increment = getStringField(obj, "incrementField");

    std::string startUuid = getStringField(obj, "startAnchor");
    start = new Anchor(startUuid, this);

    std::string endUuid = getStringField(obj, "endAnchor");
    end = new Anchor(endUuid, this);

    if (!increment.empty())
        inc = new Anchor(increment, this);
    else
        inc = nullptr;
}

std::shared_ptr<Statement> ForLoop::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    return nullptr;
}

// ------------------------------------------------------------
// GetVar
void GetVar::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string passingUuid = getStringField(obj, "passingAnchor");
    passing = new Anchor(passingUuid, this);
    variableName = getStringField(obj, "variable");
}

std::shared_ptr<Statement> GetVar::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    return nullptr;
}

// ------------------------------------------------------------
void If::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);

    std::string trueUuid = getStringField(obj, "trueAnchor");
    trueAnchor = new Anchor(trueUuid, this);

    std::string falseUuid = getStringField(obj, "falseAnchor");
    falseAnchor = new Anchor(falseUuid, this);

    std::string condUuid = getStringField(obj, "condition");
    condition = new Anchor(condUuid, this);
}

std::shared_ptr<Statement> If::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    // Build an AST node representing a conditional.
    return nullptr;
}

// ------------------------------------------------------------
void Listen::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string rightUuid = getStringField(obj, "rightAnchor");
    right = new Anchor(rightUuid, this);
    variableName = getStringField(obj, "variableName");
}

std::shared_ptr<Statement> Listen::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    return nullptr;
}

// ------------------------------------------------------------
void Print::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);

    std::string rightUuid = getStringField(obj, "rightAnchor");
    right = new Anchor(rightUuid, this);

    QString blockType = obj.value("blockType").toString();
    QString valueField = obj.value("value").toString();
    if (blockType == "PrintBySignal") {
        value = new Anchor(valueField.toStdString(), this);
    } else { // PrintByValue: store literal string.
        value = valueField.toStdString();
    }
}

std::shared_ptr<Statement> Print::buildAST(std::vector<std::shared_ptr<Statement>>& result)
{
    if (this->name == "PrintBySignal")
    {
        Anchor const* anchorPtr = std::get<Anchor*>(this->value);
        Block* block = Anchor::getNextBlock(*anchorPtr);

        const std::shared_ptr<Statement> expr = block->buildAST(result);
        const std::shared_ptr<ExpressionStatement> exprStatement = std::dynamic_pointer_cast<
            ExpressionStatement>(expr);
        const auto statement = std::make_shared<PrintStatement>(exprStatement->expression);
        result.push_back(statement);

        return runNext(result, right);
    }
    else if (this->name == "PrintByValue")
    {
        auto strVal = std::get<std::string>(this->value);
        std::shared_ptr<Expression> expr = std::make_shared<LiteralString>(strVal);

        auto statement = std::make_shared<PrintStatement>(expr);
        result.push_back(statement);

        return runNext(result, right);
    }

    throw std::runtime_error("Unknown print block type");
}

// ------------------------------------------------------------
void SetVar::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);

    std::string rightUuid = getStringField(obj, "rightAnchor");
    right = new Anchor(rightUuid, this);

    variableName = getStringField(obj, "variable");

    QString blockType = obj.value("blockType").toString();
    QString valueField = obj.value("value").toString();
    if (blockType == "SetVarBySignal") {
        value = new Anchor(valueField.toStdString(), this);
    } else { // Otherwise store as literal value.
        value = valueField.toStdString();
    }
}

std::shared_ptr<Statement> SetVar::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    return nullptr;
}

// ------------------------------------------------------------
void Skip::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);
}

std::shared_ptr<Statement> Skip::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    return nullptr;
}

// ------------------------------------------------------------
void Start::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string rightUuid = getStringField(obj, "rightAnchor");
    right = new Anchor(rightUuid, this);
}

std::shared_ptr<Statement> Start::buildAST(std::vector<std::shared_ptr<Statement>>& result)
{
    return runNext(result, right);
}

// ------------------------------------------------------------
void Value::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string passingUuid = getStringField(obj, "passingAnchor");
    passing = new Anchor(passingUuid, this);
    valueStr = getStringField(obj, "value");
}

std::shared_ptr<Statement> Value::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    auto literal = std::make_shared<LiteralString>(valueStr);
    auto expr = std::make_shared<ExpressionStatement>(literal);

    return expr;
}

// ------------------------------------------------------------
void While::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);

    std::string rightUuid = getStringField(obj, "rightAnchor");
    right = new Anchor(rightUuid, this);

    std::string condUuid = getStringField(obj, "condition");
    condition = new Anchor(condUuid, this);

    std::string startUuid = getStringField(obj, "startAnchor");
    start = new Anchor(startUuid, this);

    std::string endUuid = getStringField(obj, "endAnchor");
    end = new Anchor(endUuid, this);
}

std::shared_ptr<Statement> While::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    return nullptr;
}

// ------------------------------------------------------------
void BinaryOp::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);

    std::string rightUuid = getStringField(obj, "rightAnchor");
    right = new Anchor(rightUuid, this);

    std::string leftInputUuid = getStringField(obj, "leftInputValue");
    leftInputValue = new Anchor(leftInputUuid, this);

    std::string rightInputUuid = getStringField(obj, "rightInputValue");
    rightInputValue = new Anchor(rightInputUuid, this);

    operation = getStringField(obj, "operation");

    std::string outputUuid = getStringField(obj, "outputValue");
    outputValue = new Anchor(outputUuid, this);
}

std::shared_ptr<Statement> BinaryOp::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    return nullptr;
}

// ------------------------------------------------------------
void UnaryOp::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string leftUuid = getStringField(obj, "leftAnchor");
    left = new Anchor(leftUuid, this);

    std::string rightUuid = getStringField(obj, "rightAnchor");
    right = new Anchor(rightUuid, this);

    std::string inputUuid = getStringField(obj, "inputValue");
    inputValue = new Anchor(inputUuid, this);

    operation = getStringField(obj, "operation");

    std::string outputUuid = getStringField(obj, "outputValue");
    outputValue = new Anchor(outputUuid, this);
}

std::shared_ptr<Statement> UnaryOp::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    // input value
    Block* block = Anchor::getNextBlock(*this->inputValue);
    const std::shared_ptr<Statement> expr = block->buildAST(result);
    const auto exprStatement = std::dynamic_pointer_cast<ExpressionStatement>(expr);
    const auto inputValueStmt = std::make_shared<ExpressionStatement>(exprStatement->expression);

    // output value
    Block* block2 = Anchor::getNextBlock(*this->inputValue);
    const std::shared_ptr<Statement> expr2 = block2->buildAST(result);
    const auto exprStatement2 = std::dynamic_pointer_cast<ExpressionStatement>(expr2);
    const auto outputValueStmt = std::make_shared<ExpressionStatement>(exprStatement2->expression);

    // operation  -  ["negate", "not"]
    auto op = Token(operation == "negate" ? TokenType::MINUS : TokenType::BANG, operation, "", 0);

    auto unary = std::make_shared<Unary>(op, inputValueStmt->expression);

    std::shared_ptr<Statement> statement = std::make_shared<ExpressionStatement>(unary);
    result.push_back(statement);

    return runNext(result, right);
}
