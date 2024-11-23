#include <mutex>
#include <sstream>

#include "LoggerWrapper.h"

namespace scribe
{
    std::mutex mutex_;

    void LoggerWrapper::setLoggerCallback(void (*logCallback)(LOG_LEVEL loglevel, std::string logMessage))
    {
        logCallback_ = logCallback;
    }

    std::function<void(LOG_LEVEL, std::string)> LoggerWrapper::getLoggerCallback()
    {
        return logCallback_;
    }

    void LoggerWrapper::setMinimunLoggerLevel(LOG_LEVEL logLevel)
    {
        // TODO: Add mutex??
        minimunLogLevel_ = logLevel;
    }

    void LoggerWrapper::logVerbose(const char *file, const char *function, const int line, const std::string &message)
    {
        log(file, function, line, message, LOG_LEVEL::VERBOSE);
    }

    void LoggerWrapper::logInfo(const char *file, const char *function, const int line, const std::string &message)
    {
        log(file, function, line, message, LOG_LEVEL::INFO);     
    }

    void LoggerWrapper::logWarning(const char *file, const char *function, const int line, const std::string &message)
    {
        log(file, function, line, message, LOG_LEVEL::WARNING);     
    }

    void LoggerWrapper::logError(const char *file, const char *function, const int line, const std::string &message)
    {
        log(file, function, line, message, LOG_LEVEL::ERROR);     
    }

    void LoggerWrapper::logCritical(const char *file, const char *function, const int line, const std::string &message)
    {
        log(file, function, line, message, LOG_LEVEL::CRITICAL);
    }

    void LoggerWrapper::log(const char *file, const char *function, const int line, const std::string &message, LOG_LEVEL logLevel)
    {
        std::lock_guard<std::mutex> lock(mutex_);

        std::stringstream ss;

        ss << "[" << file << "|" << function << "|" << line << "]";
        ss << " " << message;

        if(logCallback_ && logLevel >= minimunLogLevel_)
        {
            logCallback_(logLevel, ss.str());
        }
    }
}