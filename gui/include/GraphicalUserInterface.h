#pragma once

#if defined(VTC_GUI_EXPORTS)
#  if defined(_WIN32)
#    define VTC_GUI_API __declspec(dllexport)
#  else
#    define VTC_GUI_API __attribute__((visibility("default")))
#  endif
#else
#  define VTC_GUI_API __declspec(dllimport)
#endif

#include "IUserInterface.h"

class VTC_GUI_API GraphicalUserInterface final : public vtc::ui::IUserInterface
{
public:
    using IUserInterface::IUserInterface;
    int run(int argc, char *argv[]) override;
};
