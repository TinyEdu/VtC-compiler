#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> types = {"LiteralInt", "LiteralFloat", "LiteralString",
                                  "LiteralBool", "LiteralDouble"};

std::map<std::string, std::string> operationsMap = {
    {"add", "+"},
    {"subtract", "-"},
    {"multiply", "*"},
    {"divide", "/"},
    {"modulo", "%"},
    {"equal", "=="},
    {"not_equal", "!="},
    {"greater_than", ">"},
    {"less_than", "<"},
    {"greater_than_or_equal", ">="},
    {"less_than_or_equal", "<="}};

std::vector<std::string> operations = {"add", "subtract", "multiply", "divide",
                                       "modulo"};

std::vector<std::string> logicalOperations = {"equal",
                                              "not_equal",
                                              "greater_than",
                                              "less_than",
                                              "greater_than_or_equal",
                                              "less_than_or_equal"};

struct comb {
  std::string left;
  std::string right;
  std::string result;
};

std::vector<comb> combinations = {
    {"LiteralInt", "LiteralInt", "LiteralInt"},
    {"LiteralInt", "LiteralFloat", "LiteralFloat"},
    {"LiteralInt", "LiteralString", "-"},
    {"LiteralInt", "LiteralBool", "LiteralInt"},
    {"LiteralInt", "LiteralDouble", "LiteralDouble"},

    {"LiteralFloat", "LiteralInt", "LiteralFloat"},
    {"LiteralFloat", "LiteralFloat", "LiteralFloat"},
    {"LiteralFloat", "LiteralString", "-"},
    {"LiteralFloat", "LiteralBool", "LiteralFloat"},
    {"LiteralFloat", "LiteralDouble", "LiteralDouble"},

    {"LiteralString", "LiteralInt", "-"},
    {"LiteralString", "LiteralFloat", "-"},
    {"LiteralString", "LiteralString", "LiteralString"},
    {"LiteralString", "LiteralBool", "-"},
    {"LiteralString", "LiteralDouble", "-"},

    {"LiteralBool", "LiteralInt", "LiteralInt"},
    {"LiteralBool", "LiteralFloat", "LiteralFloat"},
    {"LiteralBool", "LiteralString", "-"},
    {"LiteralBool", "LiteralBool", "LiteralInt"},
    {"LiteralBool", "LiteralDouble", "LiteralDouble"},

    {"LiteralDouble", "LiteralInt", "LiteralDouble"},
    {"LiteralDouble", "LiteralFloat", "LiteralDouble"},
    {"LiteralDouble", "LiteralString", "-"},
    {"LiteralDouble", "LiteralBool", "LiteralDouble"},
    {"LiteralDouble", "LiteralDouble", "LiteralDouble"},
};

// pattern
// Literal* [function_name]([l1] left, [l2] right) { return new [result_literal](left->value + right->value); }

/*
int main() { // generate function prototypes
  for (auto& operation : operations) {
    for (auto& combination : combinations) {
      std::cout << "Literal* " << operation << "(" << combination.left << "* left, " << combination.right << "* right);\n";
    }
    std::cout << "\n";
  }
  return 1;
}
*/

int main() {
  for (auto& operation : operations) {
    for (auto& combination : combinations) {
      std::cout << "Literal* "
                << "OperationsDispatcher::" << operation << "("
                << combination.left << "* left, " << combination.right
                << "* right) ";
      if (combination.result == "-") {
        std::cout << "{ throw std::runtime_error(\"Illegal operation["
                  << operation << "] " << combination.left << " | "
                  << combination.right << "!\"); \n";
        std::cout << " return nullptr; }\n";
      } else {
        std::cout << "{ return new " << combination.result << "(left->value "
                  << operationsMap[operation] << " right->value); }\n";
      }
    }
  }
  return 1;
}
