// LogManager.h

#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <source_location>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class LogManager {
public:
    class LogStream {
    public:
        LogStream(const std::string& level, const std::string& file,
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
        std::string level;
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

    // ANSI escape codes for colors
    static const std::string green;
    static const std::string orange;
    static const std::string red;
    static const std::string reset;

    // Maximum width for the log prefix to align the closing bracket
    static const int prefixWidth;
};

// Macros to simplify logging
#define ENDL "\n"
#define LOG LogManager::Log(std::source_location::current())
#define WARN LogManager::Warning(std::source_location::current())
#define CRIT LogManager::CriticalWarning(std::source_location::current())

#endif  // LOGMANAGER_H