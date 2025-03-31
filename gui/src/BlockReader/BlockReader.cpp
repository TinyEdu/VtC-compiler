#include "BlockReader.h"

#include <utility>

#include "BlockReaderException.h"
#include "Blocks/BinaryOp.h"
#include "Blocks/Break.h"
#include "Blocks/Call.h"
#include "Blocks/CreateVarBySignal.h"
#include "Blocks/CreateVarByValue.h"
#include "Blocks/End.h"
#include "Blocks/ForLoop.h"
#include "Blocks/GetVar.h"
#include "Blocks/If.h"
#include "Blocks/Listen.h"
#include "Blocks/PrintBySignal.h"
#include "Blocks/PrintByValue.h"
#include "Blocks/SetVarBySignal.h"
#include "Blocks/Skip.h"
#include "Blocks/Start.h"
#include "Blocks/UnaryOp.h"
#include "Blocks/Value.h"
#include "Blocks/While.h"

BlockReader* BlockReader::instance = nullptr;

BlockReader::BlockReader()
{
    // Register functions in constructor
    initializeHandlerRegister();
}

Block* BlockReader::extract(QQuickItem* block) const
{
    const QVariant nameProperty = block->property("name");

    if (!nameProperty.isValid())
    {
        throw BlockReaderException("BlockReader, extract error.");
    }

    return extract(block, nameProperty.toString());
}

Block* BlockReader::extract(QQuickItem* block, const QString& name) const
{
    const auto it = functionMap.find(name);
    if (it == functionMap.end())
    {
        throw std::invalid_argument("Function not found: " + name.toStdString());
    }

    return it->second(block, name);
}

QString BlockReader::readChildProperty(QQuickItem* block, QString childName, QString propertyName)
{
    const QObject* foundChildName = block->findChild<QObject*>(childName);
    if (!foundChildName) {
        throw BlockReaderException("Could not find child in BlockDiagram");
    }

    const QVariant foundPropertyName = foundChildName->property(propertyName.toStdString().c_str());
    if (!foundPropertyName.isValid()) {
        throw BlockReaderException("Property is not set or accessible");
    }

    return foundPropertyName.toString();
}

bool BlockReader::isChildPresent(QQuickItem* block, QString childName)
{
    const QObject* foundChildName = block->findChild<QObject*>(childName);
    return foundChildName;
}

QString BlockReader::readProperty(QQuickItem* block, QString propertyName)
{
    const QVariant foundPropertyName = block->property(propertyName.toStdString().c_str());
    if (!foundPropertyName.isValid()) {
        throw BlockReaderException("Property 'anchorId' is not set or accessible");

    }

    return foundPropertyName.toString();
}


QUuid BlockReader::emptyQUuid()
{
    return {};
}

// ------------------------------------------------------------------------------------
// Handlers
// ------------------------------------------------------------------------------------

void BlockReader::initializeHandlerRegister()
{
    functionMap["Binary Op"] = &BlockReader::BuildBinaryOp;
    functionMap["Break"] = &BlockReader::BuildBreak;
    functionMap["Call"] = &BlockReader::BuildCall;
    functionMap["Create Var"] = &BlockReader::BuildCreateVar;
    functionMap["End"] = &BlockReader::BuildEnd;
    functionMap["For Loop"] = &BlockReader::BuildForLoop;
    functionMap["Get Var"] = &BlockReader::BuildGetVar;
    functionMap["If"] = &BlockReader::BuildIf;
    functionMap["Listen"] = &BlockReader::BuildListen;
    functionMap["Print"] = &BlockReader::BuildPrint;
    functionMap["Set Var"] = &BlockReader::BuildSetVar;
    functionMap["Skip"] = &BlockReader::BuildSkip;
    functionMap["Start"] = &BlockReader::BuildStart;
    functionMap["Unary Op"] = &BlockReader::BuildUnaryOp;
    functionMap["Value"] = &BlockReader::BuildValue;
    functionMap["While"] = &BlockReader::BuildWhile;
}

Block* BlockReader::BuildBreak(QQuickItem* block, QString name)
{
    const auto result = new Break();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = emptyQUuid();

    return result;
}

Block* BlockReader::BuildCall(QQuickItem* block, QString name)
{
    const auto result = new Call();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = emptyQUuid();

    result->eventName = readChildProperty(block, "eventField", "text");

    return result;
}

Block* BlockReader::BuildCreateVar(QQuickItem* block, QString name)
{
    if (isChildPresent(block, "valueField"))
    {
        return BuildCreateVarByValue(block, name);
    }

    return BuildCreateVarBySignal(block, name);
}

Block* BlockReader::BuildCreateVarByValue(QQuickItem* block, QString name)
{
    const auto result = new CreateVarByValue();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = QUuid(readChildProperty(block, "rightAnchor", "anchorId"));

    result->variableName = readChildProperty(block, "variableNameField", "text");
    result->value = readChildProperty(block, "valueField", "text");

    return result;
}

