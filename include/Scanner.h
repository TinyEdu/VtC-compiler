// Scanner.h
#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include "Token.h"

class Scanner {
public:
    // Constructor
    Scanner(const std::string& source) : source(source) {}

    std::vector<Token> scanTokens();
private:
    std::string source;
    std::vector<Token> tokens;
};

#endif // SCANNER_H
