#include <span>
#include <optional>

#include "LogManager/LogManager.h"
#include <Compiler/Compiler.h>


#ifdef _WIN32
#include <windows.h>

void enableAnsiSupport()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#endif


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
#ifdef _WIN32
    enableAnsiSupport();
#endif
    LogManager::LOG() << "Running compiler...";

    // Wrap arguments in a std::span
    const std::span args(argv, argc);

    if (args.size() > 2)
    {
        LogManager::warn() << "Error: Invalid number of arguments.";
        LogManager::warn() << "Usage: ./compiler [filename]";

        return 65;
    }

    if (const auto filename = isCorrectFilename(args))
    {
        LogManager::LOG() << "Compiling file: " << *filename << "...";
        Compiler::runFile(*filename);
    }
    else
    {
        LogManager::LOG() << "Real life compilation...";
        LogManager::LOG() << "Prompting :>";

        Compiler::runPrompt();
    }

    return 0;
}
