cmake_minimum_required(VERSION 3.29)
project(vtc-compiler)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.1\\mingw_64")


find_package(Qt6 COMPONENTS
        Core
        Quick
        QuickControls2
        Gui
        REQUIRED)

set(SOURCE_FILES
        main.cpp
        gui/Core/GuiMain/GuiMain.h
        gui/Core/GuiMain/GuiMain.cpp
        gui/MovableBlock/MovableBlock.h
        gui/Anchor/Anchor.h
        gui/Collision/CollisionManager.h
        gui/Collision/CollisionManager.cpp
        gui/MovableBlock/MovableBlockFactory.h
        gui/MovableBlock/MovableBlockFactory.cpp
        gui/Anchor/AnchorFactory.h
)

qt_policy(SET QTP0001 NEW)
qt_add_executable(vtc-compiler ${SOURCE_FILES})

include_directories(vtc)
include_directories(gui)

add_subdirectory(vtc)
add_subdirectory(tests)

target_compile_definitions(vtc-compiler PRIVATE ENABLE_ANSI_COLOR)
target_compile_definitions(vtc-compiler PRIVATE DEBUG_MODE)

target_link_libraries(vtc-compiler PRIVATE
        vtc
        Qt6::Core
        Qt6::Gui
        Qt6::Quick
        Qt6::QuickControls2)

# Add QML module
qt_add_qml_module(vtc-compiler
        URI cpp.MovableBlock
        VERSION 1.0
        QML_FILES
        gui/qmls/main.qml
        gui/qmls/Anchor.qml
        gui/qmls/BezierConnection.qml
        gui/qmls/BlockDiagram.qml
        SOURCES
        gui/Core/GuiMain/GuiMain.cpp
        gui/Core/GuiMain/GuiMain.h
        gui/MovableBlock/MovableBlock.h
        gui/Anchor/Anchor.h
        gui/Anchor/AnchorFactory.h
        gui/Collision/CollisionManager.cpp
        gui/Collision/CollisionManager.h
)


