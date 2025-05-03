#include "Block.h"

#include <charconv>

#include "../BlockExtractor/ReachedEnd.h"
#include <Expressions/Literals/LiteralString.h>
#include "Statements/PrintStatement.h"

#include <QJsonObject>
#include <QString>
#include <Expressions/Assign.h>
#include <Expressions/Binary.h>
#include <Expressions/Unary.h>
#include <Expressions/Variable.h>
#include <Expressions/Literals/LiteralBool.h>
#include <Expressions/Literals/LiteralDouble.h>
#include <Expressions/Literals/LiteralInt.h>

#include "Statements/BlockStatement.h"
#include "Statements/ExpressionStatement.h"
#include "Statements/IfStatement.h"
#include "Statements/VarStatement.h"
#include "Statements/WhileStatement.h"

static std::string getStringField(const QJsonObject& obj, const char* key) {
    return obj.value(key).toString().toStdString();
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

    eventName = getStringField(obj, "eventName");
}

std::shared_ptr<Statement> Call::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    Listen* listenBlock = Anchor::findCallEventBlock(eventName);
    return runNext(result, listenBlock->right);
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
            this->variableName, ""), exprStatement->expression);

        result.push_back(statement);
        return runNext(result, right);
    }

    if (this->name == "CreateVarByValue")
    {
        std::string value;
        if (const std::string* strPtr = std::get_if<std::string>(&this->value)) {
            value = *strPtr;
        }

        std::shared_ptr<Expression> expr;

        bool bval;
        int ival;
        double dval;

        if (isBool(value, bval)) {
            expr = std::make_shared<LiteralBool>(bval);
        } else if (isInt(value, ival)) {
            expr = std::make_shared<LiteralInt>(ival);
        } else if (isDouble(value, dval)) {
            expr = std::make_shared<LiteralDouble>(dval);
        } else {
            expr = std::make_shared<LiteralString>(value);
        }

        const auto statement = std::make_shared<VarStatement>(
        Token(TokenType::IDENTIFIER, this->variableName, ""), expr);

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

    std::string startUuid = getStringField(obj, "startAnchor");
    start = new Anchor(startUuid, this);

    from = getStringField(obj, "fromField");
    to = getStringField(obj, "toField");
    step = getStringField(obj, "stepField");
    indexName = getStringField(obj, "indexName");
}

std::shared_ptr<Statement> ForLoop::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    // Build initializer
    int fromValue = std::stoi(this->from);
    auto initializer = std::make_shared<VarStatement>(
        Token(TokenType::IDENTIFIER, this->indexName, ""),
        std::make_shared<LiteralInt>(fromValue)
    );

    // Build condition
    int toValue = std::stoi(this->to);
    auto condition = std::make_shared<Binary>(
        std::make_shared<Variable>(Token(TokenType::IDENTIFIER, this->indexName, "")),
        Token(TokenType::LESS_EQUAL, "<=", ""),
        std::make_shared<LiteralInt>(toValue)
    );

    // Build increment
    int stepValue = std::stoi(this->step);
    auto increment = std::make_shared<Assign>(
        Token(TokenType::IDENTIFIER, this->indexName, "", 0),
        std::make_shared<Binary>(
            std::make_shared<Variable>(Token(TokenType::IDENTIFIER, this->indexName, "")),
            Token(TokenType::PLUS, "+", ""),
            std::make_shared<LiteralInt>(stepValue)
        )
    );

    // Build loop body
    std::vector<std::shared_ptr<Statement>> bodyStatements;
    try {
        runNext(bodyStatements, this->start);
    } catch (const ReachedEnd&) {
        // body reached end
    }

    // Add increment at the end of body
    bodyStatements.push_back(std::make_shared<ExpressionStatement>(increment));

    // Wrap body into while loop
    auto whileLoop = std::make_shared<WhileStatement>(condition, std::make_shared<BlockStatement>(bodyStatements));

    // Combine initializer + while into a block
    auto fullLoop = std::make_shared<BlockStatement>(std::vector<std::shared_ptr<Statement>>{
        initializer, whileLoop
    });

    result.push_back(fullLoop);

    return runNext(result, right);
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
    auto literal = std::make_shared<Variable>(Token(TokenType::VAR, this->variableName, ""));
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
    // Build the condition expression
    Block* condBlock = Anchor::getNextBlock(*this->condition);
    auto condStatement = condBlock->buildAST(result);
    auto condExprStmt = std::dynamic_pointer_cast<ExpressionStatement>(condStatement);
    auto conditionExpr = condExprStmt->expression;

    // Build the 'then' (true) branch
    std::vector<std::shared_ptr<Statement>> thenStatements;
    try {
        runNext(thenStatements, this->trueAnchor);
    } catch (const ReachedEnd&) {
        // true branch reached end
    }

    auto thenBranch = std::make_shared<BlockStatement>(thenStatements);

    // Build the 'else' (false) branch
    std::vector<std::shared_ptr<Statement>> elseStatements;
    try {
        Anchor::getNextBlock(*this->falseAnchor)->buildAST(elseStatements);
    } catch (const ReachedEnd&) {
        // false branch reached end
    }

    auto elseBranch = std::make_shared<BlockStatement>(elseStatements);

    auto ifStmt = std::make_shared<IfStatement>(conditionExpr, thenBranch, elseBranch);
    result.push_back(ifStmt);

    // Continue on the mainline (left anchor)
    throw ReachedEnd("If block reached end");
}

// ------------------------------------------------------------
void Listen::fromJson(const QJsonValue& json) {
    QJsonObject obj = json.toObject();

    name = getStringField(obj, "blockType");

    std::string rightUuid = getStringField(obj, "rightAnchor");
    right = new Anchor(rightUuid, this);
    eventName = getStringField(obj, "eventName");
}

std::shared_ptr<Statement> Listen::buildAST(std::vector<std::shared_ptr<Statement>>& result) {
    throw std::runtime_error("Not allowed block access");
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
    auto op = Token(operationMapper.at(this->operation), operation, "");
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
    auto op = Token(operation == "negate" ? TokenType::MINUS : TokenType::BANG, operation, "");
    auto binary = std::make_shared<Unary>(op, inputStatement->expression);

    return std::make_shared<ExpressionStatement>(binary);
}
