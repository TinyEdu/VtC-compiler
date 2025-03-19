#pragma once

#if defined(VTC_TEXT_PARSER_EXPORTS)
#  if defined(_WIN32)
#    define VTC_TEXT_PARSER_API __declspec(dllexport)
#  else
#    define VTC_TEXT_PARSER_API __attribute__((visibility("default")))
#  endif
#else
#  define VTC_TEXT_PARSER_API __declspec(dllimport)
#endif

#include "IParser.h"

class VTC_TEXT_PARSER_API TextParser final : public vtc::parser::IParser
{
public:
    std::vector<std::shared_ptr<Statement>> parse(const std::string& input) override;

    ~TextParser() = default;
};
