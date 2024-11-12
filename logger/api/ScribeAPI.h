#ifndef SCRIBE_API_H
#define SCRIBE_API_H

#include <memory>
#include <sstream>
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

            virtual void setMinimunLoggerLevel(LOG_LEVEL logLevel) = 0;

            virtual void logVerbose(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logInfo(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logWarning(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logError(const char* file, const char* function, const int line, const std::string& message) = 0;
            virtual void logCritical(const char* file, const char* function, const int line, const std::string& message) = 0;

        protected:

            virtual ~ILogger() {};
    };

    template <typename... Args>
    std::string build_message(const Args&... args) 
    {
        std::ostringstream stream;
        int dummy[] = {0, (stream << args, 0)...};
        return stream.str();
    }

    // SCRIBE FUNCTIONS WRAPPED TO BE USED BY LOGGER CALLS.

    void logVerbose(const char* file, const char* function, const int line, const std::string& message);
    void logInfo(const char* file, const char* function, const int line, const std::string& message);
    void logWarning(const char* file, const char* function, const int line, const std::string& message);
    void logError(const char* file, const char* function, const int line, const std::string& message);
    void logCritical(const char* file, const char* function, const int line, const std::string& message);

    // SCRIBE INFRASTRUCTURE FUNCTIONS.

    void initializeLogger(std::shared_ptr<ILogger> logger);
    void configMinimunLoggerLevel(std::shared_ptr<ILogger> logger, LOG_LEVEL loggerLevel); 
}

#ifndef LOG_DISABLE

#define LOG_VERBOSE(...) scribe::logVerbose(__FILE__, __FUNCTION__, __LINE__, scribe::build_message(__VA_ARGS__))
#define LOG_INFO(...) scribe::logInfo(__FILE__, __FUNCTION__, __LINE__, scribe::build_message(__VA_ARGS__))
#define LOG_WARNING(...) scribe::logWarning(__FILE__, __FUNCTION__, __LINE__, scribe::build_message(__VA_ARGS__))
#define LOG_ERROR(...) scribe::logError(__FILE__, __FUNCTION__, __LINE__, scribe::build_message(__VA_ARGS__))
#define LOG_CRITICAL(...) scribe::logCritical(__FILE__, __FUNCTION__, __LINE__, scribe::build_message(__VA_ARGS__))

#else

#define LOG_INFO
#define LOG_VERBOSE
#define LOG_WARNING
#define LOG_ERROR
#define LOG_CRITICAL

#endif // LOG_DISABLE

#endif // DEMO_VARIADIC_H