//
// Created by nikod on 15/12/2024.
//

#include "Compiler.h"

#include <utility>

#include "LogManager/LogManager.h"

// Define the static member variable
bool Compiler::hadError = false;
bool Compiler::hadRuntimeError = false;

//Interpreter Compiler::interpreter;

Compiler::Compiler() {
    //interpreter = Interpreter();
    hadRuntimeError = false;
    hadError = false;
}

Compiler::~Compiler() = default;

void Compiler::runFile(const char* file) {
    std::ifstream fileStream(file);

    if (!fileStream.is_open()) {
        LogManager::crit() << "Could not open file " << file << "\n";
        exit(74);
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();

    Compiler::run(buffer.str());

    if (hadError) {
        exit(65);
    }

    if (hadRuntimeError) {
        exit(70);
    }
}

void Compiler::runPrompt() {
    std::string line;

    for (;;) {
        LogManager::log() << ">> ";
        std::getline(std::cin, line);

        if (std::cin.eof()) {
            LogManager::log() << "Ending REPL compilation...\n";
            break;
        } else if (line.empty()) {
            continue;  // If the file is empty, skip it
        } else {
            Compiler::run(line);
            hadError = false;
        }
    }
}

void Compiler::run(const std::string_view source) {
    Scanner scanner;
    std::vector<Token> tokens = scanner.scan(source);

    Parser parser(tokens);
    std::vector<Statement*> statements = parser.parse();

    if (hadError) {
        return;
    }

    // interpreter.interpret(statements);
}

void Compiler::runtimeError(const std::runtime_error& error) {
    LogManager::log() << error.what() << "\n";
    // @TODO : Maybe add some more specifics
    hadRuntimeError = true;
}