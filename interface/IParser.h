#pragma once

#include <memory>
#include <vector>
#include <string>

class Statement;

namespace vtc::parser
{
    // Forward declaration for Statement nodes (defined elsewhere)

    /**
     * @brief Abstract interface for a parser.
     *
     * This interface defines the contract for parsing input into an Abstract Syntax Tree (Statement).
     */
    class IParser
    {
    public:
        IParser() = default;

    protected:
        ~IParser() = default;

    public:
        /**
         * @brief Parse the given input and produce an Statement.
         * @param input A string representing the source code or program description.
         * @return A unique_ptr to the root of the Statement.
         */
        virtual std::vector<std::shared_ptr<Statement>> parse(const std::string& input) = 0;
    };
} // namespace vtc::parser