#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>

std::vector<std::string> types = {"LiteralInt", "LiteralFloat", "LiteralString",
                                  "LiteralBool", "LiteralDouble"};

std::map<std::string, std::string> typesMap = {
    {"INT", "LiteralInt"},
    {"FLOAT", "LiteralFloat"},
    {"STRING", "LiteralString"},
    {"BOOL", "LiteralBool"},
    {"DOUBLE", "LiteralDouble"},
    {"*", "*"},
    {"-", "-"},
    {"R", "R"}, 
    {"X", "X"}};

std::map<std::string, std::string> operationsMap = {
    {"add", "+"},
    {"subtract", "-"},
    {"multiply", "*"},
    {"divide", "/"},
    {"equal", "=="},
    {"not_equal", "!="},
    {"greater_than", ">"},
    {"less_than", "<"},
    {"greater_than_or_equal", ">="},
    {"less_than_or_equal", "<="}};

std::vector<std::string> operations = {"add", "subtract", "multiply", "divide", "equal",
                                       "not_equal", "greater_than", "less_than", "greater_than_or_equal",
                                       "less_than_or_equal"};

std::map<int,int> negations = {
    {0, 1},
    {4, 5},
    {6, 7},
    {8, 9}
};

// Function to convert lines of CSV content into a matrix
std::vector<std::vector<std::string>> parseCSV(const std::vector<std::string>& lines) {
    std::vector<std::vector<std::string>> mtx;

    for (const auto& line : lines) {
        std::vector<std::string> row;
        std::stringstream line_stream(line);
        std::string cell;

        // Process each cell in the line
        while (std::getline(line_stream, cell, ',')) {
            row.push_back(cell);
        }

        // Handle the case where the line ends with a comma, adding an empty cell
        if (line.back() == ',') {
            row.push_back("");
        }

        // Add the row to the matrix
        mtx.push_back(row);
    }

    return mtx;
}


struct mtxStruct {
    std::vector<std::vector<std::string>> matrix;
    std::string function;
};

// Function to read all matrixes from a file
std::vector<mtxStruct> getAllMatrixes(std::string filepath) {
     std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return {};
    }   

    std::vector<mtxStruct> matrices;

    std::string line, function;
    while (file.eof() == false) {
        std::getline(file, line);

        // load function name
        size_t pos = line.find(',');
        function = line.substr(0, pos);

        std::vector<std::string> lines;
        // load lines of data in matrix
        for (int i = 0; i < 6; i++) {
            if (std::getline(file, line)) {
                lines.push_back(line);
            }
            else {
                throw std::runtime_error("Invalid file format");
            }
        }

        // get the matrix
        auto matrix = parseCSV(lines);

        matrices.push_back({matrix, function});

       // skip a line if it exists
        std::getline(file, line);
    }

    // close all files
    file.close();

    return matrices;
}

#include <algorithm> 
#include <cctype>
#include <locale>

// Helper function to trim whitespace from both ends of a string
std::string trim(const std::string& str) {
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        start++;
    }

    auto end = str.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

// Converts all given matrices with typesMap
std::vector<mtxStruct> convertMarixes(std::vector<mtxStruct> matrices) {
    // Replace every string with according typesMap
    for (auto& mtx : matrices) {
        for (auto& row : mtx.matrix) {
            for (auto& cell : row) {
                std::string originalCell = cell;
                cell = trim(cell); // Trim whitespace

                if (typesMap.find(cell) != typesMap.end()) {
                    cell = typesMap[cell];
                } else {
                    std::cerr << "Warning: Key '" << originalCell << "' not found in typesMap." << std::endl;
                }
            }
        }
    }

    return matrices;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <csv_file>" << std::endl;
        return 0;
    }

    // ------------------------------------------------------------------------

    auto matrices = getAllMatrixes(argv[1]);
    matrices = convertMarixes(matrices);
    
    // ------------------------------------------------------------------------

    // print matrixes
    for (auto mtx : matrices) {
        std::cout << "Function: " << mtx.function << std::endl;
        for (auto row : mtx.matrix) {
            for (auto cell : row) {
                std::cout << cell << "|";
            }
            std::cout << "+" << std::endl;
        }
        std::cout << std::endl;
    }

    std::ofstream cppfile("OperationsDispatcher.cpp");
    
    // coreners - are the inputs
    // the value is the result type
    for (auto mtx : matrices) {
        cppfile << "// Function: " << mtx.function << std::endl;
        for(int i = 1; i < mtx.matrix.size(); i++) {
            for(int j = 1; j < mtx.matrix[i].size(); j++) {
                cppfile << "static Literal* " << mtx.function << "(" << mtx.matrix[0][j] << "* left, " << mtx.matrix[i][0] << "* right);\n";
            }
        }
        cppfile << std::endl;
    }
    
    cppfile.close();

    // ------------------------------------------------------------------------

    std::ofstream hfile("OperationsDispatcher.h");
    hfile << "#include \"OperationsDispatcher.h\"\n";
    hfile << "#include \"Literal.h\"\n";
    hfile << "#include \"LiteralBool.h\"\n";
    hfile << "#include \"LiteralDouble.h\"\n";
    hfile << "#include \"LiteralFloat.h\"\n";
    hfile << "#include \"LiteralInt.h\"\n";
    hfile << "#include \"LiteralString.h\"\n\n";

    /*
    Literal* OperationsDispatcher::add(LiteralInt* left, LiteralInt* right) {
    return new LiteralInt(left->value + right->value);
    }
    */
    int index = 0;
    for (auto mtx : matrices) {
        hfile << "// Function: " << mtx.function << std::endl;
        for(int i = 1; i < mtx.matrix.size(); i++) {
            for(int j = 1; j < mtx.matrix[i].size(); j++) {
                hfile << "Literal* OperationsDispatcher::" << mtx.function << "(" << mtx.matrix[0][j] << "* left, " << mtx.matrix[i][0] << "* right) {\n";
                // based on the mtx.matrix[i][j] we can get the result type
                if (mtx.matrix[i][j] == "") {
                    // do nothing

                }
                    if (mtx.matrix[i][j] == "-") {
                    // illegal operation
                    hfile << "throw std::runtime_error(\"Illegal operation[" << mtx.function << "] " << mtx.matrix[0][j] << " | " << mtx.matrix[i][0] << "!\");\nreturn nullptr;\n}\n\n";
                }
                else {
                    hfile << "return new " << mtx.matrix[i][j] << "(left->value " << operationsMap[mtx.function] << " right->value);\n}\n\n";
                }
            }
        }
        index++;
        hfile << std::endl;
    }

    hfile.close();

    return 0;
}
