#ifndef RETURN_H
#define RETURN_H

#include <any>
#include <memory>
#include <stdexcept>
#include <Expressions/Literals/Literal.h>

class Return final : public std::exception
{
public:
    explicit Return(std::shared_ptr<Literal> value);

    std::shared_ptr<Literal> value;

    [[nodiscard]] const char* what() const noexcept override;
};

#endif // RETURN_H
