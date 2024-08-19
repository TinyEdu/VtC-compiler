#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> types = {
  "LiteralInt",
  "LiteralFloat",
  "LiteralString",
  "LiteralBool",
  "LiteralDouble"
};


std::vector<std::string> operations = {
  "add",
  "subtract",
  "multiply",
  "divide",
  "modulo",
  "equal",
  "not_equal",
  "greater_than",
  "less_than",
  "greater_than_or_equal",
  "less_than_or_equal"
};



struct comb {
  std::string left;
  std::string right;
  std::string result;
};

std::vector<comb> combinations = {
  {"LiteralInt", "LiteralInt", "LiteralInt"},
  {"LiteralInt", "LiteralFloat", "LiteralFloat"},
  {"LiteralInt", "LiteralString", "LiteralString"},
  {"LiteralInt", "LiteralBool", "LiteralInt"},
  {"LiteralInt", "LiteralDouble", "LiteralDouble"},

  {"LiteralFloat", "LiteralInt", "LiteralFloat"},
  {"LiteralFloat", "LiteralFloat", "LiteralFloat"},
  {"LiteralFloat", "LiteralString", "LiteralString"},
  {"LiteralFloat", "LiteralBool", "LiteralFloat"},
  {"LiteralFloat", "LiteralDouble", "LiteralDouble"},

  {"LiteralString", "LiteralInt", "LiteralString"},
  {"LiteralString", "LiteralFloat", "LiteralString"},
  {"LiteralString", "LiteralString", "LiteralString"},
  {"LiteralString", "LiteralBool", "LiteralString"},
  {"LiteralString", "LiteralDouble", "LiteralString"},

  {"LiteralBool", "LiteralInt", "LiteralInt"},
  {"LiteralBool", "LiteralFloat", "LiteralFloat"},
  {"LiteralBool", "LiteralString", "LiteralString"},
  {"LiteralBool", "LiteralBool", "LiteralInt"},
  {"LiteralBool", "LiteralDouble", "LiteralDouble"},

  {"LiteralDouble", "LiteralInt", "LiteralDouble"},
  {"LiteralDouble", "LiteralFloat", "LiteralDouble"},
  {"LiteralDouble", "LiteralString", "LiteralString"},
  {"LiteralDouble", "LiteralBool", "LiteralDouble"},
  {"LiteralDouble", "LiteralDouble", "LiteralDouble"},
};

// pattern
// Literal* [function_name]([l1] left, [l2] right) { return new [result_literal](left->value + right->value); }



int main() {
  std::string a = "abc";
  std::cout << "This is a working template\n";
  return 1;
}