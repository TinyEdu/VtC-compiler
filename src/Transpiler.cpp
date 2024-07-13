#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>

#include "Scanner.h"
#include "Token.h"
#include "Transpiler.h"

// @NOTE: Temporary solution
// Define the static member variable
bool Transpiler::hadError = false;

Transpiler::Transpiler() {
    hadError = true;
}

Transpiler::~Transpiler() {

}

void Transpiler::runFile(const char* file) {
    std::ifstream fileStream(file);

    if(!fileStream.is_open()) {
        std::cerr << "Error: Could not open file " << file << "\n";
        exit(74);
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();

    Transpiler::run(buffer.str());

    if (hadError) {
        exit(65);
    }
}

void Transpiler::runPrompt() {
    std::string line;

    for(;;) {
        std::cout << ">> ";
        std::getline(std::cin, line);

        if (std::cin.eof()) {
            std::clog << "Ending REPL compilation...\n";
            break;
        }
        else if (line.empty()) {
            continue;  // If the file is empty, skip it
        }
        else {
            Transpiler::run(line);
            hadError = false;
        }
    }
}

void Transpiler::run(std::string source) {
    std::cout << "Source code: \n";
    std::cout << std::string(15, '_') << "\n";
    std::cout << source << "\n";
    std::cout << std::string(15, '_') << "\n";

    Scanner scanner(source);
    std::vector<Token> tokens = scanner.scanTokens();

    for (Token token : tokens) {
        std::cout << token << "\n";
    }

    std::cout << std::string(15, '_') << "\n";
}
