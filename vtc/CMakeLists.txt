project(vtc)

set(HEADER_FILES
        # LogManager
        LogManager/LogManager.h

        # Compiler
        Compiler/Compiler.h

        # Parser
        Parser/Parser.h
        Parser/ParseError.h
        Parser/ParserBase.h

        # Scanner
        Scanner/Scanner.h
        Scanner/ErrorHandler.h

        # Token
        Token/Token.h
        Token/TokenType.h
        Token/TokenTypeMappings.h

        # Visitor
        Visitor/Visitor.h
        Visitor/OperationsDispatcher.h

        # Expressions
        Expressions/Expression.h
        Expressions/Assign.h
        Expressions/Binary.h
        Expressions/Call.h
        Expressions/Grouping.h
        Expressions/Logical.h
        Expressions/Unary.h
        Expressions/Variable.h
        Expressions/Literals/Literal.h
        Expressions/Literals/LiteralBool.h
        Expressions/Literals/LiteralDouble.h
        Expressions/Literals/LiteralFloat.h
        Expressions/Literals/LiteralInt.h
        Expressions/Literals/LiteralString.h

        # Statements
        Statements/Statement.h
        Statements/ExpressionStatement.h
        Statements/IfStatement.h
        Statements/WhileStatement.h
        Statements/PrintStatement.h
        Statements/BlockStatement.h
        Statements/FunctionStatement.h
        Statements/ClassStatement.h
        Statements/VarStatement.h
        Statements/ReturnStatement.h
        Statements/StatementsWorld.h

        # Interpreter
        Interpreter/Interpreter.h
        Interpreter/ArityMismatchException.h
        Interpreter/NonBooleanConditionException.h
        Interpreter/MissingInitializerException.h

        # Environment
        Environment/Environment.h
        Environment/EnvironmentException.h

        # Callable
        Callable/Callable.h
        Callable/Natives/ClockCallable.h
        Callable/Natives/FunctionCallable.h
        Callable/Return.h
)

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
        Statements/Statement.cpp
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
        Environment/Environment.cpp
        Environment/SymbolTable.cpp
)

add_library(vtc STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_compile_definitions(vtc PRIVATE DEBUG_MODE)
