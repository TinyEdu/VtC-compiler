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

#include <qqmlapplicationengine.h>

#include "IUserInterface.h"
#include "Anchor/AnchorFactory.h"
#include "BezierConnection/BezierConnectionFactory.h"
#include "BlockDiagram/BlockDiagramFactory.h"
#include "GuiController/GuiController.h"

class VTC_GUI_API GraphicalUserInterface final : public vtc::ui::IUserInterface
{
public:
    using IUserInterface::IUserInterface;
    int run(int argc, char *argv[]) override;

private:
    void initializeInstances(QQmlApplicationEngine& engine);
    void loadEngine(const QGuiApplication& app, QQmlApplicationEngine& engine);
    void prepareContexts(QQmlApplicationEngine& engine) const;
    static bool initializedSuccessfully(QQmlApplicationEngine& engine);

    std::shared_ptr<GuiController> guiController;

    std::shared_ptr<BlockDiagramFactory> blockDiagramFactory;
    std::shared_ptr<BezierConnectionFactory> bezierConnectionFactoryCPP;
    std::shared_ptr<AnchorFactory> anchorFactory;

    const QUrl url = QUrl(QStringLiteral("qrc:qml/main.qml"));
};
