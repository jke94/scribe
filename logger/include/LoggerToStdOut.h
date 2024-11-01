#ifndef I_LOGGER_TO_STD_OUT_H
#define I_LOGGER_TO_STD_OUT_H

#include "ILogger.h"
#include <string>

namespace scribe
{
    class LoggerToStdOut : public ILogger
    {
        public:
            LoggerToStdOut() = default;
            ~LoggerToStdOut() = default;

            void logVerbose(const char* file, const char* function, const int line, const std::string& message) override;
            void logInfo(const char* file, const char* function, const int line, const std::string& message) override;
            void logWarning(const char* file, const char* function, const int line, const std::string& message) override;
            void logError(const char* file, const char* function, const int line, const std::string& message) override;
            void logCritical(const char* file, const char* function, const int line, const std::string& message) override;

        private:

            void log(LOG_LEVEL logLevel, const char* file, const char* function, const int line, const std::string &message);
            std::string logLevelEnumToStr(LOG_LEVEL logLevel);
    };
}

#endif