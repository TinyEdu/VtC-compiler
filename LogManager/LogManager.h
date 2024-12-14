// LogManager.h

#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
#include <filesystem>


class LogManager {
public:
    enum class LogLevel { LOG, WARNING, CRITICAL };

    class LogStream {
    public:
        LogStream(LogLevel level, const std::string& file,
                  const std::string& function, int line)
            : level(level), file(file), function(function), line(line) {}

        template <typename T>
        LogStream& operator<<(const T& msg) {
#ifdef DEBUG_MODE
            buffer << msg;
#endif
            return *this;
        }

        ~LogStream() {
            output();
        }

    private:
        LogLevel level;
        std::string file;
        std::string function;
        int line;
        std::ostringstream buffer;

        void output() const;
    };

    static LogStream Log(const std::string& file, const std::string& function,
                         int line);
    static LogStream Warning(const std::string& file, const std::string& function,
                             int line);
    static LogStream CriticalWarning(const std::string& file,
                                     const std::string& function, int line);

private:
    static std::string extractFilename(const std::string& path);
    static std::string getColor(LogLevel level);
    static std::string levelToString(LogLevel level);
    static std::ostream& getOutputStream(LogLevel level);

    // ANSI escape codes for colors
    static const std::string green;
    static const std::string orange;
    static const std::string red;
    static const std::string reset;
};

// Macros to simplify logging
#define ENDL "\n"
#define LOG LogManager::Log(__FILE__, __FUNCTION__, __LINE__)
#define WARN LogManager::Warning(__FILE__, __FUNCTION__, __LINE__)
#define CRIT LogManager::CriticalWarning(__FILE__, __FUNCTION__, __LINE__)

#endif  // LOGMANAGER_H
