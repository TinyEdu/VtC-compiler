#pragma once

#include <utility>

#include "IInterpreter.h"
#include "IParser.h"

namespace vtc::ui
{
    /**
     * @brief Abstract interface for a user interface.
     *
     * This interface defines the contract for running a user interface,
     * which could be graphical or text-based.
     */

    class IUserInterface
    {
    public:
        IUserInterface(std::shared_ptr<vtc::parser::IParser> parser,
            std::shared_ptr<vtc::interpreter::IInterpreter> interpreter)
        : parser(std::move(parser)), interpreter(std::move(interpreter)) {};

        ~IUserInterface() = default;

        std::shared_ptr<parser::IParser> parser;
        std::shared_ptr<interpreter::IInterpreter> interpreter;

    public:
        /**
         * @brief Start the user interface loop.
         *
         * This method should initialize and run the UI event loop or interaction loop.
         */
        virtual int run(int argc, char *argv[]) = 0;
    };
} // namespace vtc::ui
