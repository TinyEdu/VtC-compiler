cmake_minimum_required(VERSION 3.29.1)
project(ast LANGUAGES CXX)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(${PROJECT_NAME} SHARED
        # Visitor
        Visitor/Visitor.h
        Visitor/OperationsDispatcher.cpp
        Visitor/OperationsDispatcher.h

        # Token
        Token/Token.h
        Token/Token.cpp
        Token/TokenTypeMappings.h
        Token/TokenType.h

        # Expressions
        Expressions/Assign.cpp
        Expressions/Binary.cpp
        Expressions/Call.cpp
        Expressions/Grouping.cpp
        Expressions/Logical.cpp
        Expressions/Unary.cpp
        Expressions/Variable.cpp
        Expressions/Literals/Literal.cpp
        Expressions/Literals/LiteralBool.cpp
        Expressions/Literals/LiteralDouble.cpp
        Expressions/Literals/LiteralFloat.cpp
        Expressions/Literals/LiteralInt.cpp
        Expressions/Literals/LiteralString.cpp

        # Statements
        Statements/Statement.h
        Statements/StatementsWorld.h
        Statements/BlockStatement.h
        Statements/ClassStatement.h
        Statements/ExpressionStatement.h
        Statements/FunctionStatement.h
        Statements/IfStatement.h
        Statements/PrintStatement.h
        Statements/ReturnStatement.h
        Statements/VarStatement.h
        Statements/WhileStatement.h

        Statements/BlockStatement.cpp
        Statements/ClassStatement.cpp
        Statements/ExpressionStatement.cpp
        Statements/FunctionStatement.cpp
        Statements/IfStatement.cpp
        Statements/PrintStatement.cpp
        Statements/ReturnStatement.cpp
        Statements/VarStatement.cpp
        Statements/WhileStatement.cpp

        # Log Manager
        LogManager/LogManager.h
        LogManager/LogManager.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
