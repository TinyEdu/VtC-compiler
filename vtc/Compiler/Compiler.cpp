#include "Compiler.h"

#include "Interpreter/Interpreter.h"
#include "LogManager/LogManager.h"
#include "Scanner/Scanner.h"
#include "Parser/Parser.h"

#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>

Interpreter Compiler::interpreter;

bool Compiler::hadError = false;
bool Compiler::hadRuntimeError = false;

Compiler::Compiler()
{
    interpreter = Interpreter();
    hadRuntimeError = false;
    hadError = false;
}

Compiler::~Compiler() = default;

void Compiler::runFile(const char* file)
{
    std::ifstream fileStream(file);

    if (!fileStream.is_open())
    {
        LogManager::crit() << "Could not open file " << file << "\n";
        exit(74);
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();

    run(buffer.str());

    if (hadError)
    {
        exit(65);
    }

    if (hadRuntimeError)
    {
        exit(70);
    }
}

void Compiler::runPrompt()
{
    std::string line;

    for (;;)
    {
        LogManager::log() << ">> ";
        std::getline(std::cin, line);

        if (std::cin.eof())
        {
            LogManager::log() << "Ending REPL compilation...\n";
            break;
        }

        if (line.empty())
        {
            // If the file is empty, skip it
            continue;
        }

        Compiler::run(line);
        hadError = false;
    }
}

void Compiler::run(const std::string& source)
{
    Scanner scanner;
    const std::vector<Token> tokens = scanner.scan(source);

    Parser parser(tokens);
    const auto& statements = parser.parse();

    if (hadError)
    {
        return;
    }

    interpreter.interpret(statements);
}

void Compiler::runtimeError(const std::runtime_error& error)
{
    LogManager::log() << error.what() << "\n";
    // @TODO : Maybe add some more specifics
    hadRuntimeError = true;
}
