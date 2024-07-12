#include "Scanner.h"

std::vector<Token> Scanner::scanTokens() {
  // @NOTE: Do we want to reset the vector every time?


  while (!isAtEnd()) {
    // We are at the beginning of the next lexeme
    start = current;
    this.scanToken();
  }
  
  tokens.push_back(new Token(EOF, "", "", line));
  return tokens;
}

bool Scanner::isAtEnd() const {
  return current >= source.length();
}

void Scanner::scanToken() {
  char c = advance();
  switch (c) {
    case '(': addToken(TokenType::LEFT_PAREN); break;
    case ')': addToken(TokenType::RIGHT_PAREN); break;
    case '{': addToken(TokenType::LEFT_BRACE); break;
    case '}': addToken(TokenType::RIGHT_BRACE); break;
    case ',': addToken(TokenType::COMMA); break;
    case '.': addToken(TokenType::DOT); break;
    case '-': addToken(TokenType::MINUS); break;
    case '+': addToken(TokenType::PLUS); break;
    case ';': addToken(TokenType::SEMICOLON); break;
    case '*': addToken(TokenType::STAR); break;
    case '!':
      addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
      break;
    case '=':
      addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
      break;
    case '<':
      addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
      break;
    case '>':
      addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
      break;
    case '/':
      if (match('/')) {
        // A comment goes until the end of the line
        while (peek() != '\n' && !isAtEnd()) advance();
      } else {
        addToken(TokenType::SLASH);
      }
      break;
    case ' ':
    case '\r':
    case '\t':
      // Ignore whitespaces
      break;
    case '\n':
      line++;
      break;

    default:
      std::cerr << "Error: Unexpected character '" << c << "' at line " << line << "\n";
      ErrorHandler::error(line, "invalid character");
      break;
  }
}

char Scanner::advance() {
  return source[current++];
}

void Scanner::addToken(TokenType type) {
  addToken(type, "");
}

void Scanner::addToken(TokenType type, const std::string& literal) {
  std::string text = source.substr(start, current - start);
  tokens.push_back(Token(type, text, literal, line));
}

bool Scanner::match(char expected) {
  if(isAtEnd()) return false;
  if(source[current] != expected) return false;
  
  current++;
  return true;
}

char Scanner::peek() const {
  if (isAtEnd()) return '\0';
  return source[current];
}