#include "LoggerToStdOut.h"

#include <iostream>
#include <string>

namespace scribe
{
    void LoggerToStdOut::logVerbose(const char* file, const char* function, const int line, const std::string &message)
    {
        std::cout << "[VERBOSE] " << message << std::endl;
    }

    void LoggerToStdOut::logInfo(const char* file, const char* function, const int line, const std::string &message)
    {
        std::cout << "File: " << file << std::endl;
        std::cout << "Function: " << function << std::endl;
        std::cout << "Line: " << line << std::endl;

        std::cout << "[INFO] " << message << std::endl;
    }

    void LoggerToStdOut::logWarning(const char* file, const char* function, const int line, const std::string &message)
    {
        std::cout << "[WARNING] " << message << std::endl;
    }

    void LoggerToStdOut::logError(const char* file, const char* function, const int line, const std::string &message)
    {
        std::cout << "[ERROR] " << message << std::endl;
    }

    void LoggerToStdOut::logCritical(const char* file, const char* function, const int line, const std::string &message)
    {
        std::cout << "[CRITICAL] " << message << std::endl;
    }

    void LoggerToStdOut::log(LOG_LEVEL logLevel, const char* file, const char* function, const int line, const std::string &message)
    {
        std::cout << "[" << logLevelEnumToStr(logLevel) << "] " << message << std::endl;
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
                value = "VERBOSE";
                break;
            case LOG_LEVEL::WARNING:
                value = "VERBOSE";
                break;
            case LOG_LEVEL::ERROR:
                value = "VERBOSE";
                break;
            case LOG_LEVEL::CRITICAL:
                value = "VERBOSE";
                break;
            default:
                value = "NO_LEVEL_DEFINED";
                break;
        }

        return value;
    }
}