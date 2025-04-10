#pragma once

#include "../Anchor/Anchor.h"
#include "Statements/Statement.h"

#include <memory>
#include <string>
#include <variant>
#include <QJsonValue>

class Block {
public:
    Block() = default;
    virtual ~Block() = default;

    std::string name;

    // Reads properties from the provided QJsonValue.
    virtual void fromJson(const QJsonValue& json) = 0;
    // Builds the AST from this b.
    virtual std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) = 0;
};

// Break block.
class Break : public Block {
public:
    Break() : left(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
};

// Call block.
class Call : public Block {
public:
    Call() : left(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
};

// CreateVar block representing both CreateVarBySignal and CreateVarByValue.
class CreateVar : public Block {
public:
    CreateVar() : left(nullptr), right(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
    Anchor* right;
    std::string variableName;
    // The value can be specified as an anchor (signal) or literal string (value).
    std::variant<Anchor*, std::string> value;
};

// End block.
class End : public Block {
public:
    End() : left(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
};

// ForLoop block.
class ForLoop : public Block {
public:
    ForLoop() : left(nullptr), right(nullptr), start(nullptr), end(nullptr), inc(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
    Anchor* right;
    std::string from;
    std::string to;
    std::string increment;
    // Additional anchors for loop boundaries.
    Anchor* start;
    Anchor* end;
    Anchor* inc;
};

// GetVar block.
class GetVar : public Block {
public:
    GetVar() : passing(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* passing;
    std::string variableName;
};

// If block.
class If : public Block {
public:
    If() : left(nullptr), trueAnchor(nullptr), falseAnchor(nullptr), condition(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
    Anchor* trueAnchor;
    Anchor* falseAnchor;
    Anchor* condition;
};

// Listen block.
class Listen : public Block {
public:
    Listen() : right(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* right;
    std::string variableName;
};

// Print block representing PrintBySignal and PrintByValue.
class Print : public Block {
public:
    Print() : left(nullptr), right(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
    Anchor* right;
    std::variant<Anchor*, std::string> value;
};

// SetVar block.
class SetVar : public Block {
public:
    SetVar() : left(nullptr), right(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
    Anchor* right;
    std::string variableName;
    std::variant<Anchor*, std::string> value;
};

// Skip block.
class Skip : public Block {
public:
    Skip() : left(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
};

// Start block.
class Start : public Block {
public:
    Start() : right(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* right;
};

// Value block.
class Value : public Block {
public:
    Value() : passing(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* passing;
    std::string valueStr;
};

// While block.
class While : public Block {
public:
    While() : left(nullptr), right(nullptr), condition(nullptr), start(nullptr), end(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
    Anchor* right;
    Anchor* condition;
    Anchor* start;
    Anchor* end;
};

// BinaryOp block.
class BinaryOp : public Block {
public:
    BinaryOp() : left(nullptr), right(nullptr), leftInputValue(nullptr),
                 rightInputValue(nullptr), outputValue(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
    Anchor* right;
    Anchor* leftInputValue;
    Anchor* rightInputValue;
    std::string operation;
    Anchor* outputValue;
};

// UnaryOp block.
class UnaryOp : public Block {
public:
    UnaryOp() : left(nullptr), right(nullptr), inputValue(nullptr), outputValue(nullptr) {}
    void fromJson(const QJsonValue& json) override;
    std::shared_ptr<Statement> buildAST(std::vector<std::shared_ptr<Statement>>& result) override;
private:
    Anchor* left;
    Anchor* right;
    Anchor* inputValue;
    Anchor* outputValue;
    std::string operation;
};
