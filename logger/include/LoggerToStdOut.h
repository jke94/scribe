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

            void logVerbose(const std::string& message) override;
            void logInfo(const std::string& message) override;
            void logWarning(const std::string& message) override;
            void logError(const std::string& message) override;
            void logCritical(const std::string& message) override;            
    };
}

#endif