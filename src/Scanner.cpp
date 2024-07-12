#include "Scanner.h"


std::vector<Token> Scanner::scanTokens() {
  // @NOTE: Do we want to reset the vector every time?


  while (!isAtEnd()) {
    // We are at the beginning of the next lexeme
    start = current;
    scanToken();
  }
  
  tokens.emplace_back(TokenType::END_OF_FILE, "", "", line);

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
    case '"':
      stringLiteral();
      break;
    default:
      if (isDigit(c)) {
        numberLiteral();
      }
      else if(isAlpha(c)) {
        identifier();
      } 
      else {
        std::cerr << "Error: Unexpected character '" << c << "' at line " << line << "\n";
        ErrorHandler::error(line, "invalid character");
        break;
      }
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


char Scanner::peekNext() const {
  if (current + 1 >= source.length()) return '\0';
  return source[current + 1];
}


void Scanner::stringLiteral() {
  while (peek() != '"' && !isAtEnd()) {
    if (peek() == '\n') line++;
      advance();
    }

    if (isAtEnd()) {
      ErrorHandler::error(line, "Unterminated string.");
      return;
    }

    // The closing ".
    advance();

    // Trim the surrounding quotes.
    std::string value = source.substr(start + 1, current - start - 1); // @NOTE: Is this correct?
    addToken(TokenType::STRING, value);
}


void Scanner::numberLiteral() {
  while (isDigit(peek())) advance();

  // Look for a fractional part.
  if (peek() == '.' && isDigit(peekNext())) {
    // Consume the "."
    advance();

    while (isDigit(peek())) advance();
  }

  double value;
  std::stringstream ss(source.substr(start, current - start + 1));
  ss >> value;
  addToken(TokenType::NUMBER, ss.str());
}


bool Scanner::isDigit(char c) const {
   return c >= '0' && c <= '9';
}


bool Scanner::isAlpha(char c) const {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
            c == '_';
}

bool Scanner::isAlphanumeric(char c) const {
  return isAlpha(c) || isDigit(c);
}


void Scanner::identifier() {
  while (isAlphanumeric(peek())) advance();
  
  std::string text = source.substr(start, current - start + 1);
  TokenType type = keywords.at(text);
  
  // If the identifier is not a keyword, it is an identifier
  
  addToken(TokenType::IDENTIFIER);
}
