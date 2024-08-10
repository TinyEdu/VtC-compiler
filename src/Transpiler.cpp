#include "Transpiler.h"

// Define the static member variable
bool Transpiler::hadError = false;
bool Transpiler::hadRuntimeError = false;

Interpreter Transpiler::interpreter;

Transpiler::Transpiler() {
  interpreter = Interpreter();
  hadRuntimeError = false;
  hadError = false;
}

Transpiler::~Transpiler() {}

void Transpiler::runFile(const char* file) {
  std::ifstream fileStream(file);

  if (!fileStream.is_open()) {
    CRIT << "Could not open file " << file << "\n";
    exit(74);
  }

  std::stringstream buffer;
  buffer << fileStream.rdbuf();

  Transpiler::run(buffer.str());

  if (hadError) {
    exit(65);
  }

  if (hadRuntimeError) {
    exit(70);
  }
}

void Transpiler::runPrompt() {
  std::string line;

  for (;;) {
    LOG << ">> ";
    std::getline(std::cin, line);

    if (std::cin.eof()) {
      LOG << "Ending REPL compilation...\n";
      break;
    } else if (line.empty()) {
      continue;  // If the file is empty, skip it
    } else {
      Transpiler::run(line);
      hadError = false;
    }
  }
}

void Transpiler::run(std::string source) {
  LOG << "Source code: \n";
  LOG << std::string(15, '_') << "\n";
  LOG << source << "\n";
  LOG << std::string(15, '_') << "\n";

  Scanner scanner(source);
  std::vector<Token> tokens = scanner.scanTokens();

  // for testing purposes
  for (Token token : tokens)
    LOG << token << "\n";

  LOG << std::string(15, '_') << "\n";

  Parser parser(tokens);
  Expression* expression = parser.parse();

  // for testing purposes
  AstPrinter printer;
  if (expression != nullptr)
    LOG << printer.print(expression) << "\n";

  if (hadError)
    return;

  interpreter.interpret(expression);

  LOG << std::string(15, '_') << "\n";
}

void Transpiler::runtimeError(const std::runtime_error& error) {
  LOG << error.what() << "\n";
  // @TODO : Maybe add some more specifics
  hadRuntimeError = true;
}
