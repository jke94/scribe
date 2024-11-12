#ifndef LOGGER_TO_STD_OUT_H
#define LOGGER_TO_STD_OUT_H

#include "ScribeAPI.h"
#include <string>

class LoggerToStdOut : public scribe::ILogger
{
    public:
        LoggerToStdOut() = default;
        ~LoggerToStdOut();

        void setMinimunLoggerLevel(scribe::LOG_LEVEL logLevel) override;
        void logVerbose(const char* file, const char* function, const int line, const std::string& message) override;
        void logInfo(const char* file, const char* function, const int line, const std::string& message) override;
        void logWarning(const char* file, const char* function, const int line, const std::string& message) override;
        void logError(const char* file, const char* function, const int line, const std::string& message) override;
        void logCritical(const char* file, const char* function, const int line, const std::string& message) override;

    private:

        void log(scribe::LOG_LEVEL logLevel, const char* file, const char* function, const int line, const std::string &message);
        std::string logLevelEnumToStr(scribe::LOG_LEVEL logLevel);
        std::string getDateAndTime();

        // TODO: Implement the logic in logger to use this variable in logger. Only work if log level is upper than minimun log level.
        scribe::LOG_LEVEL logLevel_;
};


#endif