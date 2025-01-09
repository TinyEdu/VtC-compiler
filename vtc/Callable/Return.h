#ifndef RETURN_H
#define RETURN_H

#include <any>
#include <stdexcept>

class Return final : public std::exception
{
public:
    explicit Return(std::any value);

    std::any value;

    [[nodiscard]] const char* what() const noexcept override;
};

#endif // RETURN_H
