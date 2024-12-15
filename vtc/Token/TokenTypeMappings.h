//
// Created by nikod on 15/12/2024.
//

#ifndef TOKENTYPEMAPPINGS_H
#define TOKENTYPEMAPPINGS_H

#include "TokenType.h"

const std::map<TokenType, std::string> tokenTypeMap = {
    // Single-character tokens.
    {TokenType::LEFT_PAREN, "LEFT_PAREN"},
    {TokenType::RIGHT_PAREN, "RIGHT_PAREN"},
    {TokenType::LEFT_BRACE, "LEFT_BRACE"},
    {TokenType::RIGHT_BRACE, "RIGHT_BRACE"},
    {TokenType::COMMA, "COMMA"},
    {TokenType::DOT, "DOT"},
    {TokenType::MINUS, "MINUS"},
    {TokenType::PLUS, "PLUS"},
    {TokenType::SEMICOLON, "SEMICOLON"},
    {TokenType::SLASH, "SLASH"},
    {TokenType::STAR, "STAR"},

    // One or two character tokens.
    {TokenType::BANG, "BANG"},
    {TokenType::BANG_EQUAL, "BANG_EQUAL"},
    {TokenType::EQUAL, "EQUAL"},
    {TokenType::EQUAL_EQUAL, "EQUAL_EQUAL"},
    {TokenType::GREATER, "GREATER"},
    {TokenType::GREATER_EQUAL, "GREATER_EQUAL"},
    {TokenType::LESS, "LESS"},
    {TokenType::LESS_EQUAL, "LESS_EQUAL"},

    // Literals.
    {TokenType::IDENTIFIER, "IDENTIFIER"},
    {TokenType::STRING, "STRING"},
    {TokenType::NUMBER, "NUMBER"},

    // Keywords.
    {TokenType::AND, "AND"},
    {TokenType::CLASS, "CLASS"},
    {TokenType::ELSE, "ELSE"},
    {TokenType::FALSE, "FALSE"},
    {TokenType::DEF, "DEF"},
    {TokenType::FOR, "FOR"},
    {TokenType::IF, "IF"},
    {TokenType::NIL, "NIL"},
    {TokenType::OR, "OR"},
    {TokenType::PRINT, "PRINT"},
    {TokenType::RETURN, "RETURN"},
    {TokenType::SUPER, "SUPER"},
    {TokenType::THIS, "THIS"},
    {TokenType::TRUE, "TRUE"},
    {TokenType::VAR, "VAR"},
    {TokenType::WHILE, "WHILE"},

    {TokenType::END_OF_FILE, "END_OF_FILE"}
};

const std::unordered_map<std::string, TokenType> keywordMappings = {
    {"and", TokenType::AND},
    {"class", TokenType::CLASS},
    {"else", TokenType::ELSE},
    {"false", TokenType::FALSE},
    {"for", TokenType::FOR},
    {"def", TokenType::DEF},
    {"if", TokenType::IF},
    {"nil", TokenType::NIL},
    {"or", TokenType::OR},
    {"print", TokenType::PRINT},
    {"return", TokenType::RETURN},
    {"super", TokenType::SUPER},
    {"this", TokenType::THIS},
    {"true", TokenType::TRUE},
    {"var", TokenType::VAR},
    {"while", TokenType::WHILE}
};

const std::unordered_map<char, TokenType> doubleCharTokensMappings = {
    {'!', TokenType::BANG}, // '!' might become '!='
    {'=', TokenType::EQUAL}, // '=' might become '=='
    {'<', TokenType::LESS}, // '<' might become '<='
    {'>', TokenType::GREATER} // '>' might become '>='
};

const std::unordered_map<char, TokenType> singleCharTokensMappings = {
    {'(', TokenType::LEFT_PAREN},
    {')', TokenType::RIGHT_PAREN},
    {'{', TokenType::LEFT_BRACE},
    {'}', TokenType::RIGHT_BRACE},
    {',', TokenType::COMMA},
    {'.', TokenType::DOT},
    {'-', TokenType::MINUS},
    {'+', TokenType::PLUS},
    {';', TokenType::SEMICOLON},
    {'*', TokenType::STAR},
    {'<', TokenType::LESS},
    {'>', TokenType::GREATER},
    {'=', TokenType::EQUAL},
    {'/', TokenType::SLASH}
};

#endif //TOKENTYPEMAPPINGS_H
