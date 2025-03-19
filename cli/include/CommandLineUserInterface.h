#pragma once

#if defined(VTC_CLI_EXPORTS)
#  if defined(_WIN32)
#    define VTC_CLI_API __declspec(dllexport)
#  else
#    define VTC_CLI_API __attribute__((visibility("default")))
#  endif
#else
#  define VTC_CLI_API __declspec(dllimport)
#endif

#include "IUserInterface.h"

class VTC_CLI_API CommandLineUserInterface final : public vtc::ui::IUserInterface
{
public:
    using IUserInterface::IUserInterface;
    int run(int argc, char *argv[]) override;
};
