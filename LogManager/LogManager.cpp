// LogManager.cpp

#include "LogManager.h"


const std::string LogManager::green = "\033[32m";  // Green color for LOG
const std::string LogManager::orange = "\033[33m"; // Yellow/orange color for WARNING
const std::string LogManager::red = "\033[31m";    // Red color for CRITICAL
const std::string LogManager::reset = "\033[0m";   // Reset color

void LogManager::LogStream::output() const {
#ifdef DEBUG_MODE
    std::ostringstream prefix;
    prefix << getColor(level) << "[" << levelToString(level) << "] " << reset
           << "[" << std::setw(15) << std::left << extractFilename(file)
           << " | " << std::setw(4) << std::right << line
           << " | " << std::setw(15) << std::left << function << "]";

    std::ostream& out = getOutputStream(level);
    out << prefix.str() << " " << buffer.str() << ENDL;
#endif
}

LogManager::LogStream LogManager::Log(const std::string& file,
                                      const std::string& function, int line) {
    return LogStream(LogLevel::LOG, file, function, line);
}

LogManager::LogStream LogManager::Warning(const std::string& file,
                                          const std::string& function,
                                          int line) {
    return LogStream(LogLevel::WARNING, file, function, line);
}

LogManager::LogStream LogManager::CriticalWarning(const std::string& file,
                                                  const std::string& function,
                                                  int line) {
    return LogStream(LogLevel::CRITICAL, file, function, line);
}

std::string LogManager::extractFilename(const std::string& path) {
    return std::filesystem::path(path).filename().string();
}

std::string LogManager::getColor(LogLevel level) {
    switch (level) {
        case LogLevel::LOG: return green;
        case LogLevel::WARNING: return orange;
        case LogLevel::CRITICAL: return red;
    }
    return reset;
}

std::string LogManager::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::LOG: return "LOG";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::CRITICAL: return "CRITICAL";
    }
    return "UNKNOWN";
}

std::ostream& LogManager::getOutputStream(LogLevel level) {
    return (level == LogLevel::LOG) ? std::cout : std::cerr;
}
