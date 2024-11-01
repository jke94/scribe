#include <iostream>
#include <memory>
#include <string>

#include "ScribeAPI.h"
#include "ILogger.h"
#include "LoggerToStdOut.h"

namespace scribe
{
    std::shared_ptr<ILogger> logger_ = std::make_shared<LoggerToStdOut>();

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
}