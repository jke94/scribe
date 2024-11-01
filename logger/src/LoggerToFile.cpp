#include "LoggerToStdOut.h"

#include <iostream>
#include <string>

namespace scribe
{
    void LoggerToStdOut::logVerbose(const std::string &message)
    {
        std::cout << "[VERBOSE] " << message << std::endl;
    }
    void LoggerToStdOut::logInfo(const std::string &message)
    {
        std::cout << "[INFO] " << message << std::endl;
    }
    void LoggerToStdOut::logWarning(const std::string &message)
    {
        std::cout << "[WARNING] " << message << std::endl;
    }
    void LoggerToStdOut::logError(const std::string &message)
    {
        std::cout << "[ERROR] " << message << std::endl;
    }
    void LoggerToStdOut::logCritical(const std::string &message)
    {
        std::cout << "[CRITICAL] " << message << std::endl;
    }
}