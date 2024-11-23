#ifndef LOGGER_WRAPPER_H
#define LOGGER_WRAPPER_H

#include <functional>
#include <string>

#include "ILogger.h"

namespace scribe
{
    class LoggerWrapper : public ILogger
    {

    public:
        LoggerWrapper() = default;

        void setMinimunLoggerLevel(LOG_LEVEL logLevel) override;

        void logVerbose(const char* file, const char* function, const int line, const std::string& message) override;
        void logInfo(const char* file, const char* function, const int line, const std::string& message) override;
        void logWarning(const char* file, const char* function, const int line, const std::string& message) override;
        void logError(const char* file, const char* function, const int line, const std::string& message) override;
        void logCritical(const char* file, const char* function, const int line, const std::string& message) override;

        void setLoggerCallback(void(*logCallback)(LOG_LEVEL loglevel, std::string logMessage)) override;
        std::function<void(LOG_LEVEL, std::string)> getLoggerCallback() override;

    private:

        LOG_LEVEL minimunLogLevel_ = LOG_LEVEL::VERBOSE;
        void log(const char* file, const char* function, const int line, const std::string& message, LOG_LEVEL logLevel);
        void(*logCallback_)(LOG_LEVEL loglevel, std::string logMessage) = nullptr;
    };
}

#endif