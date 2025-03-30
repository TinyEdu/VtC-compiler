#ifndef BLOCKREADEREXCEPTION_H
#define BLOCKREADEREXCEPTION_H

#include <stdexcept>
#include <string>

class BlockReaderException : public std::runtime_error {
public:
    explicit BlockReaderException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif //BLOCKREADEREXCEPTION_H
