#include "ScribeAPI.h"

#include <memory>
#include <string>

namespace scribe
{
    std::shared_ptr<ILogger> logger_;

    void logVerbose(const char* file, const char* function, const int line, const std::string& message)
    {
        if(logger_)
        {
            logger_.get()->logVerbose(file, function, line, message);
        }
    }

    void logInfo(const char* file, const char* function, const int line, const std::string& message)
    {
        if(logger_)
        {
            logger_.get()->logInfo(file, function, line, message);
        }
    }

    void logWarning(const char* file, const char* function, const int line, const std::string& message)
    {
        if(logger_)
        {        
            logger_.get()->logWarning(file, function, line, message);
        }
    }

    void logError(const char* file, const char* function, const int line, const std::string& message)
    {
        if(logger_)
        {        
            logger_.get()->logError(file, function, line, message);
        }
    }

    void logCritical(const char* file, const char* function, const int line, const std::string& message)
    {
        if(logger_)
        {        
            logger_.get()->logCritical(file, function, line, message);
        }        
    }
    
    void initializeLogger(std::shared_ptr<ILogger> logger)
    {
        logger_ = std::move(logger);
    }

    void configMinimunLoggerLevel(std::shared_ptr<ILogger> logger, scribe::LOG_LEVEL loggerLevel)
    {
        if(logger_)
        {
            logger->setMinimunLoggerLevel(loggerLevel);
        }
    }
}

