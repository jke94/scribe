#include <iostream>
#include <memory>
#include <string>

#include "ScribeAPI.h"

namespace scribe
{
    std::shared_ptr<ILogger> logger_;

    void logVerbose(const char* file, const char* function, const int line, const std::string& message)
    {
        logger_.get()->logVerbose(file, function, line, message);
    }

    void logInfo(const char* file, const char* function, const int line, const std::string& message)
    {
        logger_.get()->logInfo(file, function, line, message);
    }

    void logWarning(const char* file, const char* function, const int line, const std::string& message)
    {
        logger_.get()->logWarning(file, function, line, message);
    }

    void logError(const char* file, const char* function, const int line, const std::string& message)
    {
        logger_.get()->logError(file, function, line, message);
    }

    void logCritical(const char* file, const char* function, const int line, const std::string& message)
    {
        logger_.get()->logCritical(file, function, line, message);
    }
    
    void initializeLogger(std::shared_ptr<ILogger> logger)
    {
        // TODO dynamic cast.
        logger_ = std::move(logger);
    }

    void configMinimunLoggerLevel(std::shared_ptr<ILogger> logger, scribe::LOG_LEVEL loggerLevel)
    {
        logger->setMinimunLoggerLevel(loggerLevel);
    }

    // void finalizeLogger(std::shared_ptr<ILogger>& logger)
    // {
    //      // TODO
    // }    
}

