// Application.cpp

#include "AstPrinter.h"
#include "Transpiler.h"

#include "LogManager.h"

int main(int argc, char* argv[]) {
  LOG << "Running compiler..." << ENDL;

  if (argc > 2) {
    WARN << "Error: Wrong input amount." << ENDL;
    return 65;  // https://man.freebsd.org/cgi/man.cgi?query=sysexits&apropos=0&sektion=0&manpath=FreeBSD+4.3-RELEASE&format=html
  } else if (argc == 2) {
    LOG << "Compiling file: " << argv[1] << "...\n";
    Transpiler::runFile(argv[1]);
  } else {  // argc == 1
    LOG << "Real life compilation..." << ENDL;
    LOG << "Prompting :>" << ENDL;
    Transpiler::runPrompt();
  }

  return 1;
}