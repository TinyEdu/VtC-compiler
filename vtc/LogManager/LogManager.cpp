// LogManager.cpp

#include "LogManager.h"

inline void LogManager::log(const std::string_view message, const std::source_location location)
{
    display(message, location, green, "LOG ");
}

inline void LogManager::warn(const std::string_view message, const std::source_location location)
{
    display(message, location, orange, "WARN");
}

inline void LogManager::crit(const std::string_view message, const std::source_location location)
{
    display(message, location, red, "CRIT");
}

inline void LogManager::display(const std::string_view message, const std::source_location location,
                                const std::string& color, const std::string& type)
{
    std::ostringstream oss;

    oss << color << type << " ["
        << extractFilenameAndLine(location.file_name())
        << " | line:" << location.line() << " | "
        << extractFunctionName(location.function_name()) << "] "
        << reset
        << message;

    std::cout << oss.str() << std::endl;
}

inline std::string LogManager::extractFilenameAndLine(const std::string& input)
{
    return extractLastByDelimiter(input, '/');
}

inline std::string LogManager::extractFunctionName(const std::string& input)
{
    return extractLastByDelimiter(input, ' ');
}

inline std::string LogManager::extractLastByDelimiter(const std::string& input, const char delimiter)
{
    std::vector<std::string> parts;
    std::stringstream ss(input);
    std::string token;

    // Split the string using a delimiter
    while (std::getline(ss, token, delimiter))
    {
        parts.push_back(token);
    }

    return parts.back();
}
