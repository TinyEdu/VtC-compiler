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
    {"DOUBLE", "LiteralDouble"}};

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

// Negations
// q1: equal -> not_equal
// q2: greater_than -> less_than
// q4: greater_than_or_equal -> less_than_or_equal
// q5: add -> subtract

std::vector<std::pair<int,int>> negations = {
    {0, 1},
    {4, 5},
    {6, 7},
    {8, 9}
};

// if * -> the operation is not allowed

int main(int argc, char* argv[]) {
    // load the csv file
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <csv_file>" << std::endl;
        return 0;
    } else {
        std::cout << "Loading file: " << argv[1] << std::endl;
    }

    std::fstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::ofstream cppfile("OperationsDispatcher.cpp");
    std::ofstream hfile("OperationsDispatcher.h");

    std::string line;
    std::string function;

    while (file.is_open() && !file.eof()) {
        if (std::getline(file, line)) {
            if (line.empty()) continue;  // Skip empty lines

            // Read the function name from the first line
            std::stringstream ss(line);
            std::getline(ss, function, ',');  // The first element is the function name

            // Initialize the matrix with the size of types
            std::vector<std::vector<std::string>> matrix(types.size(), std::vector<std::string>(types.size(), "-"));

            // Read the next `types.size()` lines to fill the matrix
            for (int i = 0; i < types.size(); i++) {
                if (std::getline(file, line)) {
                    std::stringstream ss(line);
                    std::string element;
                    std::getline(ss, element, ','); // Skip the first element (row type name)

                    int j = 0;
                    while (std::getline(ss, element, ',')) {
                        matrix[i][j] = element;
                        j++;
                    }
                }
            }

            // Process the matrix (e.g., print it out for now)
            std::cout << "Function: " << function << std::endl;
            for (int i = 0; i < types.size(); i++) {
                for (int j = 0; j < types.size(); j++) {
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        // Skip the empty line separating blocks in the CSV file
        if (std::getline(file, line)) {}
    }

    // close all files
    file.close();
    cppfile.close();
    hfile.close();
    return 0;
}
