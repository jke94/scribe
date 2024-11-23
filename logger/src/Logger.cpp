#include "Logger.h"
#include "ScribeAPI.h"
#include "ILoggerContainer.h"

using namespace scribe;

void logVerbose(const char* file, const char* function, const int line, const std::string& message)
{
    if(ILoggerContainer::logger_)
    {
        ILoggerContainer::logger_.get()->logVerbose(file, function, line, message);
    }
}

void logInfo(const char* file, const char* function, const int line, const std::string& message)
{
    if(ILoggerContainer::logger_)
    {
        ILoggerContainer::logger_.get()->logInfo(file, function, line, message);
    }
}

void logWarning(const char* file, const char* function, const int line, const std::string& message)
{
    if(ILoggerContainer::logger_)
    {        
        ILoggerContainer::logger_.get()->logWarning(file, function, line, message);
    }
}

void logError(const char* file, const char* function, const int line, const std::string& message)
{
    if(ILoggerContainer::logger_)
    {        
        ILoggerContainer::logger_.get()->logError(file, function, line, message);
    }
}

void logCritical(const char* file, const char* function, const int line, const std::string& message)
{
    if(ILoggerContainer::logger_)
    {        
        ILoggerContainer::logger_.get()->logCritical(file, function, line, message);
    }        
}
