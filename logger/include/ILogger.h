#ifndef I_LOGGER_H
#define I_LOGGER_H

#include <string>

namespace scribe
{
    class ILogger
    {
        public:

            virtual void logVerbose(const std::string& message) = 0;
            virtual void logInfo(const std::string& message) = 0;
            virtual void logWarning(const std::string& message) = 0;
            virtual void logError(const std::string& message) = 0;
            virtual void logCritical(const std::string& message) = 0;

        protected:

            virtual ~ILogger() {};
    };
}

#endif // I_LOGGER_H