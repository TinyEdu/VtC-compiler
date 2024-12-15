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

class LogStream;

class LogManager
{
public:
    static LogStream log(std::source_location location = std::source_location::current());
    static LogStream warn(std::source_location location = std::source_location::current());
    static LogStream crit(std::source_location location = std::source_location::current());

    static void display(const std::string& message,
                        std::source_location location, const std::string& color, const std::string& type);

private:
    static std::string extractFilenameAndLine(const std::string& input);
    static std::string extractFunctionName(const std::string& input);
    static std::string extractLastByDelimiter(const std::string& input, char delimiter);
};

class LogStream
{
public:
    LogStream(const std::string& color, const std::string& type, std::source_location location);
    ~LogStream();

    template <typename T>
    LogStream& operator<<(const T& value)
    {
        buffer_ << value;
        return *this;
    }

private:
    std::ostringstream buffer_;
    std::string color_;
    std::string type_;
    std::source_location location_;

    void flush();
};

#endif  // LOGMANAGER_H
