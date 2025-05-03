cmake_minimum_required(VERSION 3.29.1)
project(interpreter LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED
        include/Interpreter.h
        src/Interpreter.cpp

        src/Callable/Callable.cpp
        src/Callable/Callable.h
        src/Callable/Return.cpp
        src/Callable/Return.h

        src/Callable/Natives/ClockCallable.cpp
        src/Callable/Natives/ClockCallable.h
        src/Callable/Natives/FunctionCallable.cpp
        src/Callable/Natives/FunctionCallable.h

        src/Environment/Environment.cpp
        src/Environment/Environment.h
        src/Environment/EnvironmentException.h
        src/Environment/NotFoundInScopeException.h
        src/Environment/SymbolTable.h

        src/Interpreter/BaseInterpreter.cpp
        src/Interpreter/BaseInterpreter.h
        src/Interpreter/ArityMismatchException.cpp
        src/Interpreter/ArityMismatchException.h
        src/Interpreter/MissingInitializerException.h
        src/Interpreter/NonBooleanConditionException.cpp
        src/Interpreter/NonBooleanConditionException.h
)

target_compile_definitions(${PROJECT_NAME} PRIVATE VTC_INTERPRETER_EXPORTS)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../interface
        ${CMAKE_CURRENT_SOURCE_DIR}/../ast
)

target_link_libraries(${PROJECT_NAME} PRIVATE ast)