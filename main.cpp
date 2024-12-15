// main.cpp

#include "vtc/LogManager/LogManager.h"

#include <span>
#include <optional>


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
    LogManager::log() << "Running compiler...";

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
        LogManager::log() << "Compiling file: " << *filename << "...";
        //Transpiler::runFile(*filename);
    }
    else
    {
        LogManager::log() << "Real life compilation...";
        LogManager::log() << "Prompting :>";
        //Transpiler::runPrompt();
    }

    return 0;
}
