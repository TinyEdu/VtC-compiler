#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> types = {"LiteralInt", "LiteralFloat", "LiteralString",
                                  "LiteralBool", "LiteralDouble"};

std::map<std::string, std::string> typeMap = {
    {"LiteralInt", "int"}, {"LiteralFloat", "float"}, 
    {"LiteralString", "std::string"}, 
    {"LiteralBool", "bool"}, {"LiteralDouble", "double"}};


std::string forwardDeclaration(std::string type) {
  std::string result = "class Expression;\n"
                       "class Literal;\n";

  for(auto& t : types) {
    if(t != type) {
      result += "class " + t + ";\n"; 
    }
  }
  return result;
}

std::string contructor(std::string type) {
  return type + "(" + typeMap[type] +" value) : value(value) {};\n\n"
          "" + typeMap[type] +" value;\n\n";
} 

std::string process(std::string type) {
  std::string result = "virtual Expression* process(Literal* expr, Token token) override {\n"
    "return expr->process(this, token);\n"
    "};\n\n";

  for(auto& t : types) {
    result += "virtual Expression* process(" + t + "* expr, Token token);\n";
  }

  return result;
};

std::string printoverload(std::string type) {
  return "\nfriend std::ostream& operator<<(std::ostream& os, const " + type + "* expr) {\n"
         "  os << expr->value;\n"
         "  return os;\n"
         "};\n"
         "\n"
         "friend std::ostream& operator<<(std::ostream& os, const " + type + "& expr) {\n"
         "  os << expr.value;\n"
          "  return os;\n"
          "};\n\n";

}

std::string start(std::string type) {
  return "// " + type + ".h\n\n"
         "#ifndef " + type + "_H\n"
         "#define " + type + "_H\n\n"
         "#include \"string.h\"\n\n"
         "" + forwardDeclaration(type) + ""
         "\nclass " + type + " : public Literal {\n\n";
}


#include <fstream>

int main() {
  // iterate over types and generate the header files
  for(auto& type : types) {
    std::string filename = type + ".h";
    std::ofstream file(filename);
    file << start(type);
    file << contructor(type);
    file << process(type);
    file << printoverload(type);
    file << "};\n#endif  // " + type + "_H\n";
    file.close();

    std::ofstream cppfile(type + ".cpp");
    
    for(auto& t : types) {
      if(t != type) {
        cppfile << "#include \"" + t + ".h\"\n";
      }
    }
    cppfile << "#include \"OperationsDispatcher.h\"\n";

    cppfile << "Expression* " + type + "::process(LiteralInt* expr, Token token) {\n"
            "  return OperationsDispatcher::dispatch(expr, this, token);\n"
            "};\n\n";
    cppfile << "Expression* " + type + "::process(LiteralFloat* expr, Token token) {\n"
            "  return OperationsDispatcher::dispatch(expr, this, token);\n"
            "};\n\n";    
    cppfile << "Expression* " + type + "::process(LiteralString* expr, Token token) {\n"
            "  return OperationsDispatcher::dispatch(expr, this, token);\n"
            "};\n\n";
    cppfile << "Expression* " + type + "::process(LiteralBool* expr, Token token) {\n"
            "  return OperationsDispatcher::dispatch(expr, this, token);\n"
            "};\n\n";
    cppfile << "Expression* " + type + "::process(LiteralDouble* expr, Token token) {\n"
            "  return OperationsDispatcher::dispatch(expr, this, token);\n"
            "};\n\n";
    cppfile.close();
  }

  return 0;
}
