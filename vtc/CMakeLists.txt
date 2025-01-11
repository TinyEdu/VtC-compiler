project(vtc)

set(SOURCE_FILES
        # LogManager
        LogManager/LogManager.cpp

        # Compiler
        Compiler/Compiler.cpp

        # Parser
        Parser/Parser.cpp
        Parser/ParserBase.cpp

        # Scanner
        Scanner/Scanner.cpp
        Scanner/ErrorHandler.cpp

        # Token
        Token/Token.cpp

        # Visitor
        Visitor/OperationsDispatcher.cpp

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
        Statements/ExpressionStatement.cpp
        Statements/IfStatement.cpp
        Statements/WhileStatement.cpp
        Statements/PrintStatement.cpp
        Statements/BlockStatement.cpp
        Statements/FunctionStatement.cpp
        Statements/ClassStatement.cpp
        Statements/VarStatement.cpp
        Statements/ReturnStatement.cpp
        Statements/StatementsWorld.cpp

        # Interpreter
        Interpreter/Interpreter.cpp
        Interpreter/ArityMismatchException.cpp
        Interpreter/NonBooleanConditionException.cpp

        # Callable
        Callable/Callable.cpp
        Callable/Natives/ClockCallable.cpp
        Callable/Natives/FunctionCallable.cpp
        Callable/Return.cpp

        # Environment
        Environment/Environment.cpp
)

add_library(vtc STATIC ${SOURCE_FILES})
target_compile_definitions(vtc PRIVATE DEBUG_MODE)
set(CMAKE_VERBOSE_MAKEFILE ON)
