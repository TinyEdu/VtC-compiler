// LogManager.cpp

#include "LogManager.h"

const std::string LogManager::green = "\033[32m";  // Green color for LOG
const std::string LogManager::orange = "\033[33m"; // Yellow/orange color for WARNING
const std::string LogManager::red = "\033[31m";    // Red color for CRITICAL
const std::string LogManager::reset = "\033[0m";   // Reset color


#ifdef DEBUG_MODE

void LogManager::Log(const std::string& message, const std::string& file, const std::string& function, int line) {
    std::cout << green << "[LOG] " << reset
              << "[" << extractFilename(file) << " | " 
              << std::setw(4) << std::setfill(' ') << line << " | " << function << "] "
              << message << std::endl;
}


void LogManager::Warning(const std::string& message, const std::string& file, const std::string& function, int line) {
    std::cerr << orange << "[WAR] " << reset
              << "[" << extractFilename(file) << " | " 
              << std::setw(4) << std::setfill(' ') << line << " | " << function << "] "
              << message << std::endl;
}

void LogManager::CriticalWarning(const std::string& message, const std::string& file, const std::string& function, int line) {
    std::cerr << red << "[CRI] " << reset
              << "[" << extractFilename(file) << " | " 
              << std::setw(4) << std::setfill(' ') << line << " | " << function << "] "
              << message << std::endl;
}


std::string LogManager::extractFilename(const std::string& path) {
  // Find the last occurrence of the path separator
    size_t pos = path.find_last_of("/\\");
    if (pos != std::string::npos) {
        return path.substr(pos + 1);
    }
    else {
        LogManager::CriticalWarning("Failed to extract filename from path: " + path, "LogManager.cpp", __FUNCTION__, __LINE__);
    }

    return path;
}

#endif // DEBUG_MODE

#ifndef DEBUG_MODE

void LogManager::Log(const std::string& message, const std::string& file, const std::string& function, int line) {
    ;
}


void LogManager::Warning(const std::string& message, const std::string& file, const std::string& function, int line) {
    ;
}

void LogManager::CriticalWarning(const std::string& message, const std::string& file, const std::string& function, int line) {
    ;
}


std::string LogManager::extractFilename(const std::string& path) {
    return path;
}

#endif // RELEASE_MODE