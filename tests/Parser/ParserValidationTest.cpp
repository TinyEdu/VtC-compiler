#include "gtest/gtest.h"
#include "Parser/Parser.h"
#include "Scanner/Scanner.h"
#include "Expressions/Literals/LiteralInt.h"
#include "Expressions/Variable.h"
#include "Expressions/Assign.h"

TEST(ParserValidation, tts) {
    // given
    const std::string input = "var a = 1; a = 2;";

    // when
    Scanner scanner;
    const std::vector<Token> tokens = scanner.scan(input);
    Parser parser(tokens);
    std::vector<Statement*> statements = parser.parse();

    // then
    // Expected statement 1: var a = 1;
    Token varToken(TokenType::VAR, "var", "", 1);
    Token nameToken(TokenType::IDENTIFIER, "a", "", 1);
    Token equalToken(TokenType::EQUAL, "=", "", 1);
    Expression* initializer = new LiteralInt(1);
    VarStatement* varStmt = new VarStatement(nameToken, initializer);

    // Expected statement 2: a = 2;
    Token assignNameToken(TokenType::IDENTIFIER, "a", "", 2);
    Expression* assignValue = new LiteralInt(2);
    Assign* assignExpr = new Assign(assignNameToken, assignValue);
    ExpressionStatement* assignStmt = new ExpressionStatement(assignExpr);

    // Create expected vector
    std::vector<Statement*> expectedStatements = {varStmt, assignStmt};

    // Validate the size
    ASSERT_EQ(statements.size(), expectedStatements.size());

    // Validate the content of the statements
    // Note: Depending on your implementation of equality for statements and expressions, you may need custom comparison logic.
    for (size_t i = 0; i < statements.size(); ++i) {
        ASSERT_TRUE(*statements[i] == *expectedStatements[i]) << "Mismatch at statement " << i;
    }

    // Cleanup
    delete varStmt;
    delete assignStmt;
    for (Statement* stmt : statements) {
        delete stmt;
    }
}
