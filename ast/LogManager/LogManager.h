#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

// ANSI escape codes for coloring
const static std::string green  = "\033[32m";
const static std::string orange = "\033[33m";
const static std::string red    = "\033[31m";
const static std::string reset  = "\033[0m";

// Minimal replacement for std::source_location (C++20) in C++17.
struct SourceLocation {
    const char* file;
    int line;
    const char* function;

    SourceLocation(const char* file, int line, const char* function)
        : file(file), line(line), function(function) {}
};

class LogStream;

class LogManager {
public:
    static LogStream log(const SourceLocation& location);
    static LogStream warn(const SourceLocation& location);
    static LogStream crit(const SourceLocation& location);

    static void display(const std::string& message,
                        const SourceLocation& location, const std::string& color, const std::string& type);

private:
    static std::string extractFilenameAndLine(const std::string& input);
    static std::string extractFunctionName(const std::string& input);
    static std::string extractLastByDelimiter(const std::string& input, char delimiter);
};

class LogStream {
public:
    LogStream(const std::string& color, const std::string& type, const SourceLocation& location);
    ~LogStream();

    template <typename T>
    LogStream& operator<<(const T& value) {
        buffer_ << value;
        return *this;
    }

private:
    std::ostringstream buffer_;
    std::string color_;
    std::string type_;
    SourceLocation location_;

    void flush();
};

// Macros to capture the call site using __FILE__, __LINE__, and __func__
#define LOG()  LogManager::log(SourceLocation(__FILE__, __LINE__, __func__))
#define WARN() LogManager::warn(SourceLocation(__FILE__, __LINE__, __func__))
#define CRIT() LogManager::crit(SourceLocation(__FILE__, __LINE__, __func__))

#endif // LOGMANAGER_H
