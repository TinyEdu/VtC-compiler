// main.cpp

#include "vtc/LogManager/LogManager.h"

#include <span>
#include <optional>


std::optional<const char*> isCorrectFilename(std::span<char*> args)
{
    if (args.size() == 2)
    {
        return args[1];
    }
    return std::nullopt;
}


int main(const int argc, char* argv[])
{
    LOG << "Running compiler..." << ENDL;

    // Wrap arguments in a std::span
    const std::span args(argv, argc);

    if (args.size() > 2)
    {
        WARN << "Error: Invalid number of arguments." << ENDL;
        WARN << "Usage: ./compiler [filename]" << ENDL;
        return 65;
    }

    if (const auto filename = isCorrectFilename(args))
    {
        LOG << "Compiling file: " << *filename << "..." << ENDL;
        Transpiler::runFile(*filename);
    }
    else
    {
        LOG << "Real life compilation..." << ENDL;
        LOG << "Prompting :>" << ENDL;
        Transpiler::runPrompt();
    }

    return 0;
}
