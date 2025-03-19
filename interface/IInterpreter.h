#pragma once

#include <memory>
#include <string>
#include <vector>

class Statement;

namespace vtc::interpreter
{
    /**
     * @brief Abstract interface for an interpreter.
     *
     * This interface defines the contract for executing an Abstract Syntax Tree (AST).
     */
    class IInterpreter
    {
    public:
        IInterpreter() = default;
    protected:
        ~IInterpreter() = default;
    public:
        /**
         * @brief Execute the given AST.
         * @param statements A vector of shared pointers to the root of the AST.
         */
        virtual std::string execute(const std::vector<std::shared_ptr<Statement>>& statements) = 0;
    };
} // namespace vtc::interpreter
