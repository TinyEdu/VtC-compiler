cmake_minimum_required(VERSION 3.29.1)
project(vtc VERSION 1.0.0 LANGUAGES CXX)

find_package(Qt6 CONFIG REQUIRED COMPONENTS Gui Quick)

# Set necessary paths to ensure correct deployment
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(QT_PLUGIN_PATH "${Qt6_DIR}/../../debug/Qt6/plugins")
    set(QML_IMPORT_PATH "${Qt6_DIR}/../../debug/Qt6/qml")
    set(QML2_IMPORT_PATH "${Qt6_DIR}/../../debug/Qt6/qml")
    find_program(TOOL_WINDEPLOYQT NAMES windeployqt.debug.bat)
else ()
    set(QT_PLUGIN_PATH "${Qt6_DIR}/../../Qt6/plugins")
    set(QML_IMPORT_PATH "${Qt6_DIR}/../../Qt6/qml")
    set(QML2_IMPORT_PATH "${Qt6_DIR}/../../Qt6/qml")
    find_program(TOOL_WINDEPLOYQT NAMES windeployqt)
endif ()

message(STATUS "QT6_DIR: ${Qt6_DIR}")
message(STATUS "QT_PLUGIN_PATH: ${QT_PLUGIN_PATH}")
message(STATUS "QML_IMPORT_PATH: ${QML_IMPORT_PATH}")
message(STATUS "QML2_IMPORT_PATH: ${QML2_IMPORT_PATH}")

qt_standard_project_setup()
qt_policy(SET QTP0001 OLD)


add_subdirectory(ast)
add_subdirectory(interface)
add_subdirectory(cli)
add_subdirectory(gui)
add_subdirectory(interpreter)
add_subdirectory(jsonParser)
add_subdirectory(textParser)

qt_add_executable(${PROJECT_NAME}
        gui/resources.qrc
        main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Gui Qt6::Quick
        ast
        cli
        gui
        interpreter
        jsonParser
        textParser
)

include(cmake/Deployment.cmake)
