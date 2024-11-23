#include "ScribeAPI.h"
#include "LoggerLibConsumer.h"

#include <iostream>
#include <memory>
#include <string>

using namespace LoggerLibraryConsumer;

std::string loggerInfrastructureEnumToStr(LOGGER_INFRASTRUCTURE_RESULT loggerInfraResult);

void logCallbackFunction(LOG_LEVEL loglevel, std::string logMessage)
{
    std::cout<< logMessage << std::endl;
}

int main(int argc, char* argv[])
{
    LOGGER_INFRASTRUCTURE_RESULT initializeLoggerResult = initializeLogger(logCallbackFunction);
    std::cout << "Initialize logger result: " << loggerInfrastructureEnumToStr(initializeLoggerResult) << std::endl;

    LOGGER_INFRASTRUCTURE_RESULT configLogLevelResult = configMinimunLoggerLevel(LOG_LEVEL::VERBOSE);
    std::cout << "Configuration logger minimun logger level result: " << loggerInfrastructureEnumToStr(configLogLevelResult) << std::endl;

    std::shared_ptr<LoggerLibConsumer> itemA = std::make_shared<LoggerLibConsumer>();
    int itemAResult = itemA->multiplyByARandomNumber(1994);
    std::cout<< "Result A: " << itemAResult << std::endl;

    LoggerLibConsumer itemB;
    int itemBResult = itemA->multiplyByARandomNumber(2024);
    std::cout<< "Result B: " << itemBResult << std::endl;

    return 0;
}

std::string loggerInfrastructureEnumToStr(LOGGER_INFRASTRUCTURE_RESULT loggerInfraResult)
{
    std::string value;

    switch (loggerInfraResult)
    {
        case LOGGER_INFRASTRUCTURE_RESULT::WTF:
            value = "WTF";
            break;
        case LOGGER_INFRASTRUCTURE_RESULT::OK:
            value = "OK";
            break;
        case LOGGER_INFRASTRUCTURE_RESULT::FAILURE_HEY_YOU_HAVE_ALREADY_INITIALIZE_THE_LOGGER:
            value = "FAILURE_HEY_YOU_HAVE_ALREADY_INITIALIZE_THE_LOGGER";
            break;
        case LOGGER_INFRASTRUCTURE_RESULT::FAILURE_CALLBACK_LOGGER_IS_NULL:
            value = "FAILURE_CALLBACK_LOGGER_IS_NULL";
            break;
        case LOGGER_INFRASTRUCTURE_RESULT::FAILURE_CALLBACK_IS_NULL_PLEASE_INITIALIZE_FIRST_THE_CALLBACK_BEFORE_TO_SET_MIN_LOGGER_LEVEL:
            value = "FAILURE_CALLBACK_IS_NULL_PLEASE_INITIALIZE_FIRST_THE_CALLBACK_BEFORE_TO_SET_MIN_LOGGER_LEVEL";
            break;
        default:
            value = "NO_LEVEL_DEFINED";
            break;
    }

    return value;
}