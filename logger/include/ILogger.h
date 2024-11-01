#ifndef I_LOGGER_H
#define I_LOGGER_H

#include <string>

namespace scribe
{
    enum class LOG_LEVEL
    {
        VERBOSE,
        INFO,
        WARNING,
        ERROR,
        CRITICAL
    };

    class ILogger
    {
        public:

            virtual void logVerbose(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logInfo(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logWarning(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logError(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logCritical(const char* file, const char* function, const int line, const std::string& message) = 0;

        protected:

            virtual ~ILogger() {};
    };
}

#endif // I_LOGGER_H