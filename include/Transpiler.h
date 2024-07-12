#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Transpiler {
public:
    Transpiler();
    ~Transpiler();

public:
    static void runFile(const char* file);
    static void runPrompt();

private:
    static void run(std::string source);
};