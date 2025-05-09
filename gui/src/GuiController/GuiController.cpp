#include "GuiController.h"

#include <iostream>
#include <sstream>

#include "LogManager/LogManager.h"
#include "Serialization/ProgramSerializator.h"

#define CAPTURE_STDOUT(outputStream, codeBlock)                             \
{                                                                           \
std::stringstream _captureStream;                                           \
std::streambuf* _originalBuffer = std::cout.rdbuf(_captureStream.rdbuf());  \
codeBlock                                                                   \
std::cout.rdbuf(_originalBuffer);                                           \
outputStream = _captureStream.str();                                        \
}

void GuiController::save()
{
    const std::string projectAsJson = ProgramSerializator::instance()->saveToJson();

    // @TODO: open interface to save json and save it
    const auto parsedProject = parser->parse(projectAsJson);


    std::cout<<"Project as json:\n";
    std::cout << projectAsJson;
}

#include <chrono>
QString GuiController::run()
{
    using namespace std::chrono;

    auto start = high_resolution_clock::now();

    const std::string projectAsJson = ProgramSerializator::instance()->saveToJson();

    // @TODO: open interface to save json and save it
    const auto parsedProject = parser->parse(projectAsJson);

    std::string output;
    CAPTURE_STDOUT(output, {
        interpreter->execute(parsedProject);
    });

    auto end = high_resolution_clock::now(); // end time
    auto executionTime = duration_cast<milliseconds>(end - start).count(); // duration in ms

    output = "Parsed Project to json. \nProject: \n" + projectAsJson + "\nFinished extracting AST.\n" +
        "Finished building project.\n" + "Executing build project...\n-----------------------------------"
                                         "\nResult:\n-----------------------------------\n" + output +
                                             "\n-----------------------------------\n  Finished in " +
            std::to_string(executionTime) + " ms.\n";

    LogManager::LOG() << output;

    return QString(output.c_str());
}
