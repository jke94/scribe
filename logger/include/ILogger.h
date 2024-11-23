#ifndef I_LOGGER_H
#define I_LOGGER_H

#include <functional>
#include <string>

#include "ScribeApi.h"

namespace scribe
{
    class ILogger
    {
        public:
            virtual void logVerbose(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logInfo(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logWarning(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logError(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logCritical(const char* file, const char* function, const int line, const std::string& message) = 0;

            virtual void setMinimunLoggerLevel(LOG_LEVEL logLevel) = 0;
            virtual void setLoggerCallback(void(*logCallback)(LOG_LEVEL loglevel, std::string logMessage)) = 0;
            virtual std::function<void(LOG_LEVEL, std::string)> getLoggerCallback() = 0;
            
        protected:

            virtual ~ILogger() {};
    };
}

#endif