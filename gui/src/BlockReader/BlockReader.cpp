#include "BlockReader.h"

#include "BlockReaderException.h"
#include "Blocks/Break.h"

BlockReader::BlockReader()
{
    // Register functions in constructor
    initializeHandlerRegister();
}

Block* BlockReader::extract(const QQuickItem& block) const
{
    const QVariant nameProperty = block.property("myvariable");

    if (!nameProperty.isValid())
    {
        throw BlockReaderException("BlockReader, extract error.");
    }

    const std::string name = nameProperty.toString().toStdString();

    return extract(block, name);
}

Block* BlockReader::extract(const QQuickItem& block, const std::string& name) const
{
    const auto it = functionMap.find(name);
    if (it == functionMap.end())
    {
        throw std::invalid_argument("Function not found: " + name);
    }

    return it->second(block, name);
}

// ------------------------------------------------------------------------------------
// Handlers
// ------------------------------------------------------------------------------------

void BlockReader::initializeHandlerRegister()
{
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
    functionMap["Var"] = &BlockReader::BuildVar;
    functionMap["While"] = &BlockReader::BuildWhile;
    functionMap["Binary Op"] = &BlockReader::BuildBinaryOp;
    functionMap["Unary Op"] = &BlockReader::BuildUnaryOp;
}

Block* BlockReader::BuildBreak(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildCall(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildCreateVar(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildEnd(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildForLoop(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildGetVar(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildIf(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildListen(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildPrint(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildSetVar(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildSkip(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildStart(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildVar(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildWhile(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildBinaryOp(const QQuickItem& block, std::string name)
{
    return new Break();
}

Block* BlockReader::BuildUnaryOp(const QQuickItem& block, std::string name)
{
    return new Break();
}
