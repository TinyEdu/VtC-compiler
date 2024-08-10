#include <iostream>
#include "AstPrinter.h"
#include "Transpiler.h"

#include "LogManager.h"


int main(int argc, char* argv[]) {
  LOG << "Running compiler...";
  WARN << "This is a warning message.";
  CRIT << "This is an info message.";

  if (argc > 2) {
    std::cerr << "Error: Wrong input amount.\n";
    return 65;  // https://man.freebsd.org/cgi/man.cgi?query=sysexits&apropos=0&sektion=0&manpath=FreeBSD+4.3-RELEASE&format=html
  } else if (argc == 2) {
    std::clog << "Compiling file: " << argv[1] << "...\n";
    Transpiler::runFile(argv[1]);
  } else {  // argc == 1
    std::clog << "Real life compilation... \nPrompting :>\n";
    Transpiler::runPrompt();
  }

  return 1;
}