#include <memory>
#include <string>

#include "ScribeAPI.h"
#include "ILogger.h"
#include "LoggerWrapper.h"
#include "LoggerContainer.h"

using namespace scribe;

LOGGER_INFRASTRUCTURE_RESULT initializeLogger(void(*logCallback)(LOG_LEVEL loglevel, std::string logMessage))
{
    LOGGER_INFRASTRUCTURE_RESULT result = LOGGER_INFRASTRUCTURE_RESULT::WTF;
    
    if(LoggerContainer::logger_)
    {
        result = LOGGER_INFRASTRUCTURE_RESULT::FAILURE_HEY_YOU_HAVE_ALREADY_INITIALIZE_THE_LOGGER;
    
        return result;
    }

    LoggerContainer::logger_ = std::make_shared<LoggerWrapper>();
    LoggerContainer::logger_->setLoggerCallback(logCallback);

    result = LOGGER_INFRASTRUCTURE_RESULT::OK;

    return result;
}

LOGGER_INFRASTRUCTURE_RESULT configMinimunLoggerLevel(LOG_LEVEL loglevel)
{
    LOGGER_INFRASTRUCTURE_RESULT result = LOGGER_INFRASTRUCTURE_RESULT::WTF;

    if(!LoggerContainer::logger_)
    {
        result = LOGGER_INFRASTRUCTURE_RESULT::FAILURE_CALLBACK_IS_NULL_PLEASE_INITIALIZE_FIRST_THE_CALLBACK_BEFORE_TO_SET_MIN_LOGGER_LEVEL;
    
        return result;
    }

    LoggerContainer::logger_->setMinimunLoggerLevel(loglevel);

    result = LOGGER_INFRASTRUCTURE_RESULT::OK;

    return result;
}

