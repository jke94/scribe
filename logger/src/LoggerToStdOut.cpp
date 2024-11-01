#include "LoggerToStdOut.h"

#include <iostream>
#include <string>
#include <sstream>

namespace scribe
{
    void LoggerToStdOut::logVerbose(const char* file, const char* function, const int line, const std::string &message)
    {
        log(LOG_LEVEL::VERBOSE, file, function, line, message);
    }

    void LoggerToStdOut::logInfo(const char* file, const char* function, const int line, const std::string &message)
    {
        log(LOG_LEVEL::INFO, file, function, line, message);
    }

    void LoggerToStdOut::logWarning(const char* file, const char* function, const int line, const std::string &message)
    {
        log(LOG_LEVEL::WARNING, file, function, line, message);
    }

    void LoggerToStdOut::logError(const char* file, const char* function, const int line, const std::string &message)
    {
        log(LOG_LEVEL::ERROR, file, function, line, message);
    }

    void LoggerToStdOut::logCritical(const char* file, const char* function, const int line, const std::string &message)
    {
        log(LOG_LEVEL::CRITICAL, file, function, line, message);
    }

    void LoggerToStdOut::log(LOG_LEVEL logLevel, const char* file, const char* function, const int line, const std::string &message)
    {

        std::string fileStr(file);
        size_t pos = fileStr.find_last_of("/\\");
        std::string fileName = (pos == std::string::npos) ? fileStr : fileStr.substr(pos + 1);

        std::stringstream s;

        s << "[" << logLevelEnumToStr(logLevel) << "] ";
        s << "[" << fileName << "|" << function << "|" << line << "]";
        s << " " << message;

        std::cout << s.str() << std::endl;
    }

    std::string LoggerToStdOut::logLevelEnumToStr(LOG_LEVEL logLevel)
    {
        std::string value;

        switch (logLevel)
        {
            case LOG_LEVEL::VERBOSE:
                value = "VERBOSE";
                break;
            case LOG_LEVEL::INFO:
                value = "INFO";
                break;
            case LOG_LEVEL::WARNING:
                value = "WARNING";
                break;
            case LOG_LEVEL::ERROR:
                value = "ERROR";
                break;
            case LOG_LEVEL::CRITICAL:
                value = "CRITICAL";
                break;
            default:
                value = "NO_LEVEL_DEFINED";
                break;
        }

        return value;
    }
}