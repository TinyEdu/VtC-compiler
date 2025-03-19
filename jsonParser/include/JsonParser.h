#pragma once

#if defined(VTC_JSON_PARSER_EXPORTS)
#  if defined(_WIN32)
#    define VTC_JSON_PARSER_API __declspec(dllexport)
#  else
#    define VTC_JSON_PARSER_API __attribute__((visibility("default")))
#  endif
#else
#  define VTC_JSON_PARSER_API __declspec(dllimport)
#endif

#include "IParser.h"

class VTC_JSON_PARSER_API JsonParser final : public vtc::parser::IParser
{
public:
    std::vector<std::shared_ptr<Statement>> parse(const std::string& input) override;

    ~JsonParser() = default;
};
