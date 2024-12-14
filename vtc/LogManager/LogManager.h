// LogManager.h

#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <iostream>
#include <source_location>
#include <sstream>
#include <string>
#include <vector>
#include <format>
#include <iomanip>

const static std::string green = "\033[32m";
const static std::string orange = "\033[33m";
const static std::string red = "\033[31m";
const static std::string reset = "\033[0m";

class LogManager
{
public:
    static void log(std::string_view message, std::source_location location = std::source_location::current());

    static void warn(std::string_view message, std::source_location location = std::source_location::current());

    static void crit(std::string_view message, std::source_location location = std::source_location::current());

private:
    static void display(std::string_view message,
                        std::source_location location, const std::string& color, const std::string& type);

    static std::string extractFilenameAndLine(const std::string& input);
    static std::string extractFunctionName(const std::string& input);
    static std::string extractLastByDelimiter(const std::string& input, char delimiter);
};

#endif  // LOGMANAGER_H
