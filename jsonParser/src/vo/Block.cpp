#include "Block.h"

#include <charconv>

#include "../BlockExtractor/ReachedEnd.h"
#include <Expressions/Literals/LiteralString.h>
#include "Statements/PrintStatement.h"

#include <QJsonObject>
#include <QString>
#include <Expressions/Binary.h>
#include <Expressions/Unary.h>
#include <Expressions/Variable.h>
#include <Expressions/Literals/LiteralBool.h>
#include <Expressions/Literals/LiteralDouble.h>
#include <Expressions/Literals/LiteralInt.h>

#include "Statements/ExpressionStatement.h"
#include "Statements/VarStatement.h"

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
    if (this->name == "CreateVarBySignal")
    {
        Block* nextBlock = Anchor::getNextBlock(*std::get<Anchor*>(this->value));

        const std::shared_ptr<Statement> parsedNextExpression = nextBlock->buildAST(result);
        const std::shared_ptr<ExpressionStatement> exprStatement =
            std::dynamic_pointer_cast<ExpressionStatement>(parsedNextExpression);
        const auto statement = std::make_shared<VarStatement>(Token(TokenType::IDENTIFIER,
            this->variableName, "", 1), exprStatement->expression);

        result.push_back(statement);
        return runNext(result, right);
    }

    if (this->name == "CreateVarByValue")
    {
        std::string value;
        if (const std::string* strPtr = std::get_if<std::string>(&this->value)) {
            value = *strPtr;
        }

        // @TODO: THIS VALUE NEEDS TO BE PARSED TO A CORRECT LITERAL TYPE

        const auto statement = std::make_shared<VarStatement>(Token(TokenType::IDENTIFIER,
            this->variableName, "", 1),
            std::make_shared<LiteralString>(value));

        result.push_back(statement);
        return runNext(result, right);
    }

    throw std::runtime_error("Unknown CreateVar block type");
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
    auto literal = std::make_shared<Variable>(Token(TokenType::VAR, this->variableName, "", 1));
    auto expr = std::make_shared<ExpressionStatement>(literal);

    return expr;
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
        Block* nextBlock = Anchor::getNextBlock(*std::get<Anchor*>(this->value));

        const std::shared_ptr<Statement> expr = nextBlock->buildAST(result);
        const std::shared_ptr<ExpressionStatement> exprStatement =
            std::dynamic_pointer_cast<ExpressionStatement>(expr);
        const auto statement = std::make_shared<PrintStatement>(exprStatement->expression);

        result.push_back(statement);
        return runNext(result, right);
    }

    if (this->name == "PrintByValue")
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

bool isBool(const std::string& s, bool& out) {
    if (s == "true") { out = true; return true; }
    if (s == "false") { out = false; return true; }
    return false;
}

bool isInt(const std::string& s, int& out) {
    auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), out);
    return ec == std::errc() && ptr == s.data() + s.size();
}

bool isDouble(const std::string& s, double& out) {
    char* end;
    out = std::strtod(s.c_str(), &end);
    return end == s.c_str() + s.size();
}

std::shared_ptr<Statement> Value::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    std::shared_ptr<Expression> expr;

    bool bval;
    int ival;
    double dval;

    if (isBool(this->valueStr, bval)) {
        expr = std::make_shared<LiteralBool>(bval);
    } else if (isInt(this->valueStr, ival)) {
        expr = std::make_shared<LiteralInt>(ival);
    } else if (isDouble(this->valueStr, dval)) {
        expr = std::make_shared<LiteralDouble>(dval);
    } else {
        expr = std::make_shared<LiteralString>(this->valueStr);
    }

    return std::make_shared<ExpressionStatement>(expr);
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

const std::map<std::string, TokenType> operationMapper = {
    {"add", TokenType::PLUS},
    {"subtract", TokenType::MINUS},
    {"divide", TokenType::SLASH},
    {"multiply", TokenType::STAR},
    {"==", TokenType::EQUAL_EQUAL},
    {">=", TokenType::GREATER_EQUAL},
    {"<", TokenType::LESS},
    {"<=", TokenType::LESS_EQUAL},
    {"and", TokenType::AND},
    {"or", TokenType::OR},
    {"mod", TokenType::MODULO}
};

std::shared_ptr<Statement> BinaryOp::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    // left input value
    const std::shared_ptr<Statement> leftInputExpression = Anchor::getNextBlock(*this->leftInputValue)->buildAST(result);
    const auto leftInputStatement = std::dynamic_pointer_cast<ExpressionStatement>(leftInputExpression);

    // right input value
    const std::shared_ptr<Statement> rightInputExpression = Anchor::getNextBlock(*this->rightInputValue)->buildAST(result);
    const auto rightInputStatement = std::dynamic_pointer_cast<ExpressionStatement>(rightInputExpression);

    // operations
    auto op = Token(operationMapper.at(this->operation), operation, "", 0);
    auto binary = std::make_shared<Binary>(leftInputStatement->expression, op, rightInputStatement->expression);

    return std::make_shared<ExpressionStatement>(binary);
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
    const std::shared_ptr<Statement> inputExpression = Anchor::getNextBlock(*this->inputValue)->buildAST(result);
    const auto inputStatement = std::dynamic_pointer_cast<ExpressionStatement>(inputExpression);

    // operations
    auto op = Token(operation == "negate" ? TokenType::MINUS : TokenType::BANG, operation, "", 0);
    auto binary = std::make_shared<Unary>(op, inputStatement->expression);

    return std::make_shared<ExpressionStatement>(binary);
}
