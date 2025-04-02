cmake_minimum_required(VERSION 3.29.1)
project(gui LANGUAGES CXX)

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
        resources.qrc

        include/GraphicalUserInterface.h
        src/GraphicalUserInterface.cpp

        src/Anchor/Anchor.h
        src/Anchor/AnchorFactory.h

        src/Collision/CollisionManager.cpp
        src/Collision/CollisionManager.h

        src/MovableBlock/MovableBlock.h

        src/MovableBlock/MovableBlockFactory.h
        src/MovableBlock/MovableBlockFactory.cpp

        src/BlockDiagram/BlockDiagram.h
        src/BlockDiagram/BlockDiagramFactory.h

        src/BlockDiagramManager/BlockDiagramManager.h
        src/BlockDiagramManager/BlockDiagramManager.cpp

        src/Serialization/BlockReader.h
        src/Serialization/BlockReader.cpp
        src/Serialization/BlockReaderException.h

        src/Blocks/BinaryOp.h
        src/Blocks/Block.h
        src/Blocks/Break.h
        src/Blocks/Call.h
        src/Blocks/CreateVarBySignal.h
        src/Blocks/CreateVarByValue.h
        src/Blocks/End.h
        src/Blocks/ForLoop.h
        src/Blocks/GetVar.h
        src/Blocks/If.h
        src/Blocks/Listen.h
        src/Blocks/PrintBySignal.h
        src/Blocks/PrintByValue.h
        src/Blocks/SetVarBySignal.h
        src/Blocks/SetVarByValue.h
        src/Blocks/Skip.h
        src/Blocks/Start.h
        src/Blocks/UnaryOp.h
        src/Blocks/Value.h
        src/Blocks/While.h
        src/Blocks/Connection.h
        src/Serialization/ConnectionReader.cpp
        src/Serialization/ConnectionReader.h
        src/Serialization/ConnectionReaderException.h
        src/Serialization/ProgramSerializator.cpp
        src/Serialization/ProgramSerializator.h
)

target_compile_definitions(${PROJECT_NAME} PRIVATE VTC_GUI_EXPORTS)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Gui Qt6::Quick Qt6::Widgets)

include(../cmake/Deployment.cmake)