Block* BlockReader::BuildCreateVarBySignal(QQuickItem* block, QString name)
{
    const auto result = new CreateVarBySignal();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = QUuid(readChildProperty(block, "rightAnchor", "anchorId"));

    result->variableName = readChildProperty(block, "variableNameField", "text");
    result->value = QUuid(readChildProperty(block, "valueAnchor", "anchorId"));

    return result;
}


Block* BlockReader::BuildEnd(QQuickItem* block, QString name)
{
    const auto result = new End();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = emptyQUuid();

    return result;
}

Block* BlockReader::BuildForLoop(QQuickItem* block, QString name)
{
    const auto result = new ForLoop();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = emptyQUuid();

    // @TODO: Implement
    return result;
}

Block* BlockReader::BuildGetVar(QQuickItem* block, QString name)
{
    const auto result = new GetVar();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = emptyQUuid();
    result->rightAnchor = emptyQUuid();

    result->passingAnchor = QUuid(readChildProperty(block, "passingAnchor", "anchorId"));
    result->variable = readChildProperty(block, "variableField", "text");

    return result;
}

Block* BlockReader::BuildIf(QQuickItem* block, QString name)
{
    const auto result = new If();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = emptyQUuid();

    result->condition = QUuid(readChildProperty(block, "conditionAnchor", "anchorId"));
    result->trueAnchor = QUuid(readChildProperty(block, "trueAnchor", "anchorId"));
    result->falseAnchor = QUuid(readChildProperty(block, "falseAnchor", "anchorId"));

    return result;
}

Block* BlockReader::BuildListen(QQuickItem* block, QString name)
{
    const auto result = new Listen();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = emptyQUuid();
    result->rightAnchor = QUuid(readChildProperty(block, "rightAnchor", "anchorId"));

    result->eventName = readChildProperty(block, "eventField", "text");

    return result;
}

Block* BlockReader::BuildPrint(QQuickItem* block, QString name)
{
    if (isChildPresent(block, "valueField"))
    {
        return BuildPrintByValue(block, name);
    }

    return BuildPrintBySignal(block, name);
}

Block* BlockReader::BuildPrintByValue(QQuickItem* block, QString name)
{
    const auto result = new PrintByValue();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = QUuid(readChildProperty(block, "rightAnchor", "anchorId"));

    result->value = readChildProperty(block, "valueField", "text");

    return result;
}

Block* BlockReader::BuildPrintBySignal(QQuickItem* block, QString name)
{
    const auto result = new PrintBySignal();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = QUuid(readChildProperty(block, "rightAnchor", "anchorId"));

    result->value = QUuid(readChildProperty(block, "valueAnchor", "anchorId"));

    return result;
}

Block* BlockReader::BuildSetVar(QQuickItem* block, QString name)
{
    const auto result = new SetVarBySignal();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = QUuid(readChildProperty(block, "rightAnchor", "anchorId"));

    // @TODO: Implement
    return result;
}

Block* BlockReader::BuildSkip(QQuickItem* block, QString name)
{
    const auto result = new Skip();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = emptyQUuid();

    return result;
}

Block* BlockReader::BuildStart(QQuickItem* block, QString name)
{
    const auto result = new Start();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = emptyQUuid();
    result->rightAnchor = QUuid(readChildProperty(block, "rightAnchor", "anchorId"));

    return result;
}

Block* BlockReader::BuildValue(QQuickItem* block, QString name)
{
    const auto result = new Value();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = emptyQUuid();
    result->rightAnchor = emptyQUuid();

    result->passingAnchor = QUuid(readChildProperty(block, "passingAnchor", "anchorId"));
    result->value = readChildProperty(block, "valueField", "text");

    return result;
}

Block* BlockReader::BuildWhile(QQuickItem* block, QString name)
{
    const auto result = new While();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = QUuid(readChildProperty(block, "leftAnchor", "anchorId"));
    result->rightAnchor = QUuid(readChildProperty(block, "rightAnchor", "anchorId"));

    result->condition = QUuid(readChildProperty(block, "conditionAnchor", "anchorId"));
    result->startAnchor = QUuid(readChildProperty(block, "startAnchor", "anchorId"));
    result->endAnchor = QUuid(readChildProperty(block, "endAnchor", "anchorId"));

    return result;
}

Block* BlockReader::BuildBinaryOp(QQuickItem* block, QString name)
{
    const auto result = new BinaryOp();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = emptyQUuid();
    result->rightAnchor = emptyQUuid();

    // @TODO: Implement
    return result;
}

Block* BlockReader::BuildUnaryOp(QQuickItem* block, QString name)
{
    const auto result = new UnaryOp();

    result->setQmlObj(block);
    result->name = std::move(name);

    result->leftAnchor = emptyQUuid();
    result->rightAnchor = emptyQUuid();

    // @TODO: Implement
    return result;
}
