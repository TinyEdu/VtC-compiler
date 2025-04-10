cmake_minimum_required(VERSION 3.29.1)
project(textParser LANGUAGES CXX)

find_package(Qt6 CONFIG REQUIRED COMPONENTS Gui Quick Widgets)

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

add_library(${PROJECT_NAME} SHARED
        include/JsonParser.h
        src/JsonParser.cpp

        src/JsonReader/JsonReader.cpp
        src/JsonReader/JsonReader.h

        src/vo/Connection.h
        src/vo/Block.h
        src/vo/Block.cpp

        src/BlockExtractor/BlockExtractor.cpp
        src/BlockExtractor/BlockExtractor.h

        src/Anchor/Anchor.h
        src/Anchor/Anchor.cpp
)

target_compile_definitions(${PROJECT_NAME} PRIVATE VTC_JSON_PARSER_EXPORTS)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
        ${CMAKE_CURRENT_SOURCE_DIR}/../ast
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Gui Qt6::Quick Qt6::Widgets ast)

include(../cmake/Deployment.cmake)