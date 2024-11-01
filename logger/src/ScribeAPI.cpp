#include <iostream>
#include <memory>
#include <string>

#include "ScribeAPI.h"
#include "ILogger.h"
#include "LoggerToStdOut.h"

#include <iostream>

namespace scribe
{
    std::shared_ptr<ILogger> logger_ = std::make_shared<LoggerToStdOut>();

    void logVerbose(const char* file, const char* function, const int line, const std::string& message)
    {
        #ifndef LOG_DISABLE

        logger_.get()->logVerbose(message);
        
        #endif
    }

    void logInfo(const char* file, const char* function, const int line, const std::string& message)
    {
        #ifndef LOG_DISABLE

        std::cout << "File: " << file << std::endl;
        std::cout << "Function: " << function << std::endl;
        std::cout << "Line: " << line << std::endl;

        logger_.get()->logInfo(message);

        #endif
    }

    void logWarning(const char* file, const char* function, const int line, const std::string& message)
    {
        logger_.get()->logWarning(message);
    }

    void logError(const char* file, const char* function, const int line, const std::string& message)
    {
        logger_.get()->logError(message);
    }

    void logCritical(const char* file, const char* function, const int line, const std::string& message)
    {
        logger_.get()->logCritical(message);
    }            
}