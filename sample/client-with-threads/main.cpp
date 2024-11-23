#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include "ScribeAPI.h"
#include "SomeOperations.h"
#include "CallbackHandler.h"

std::string loggerInfrastructureEnumToStr(LOGGER_INFRASTRUCTURE_RESULT loggerInfraResult);

int main( int argc, char* argv[] )
{
    std::shared_ptr<CallbackHandler> callbackHandler_ = std::make_shared<CallbackHandler>();
    callbackHandler_->setUpInitialization();

    LOGGER_INFRASTRUCTURE_RESULT  initializeLoggerResult = initializeLogger(callbackHandler_.get()->staticLoggerCallback);

    std::cout << "Initialize logger result: " << loggerInfrastructureEnumToStr(initializeLoggerResult) << std::endl;

    LOGGER_INFRASTRUCTURE_RESULT configLogLevelResult = configMinimunLoggerLevel(LOG_LEVEL::VERBOSE);
    std::cout << "Configuration logger minimun logger level result: " << loggerInfrastructureEnumToStr(configLogLevelResult) << std::endl;    

    const int n_threads = 220;
    std::thread threads[n_threads] = {};

    for(int i=0; i<n_threads; i++)
    {
        if(i % 2 == 0)
        {
            threads[i] = std::thread(doSomethingA, "[THREAD] " + std::to_string(i) + ": A simple trace message.");
        }
        else if (i % 3 == 0)
        {
            threads[i] = std::thread(doSomethingB, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }
        else if (i % 5 == 0)
        {
            threads[i] = std::thread(doSomethingC, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }
        else if (i % 7 == 0)
        {
            threads[i] = std::thread(doSomethingD, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }        
        else
        {
            threads[i] = std::thread(doSomethingE, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }
    }

    for(int i=0; i<n_threads; i++)
    {
        threads[i].join();
    }

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