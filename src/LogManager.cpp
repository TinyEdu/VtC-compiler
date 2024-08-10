// LogManager.cpp

#include "LogManager.h"
#include <iomanip>

const std::string LogManager::green = "\033[32m";  // Green color for LOG
const std::string LogManager::orange = "\033[33m"; // Yellow/orange color for WARNING
const std::string LogManager::red = "\033[31m";    // Red color for CRITICAL
const std::string LogManager::reset = "\033[0m";   // Reset color

// Set the prefix width for alignment
const int LogManager::prefixWidth = 50;

#ifdef DEBUG_MODE
void LogManager::LogStream::output() const {
    std::string color;

    if (level == "LOG") color = green;
    else if (level == "WARNING") color = orange;
    else if (level == "CRITICAL") color = red;

    std::ostream& out = (level == "LOG") ? std::cout : std::cerr;

    // Format the prefix with fixed width to ensure alignment of the closing bracket
    std::ostringstream prefix;
    prefix << color << "[" << level << "] " << reset
           << "[" << std::setw(15) << std::left << extractFilename(file) << " | "
           << std::setw(4) << std::right << line << " | "
           << std::setw(15) << std::left << function << "]";

    out << std::setw(prefixWidth) << std::setfill(' ') << std::left << prefix.str()
        << " " << buffer.str();
}

#endif
#ifndef DEBUG_MODE
void LogManager::LogStream::output() const {}
#endif

LogManager::LogStream LogManager::Log(const std::string& file, const std::string& function, int line) {
    return LogStream("LOG", file, function, line);
}

LogManager::LogStream LogManager::Warning(const std::string& file, const std::string& function, int line) {
    return LogStream("WARNING", file, function, line);
}

LogManager::LogStream LogManager::CriticalWarning(const std::string& file, const std::string& function, int line) {
    return LogStream("CRITICAL", file, function, line);
}

std::string LogManager::extractFilename(const std::string& path) {
    size_t pos = path.find_last_of("/\\");
    return (pos != std::string::npos) ? path.substr(pos + 1) : path;
}
