#include "Transpiler.h"


Transpiler::Transpiler() {

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
        }
    }
}

void Transpiler::run(std::string source) {
    std::cout << source << "\n";
}