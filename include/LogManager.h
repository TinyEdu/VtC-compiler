// LogManager.h

#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <string>
#include <iomanip>
#include <iostream>


class LogManager {
public:
    // Log methods with source location parameters
    static void Log(const std::string& message, const std::string& file, const std::string& function, int line);
    static void Warning(const std::string& message, const std::string& file, const std::string& function, int line);
    static void CriticalWarning(const std::string& message, const std::string& file, const std::string& function, int line);

private:
    static std::string extractFilename(const std::string& path);

private:
    // ANSI escape codes for colors
    static const std::string green;
    static const std::string orange;
    static const std::string red;
    static const std::string reset;
};

// Macro to simplify logging
#define LOG(message) LogManager::Log((message), __FILE__, __FUNCTION__, __LINE__)
#define WARN(message) LogManager::Warning((message), __FILE__, __FUNCTION__, __LINE__)
#define CRIT_WARN(message) LogManager::CriticalWarning((message), __FILE__, __FUNCTION__, __LINE__)


#endif // LOGMANAGER_H
