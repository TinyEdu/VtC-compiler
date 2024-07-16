#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void defineAst(std::string outputDir, std::string baseName,
               std::vector<std::string> types) {
  std::string path = outputDir + "/" + baseName + ".h";
  std::ofstream writer(path);

  if (!writer) {
    throw std::ios_base::failure("Failed to open file: " + path);
  }

  writer << "#pragma once\n\n";
  writer << "#include <vector>\n";
  writer << "#include <string>\n\n";
  writer << "namespace Transpiler {\n\n";
  writer << "class " << baseName << " {\n";
  writer << "public:\n";
  writer << "    virtual ~" << baseName << "() = default;\n";
  writer << "};\n\n";
  writer << "} // namespace lox\n";

  writer.close();
}

int main(int argc, char** argv) {
  if (argc == 2) {
    std::cout << "Generating ast at:" << argv[1] << "!\n";

  } else {
    std::cerr << "Wrong amount of input.\n";
    return 64;
  }

  defineAst(std::string(argv[1]), "Expr",
            {"Binary   : Expr left, Token op, Expr right",
             "Grouping : Expr expression", "Literal  : std::any value",
             "Unary    : Token op, Expr right"});

  return 1;
}