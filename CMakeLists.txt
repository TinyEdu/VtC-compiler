cmake_minimum_required(VERSION 3.29)
project(vtc-compiler)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.1\\mingw_64")


add_definitions(-std=gnu++20)

find_package(Qt6 COMPONENTS
        Quick
        Gui
        REQUIRED)

set(SOURCE_FILES
        main.cpp
        gui/Core/GuiMain/GuiMain.cpp
        gui/Core/GuiMain/GuiMain.h)

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
        Qt6::Gui
        Qt6::Quick)

# Add QML module
qt_add_qml_module(vtc-compiler
        URI gui
        VERSION 1.0
        QML_FILES
        gui/qmls/main.qml
)

qt_add_resources(vtc-compiler "resources"
        PREFIX
        "/"
        FILES
        gui/qmls/main.qml
)



