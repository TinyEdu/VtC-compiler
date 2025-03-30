#include "BlockReader.h"

#include "BlockReaderException.h"

BlockReader::BlockReader()
{
    // Register functions in constructor
    initializeHandlerRegister();
}

Block BlockReader::extract(const QQuickItem& block) const
{
    const QVariant nameProperty = block.property("myvariable");

    if (!nameProperty.isValid())
    {
        throw BlockReaderException("BlockReader, extract error.");
    }

    const std::string name = nameProperty.toString().toStdString();

    return extract(block, name);
}

Block BlockReader::extract(const QQuickItem& block, const std::string& name) const
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
    functionMap["Break"] = &BlockReader::Break;
    functionMap["Call"] = &BlockReader::Call;
    functionMap["Create Var"] = &BlockReader::CreateVar;
    functionMap["End"] = &BlockReader::End;
    functionMap["For Loop"] = &BlockReader::ForLoop;
    functionMap["Get Var"] = &BlockReader::GetVar;
    functionMap["If"] = &BlockReader::If;
    functionMap["Listen"] = &BlockReader::Listen;
    functionMap["Print"] = &BlockReader::Print;
    functionMap["Set Var"] = &BlockReader::SetVar;
    functionMap["Skip"] = &BlockReader::Skip;
    functionMap["Start"] = &BlockReader::Start;
    functionMap["Var"] = &BlockReader::Var;
    functionMap["While"] = &BlockReader::While;
    functionMap["Binary Op"] = &BlockReader::BinaryOp;
    functionMap["Unary Op"] = &BlockReader::UnaryOp;
}

/**
 * leftAnchor
 */
Block BlockReader::Break(const QQuickItem& block, std::string name)
{
    return {};
}

/**
 * rightAnchor
 * callSelector - Textfield storing the called event name
 */
Block BlockReader::Call(const QQuickItem& block, std::string name)
{
}

/**
 *  1.
 *  leftAnchor
 *  rightAnchor
 *  name - textfield `nameField` storing the name
 *  value - anchor `signalAnchor` pointing to the value signal
 *
 *  2.
 *  leftAnchor
 *  rightAnchor
 *  name - textfield `nameField` storing the name
 *  value - textfield `initialValueField` with initial value
 */
Block BlockReader::CreateVar(const QQuickItem& block, std::string name)
{
}

/**
 * leftAnchor
 */
Block BlockReader::End(const QQuickItem& block, std::string name)
{
}

/**
 * leftAnchor
 */
Block BlockReader::ForLoop(const QQuickItem& block, std::string name)
{
}

Block BlockReader::GetVar(const QQuickItem& block, std::string name)
{
}

Block BlockReader::If(const QQuickItem& block, std::string name)
{
}

Block BlockReader::Listen(const QQuickItem& block, std::string name)
{
}

Block BlockReader::Print(const QQuickItem& block, std::string name)
{
}

Block BlockReader::SetVar(const QQuickItem& block, std::string name)
{
}

Block BlockReader::Skip(const QQuickItem& block, std::string name)
{
}

Block BlockReader::Start(const QQuickItem& block, std::string name)
{
}

Block BlockReader::Var(const QQuickItem& block, std::string name)
{
}

Block BlockReader::While(const QQuickItem& block, std::string name)
{
}

Block BlockReader::BinaryOp(const QQuickItem& block, std::string name)
{
}

Block BlockReader::UnaryOp(const QQuickItem& block, std::string name)
{
}
