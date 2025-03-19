#pragma once

#if defined(VTC_INTERPRETER_EXPORTS)
#  if defined(_WIN32)
#    define VTC_INTERPRETER_API __declspec(dllexport)
#  else
#    define VTC_INTERPRETER_API __attribute__((visibility("default")))
#  endif
#else
#  define VTC_INTERPRETER_API __declspec(dllimport)
#endif

#include "IInterpreter.h"

class VTC_INTERPRETER_API Interpreter final : public vtc::interpreter::IInterpreter
{
public:
    std::string execute(const std::vector<std::shared_ptr<Statement>>& statements) override;
    ~Interpreter() = default;
};
