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

  // Ignore if is a comment or whitespaces
  // // \n \r \t ' '
  if ((c == '\r' || c == '\t' || c == ' ') ||
      (c == '/' && peek() == '/')) /* do nothing */
    ;

  // New line
  else if (c == '\n')
    line++;

  // Single character tokens
  // () {} , . - + ; *
  else if (c == '(')
    addToken(TokenType::LEFT_PAREN);
  else if (c == ')')
    addToken(TokenType::RIGHT_PAREN);
  else if (c == '{')
    addToken(TokenType::LEFT_BRACE);
  else if (c == '}')
    addToken(TokenType::RIGHT_BRACE);
  else if (c == ',')
    addToken(TokenType::COMMA);
  else if (c == '.')
    addToken(TokenType::DOT);
  else if (c == '-')
    addToken(TokenType::MINUS);
  else if (c == '+')
    addToken(TokenType::PLUS);
  else if (c == ';')
    addToken(TokenType::SEMICOLON);
  else if (c == '*')
    addToken(TokenType::STAR);
  else if (c == '/')
    addToken(TokenType::SLASH);

  // Double character tokens with '=' and comparision logic
  // != == <= >= = < >
  else if (c == '!')
    addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
  else if (c == '=')
    addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
  else if (c == '<')
    addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
  else if (c == '>')
    addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);

  // Literals
  // "string"    123    my_variable_identifier   special words
  else if (c == '"')
    stringLiteral();
  else if (isDigit(c))
    numberLiteral();
  else if (isAlpha(c))
    identifier();

  // If nothing matches, throw an error
  else {
    std::cerr << "Error: Unexpected character '" << c << "' at line " << line
              << "\n";
    ErrorHandler::error(line, "invalid character");
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
  if (isAtEnd())
    return false;
  if (source[current] != expected)
    return false;

  current++;
  return true;
}

char Scanner::peek() const {
  if (isAtEnd())
    return '\0';
  return source[current];
}

char Scanner::peekNext() const {
  if (current + 1 >= source.length())
    return '\0';
  return source[current + 1];
}

void Scanner::stringLiteral() {
  while (peek() != '"' && !isAtEnd()) {
    if (peek() == '\n')
      line++;
    advance();
  }

  if (isAtEnd()) {
    ErrorHandler::error(line, "Unterminated string.");
    return;
  }

  // The closing ".
  advance();

  // Trim the surrounding quotes.
  std::string value =
      source.substr(start + 1, current - start - 1);  // @NOTE: Is this correct?
  addToken(TokenType::STRING, value);
}

void Scanner::numberLiteral() {
  while (isDigit(peek()))
    advance();

  // Look for a fractional part.
  if (peek() == '.' && isDigit(peekNext())) {
    // Consume the "."
    advance();

    while (isDigit(peek()))
      advance();
  }

  double value;
  std::stringstream ss(source.substr(start, current - start));
  ss >> value;
  addToken(TokenType::NUMBER, ss.str());
}

bool Scanner::isDigit(char c) const {
  return c >= '0' && c <= '9';
}

bool Scanner::isAlpha(char c) const {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
}

bool Scanner::isAlphanumeric(char c) const {
  return isAlpha(c) || isDigit(c);
}

void Scanner::identifier() {
  while (isAlphanumeric(peek()))
    advance();

  std::string text = source.substr(start, current - start);
  TokenType type;

  if (auto search = keywords.find(text);
      search != keywords.end()) {  // There was a keyword found
    type = search->second;
  } else {  // No keyword found --> it is an identifier
    type = TokenType::IDENTIFIER;
  }

  // If the identifier is not a keyword, it is an identifier
  addToken(type);
}
