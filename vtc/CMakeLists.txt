project(vtc)

set(HEADER_FILES
        LogManager/LogManager.h
        Compiler/Compiler.h
        Parser/Parser.h
        Scanner/Scanner.h
        Token/Token.h
        Token/TokenType.h
        Scanner/ErrorHandler.h
        Token/TokenTypeMappings.h
)

set(SOURCE_FILES
        LogManager/LogManager.cpp
        Compiler/Compiler.cpp
        Parser/Parser.cpp
        Token/Token.cpp
        Scanner/Scanner.cpp
        Scanner/ErrorHandler.cpp
)

add_library(vtc STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_compile_definitions(vtc PRIVATE DEBUG_MODE)