#include "LogManager.h"

// LogStream implementation
LogStream::LogStream(const std::string& color, const std::string& type, const SourceLocation& location)
    : color_(color), type_(type), location_(location)
{
}

LogStream::~LogStream() {
    flush();
}

void LogStream::flush() {
    LogManager::display(buffer_.str(), location_, color_, type_);
}

// LogManager implementation
LogStream LogManager::log(const SourceLocation& location) {
    return LogStream(green, "LOG ", location);
}

LogStream LogManager::warn(const SourceLocation& location) {
    return LogStream(orange, "WARN", location);
}

LogStream LogManager::crit(const SourceLocation& location) {
    return LogStream(red, "CRIT", location);
}

void LogManager::display(const std::string& message,
                         const SourceLocation& location, const std::string& color, const std::string& type)
{
    std::ostringstream oss;

    oss << color << type << " ["
        << extractFilenameAndLine(location.file)
        << " | line:" << location.line << " | "
        << extractFunctionName(location.function) << "] "
        << reset
        << message;

    std::cout << oss.str() << std::endl;
}

std::string LogManager::extractFilenameAndLine(const std::string& input) {
    return extractLastByDelimiter(input, '/');
}

std::string LogManager::extractFunctionName(const std::string& input) {
    return extractLastByDelimiter(input, ' ');
}

std::string LogManager::extractLastByDelimiter(const std::string& input, const char delimiter) {
    std::vector<std::string> parts;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        parts.push_back(token);
    }

    return parts.empty() ? input : parts.back();
}
