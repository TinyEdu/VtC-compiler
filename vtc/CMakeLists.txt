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
        Statements/Statement.h
        Parser/ParseError.h
)

set(SOURCE_FILES
        LogManager/LogManager.cpp
        Compiler/Compiler.cpp
        Parser/Parser.cpp
        Token/Token.cpp
        Scanner/Scanner.cpp
        Scanner/ErrorHandler.cpp
        Visitor/Visitor.h
        Expressions/Assign.cpp
        Expressions/Binary.cpp
        Expressions/Call.cpp
        Expressions/Grouping.cpp
        Expressions/Logical.cpp
        Expressions/Unary.cpp
        Expressions/Variable.cpp
        Statements/Statement.cpp
        Expressions/Literals/Literal.cpp
        Expressions/Literals/LiteralBool.cpp
        Expressions/Literals/LiteralDouble.cpp
        Expressions/Literals/LiteralFloat.cpp
        Expressions/Literals/LiteralInt.cpp
        Expressions/Literals/LiteralString.cpp
        Visitor/OperationsDispatcher.cpp
)

add_library(vtc STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_compile_definitions(vtc PRIVATE DEBUG_MODE)