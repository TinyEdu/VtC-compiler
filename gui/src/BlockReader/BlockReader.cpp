#include "BlockReader.h"

#include "BlockReaderException.h"

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

BlockReader::BlockReader()
{
    // Register functions in constructor
    functionMap["function1"] = &BlockReader::function1;
    functionMap["function2"] = &BlockReader::function2;
}

// ------------------------------------------------------------------------------------
// Handlers
// ------------------------------------------------------------------------------------

Block BlockReader::function1(const QQuickItem& block, std::string name)
{
    return {};
}

Block BlockReader::function2(const QQuickItem& block, std::string name)
{
    return {};
}
