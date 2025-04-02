#ifndef BLOCKREADEREXCEPTION_H
#define BLOCKREADEREXCEPTION_H

#include <stdexcept>
#include <string>

class ConnectionReaderException : public std::runtime_error {
public:
    explicit ConnectionReaderException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif //BLOCKREADEREXCEPTION_H
