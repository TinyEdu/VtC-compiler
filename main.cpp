#include "Interpreter.h"
#include "GraphicalUserInterface.h"
#include "JsonParser.h"

#if defined(USE_JSON_INPUT)
#include "TextParser.h"
#endif
#if defined(WITH_GUI)
#include "CommandLineUserInterface.h"
#endif

int main(int argc, char *argv[]) {
    std::shared_ptr<vtc::parser::IParser> parser;
#if defined(USE_JSON_INPUT)
    parser = std::make_shared<JsonParser>();
#else
    parser = std::make_shared<TextParser>();
#endif

    std::shared_ptr<vtc::interpreter::IInterpreter> interpreter;
    interpreter = std::make_shared<Interpreter>();

    std::shared_ptr<vtc::ui::IUserInterface> userInterface;
#if defined(WITH_GUI)
    userInterface = std::make_shared<GraphicalUserInterface>(parser, interpreter);
#else
    ui = std::make_shared<CommandLineUserInterface>(parser, interp);
#endif

    return userInterface->run(argc, argv);
}