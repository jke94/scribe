#include "LoggerToStdOut.h"
#include "ScribeAPI.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <string>
#include <sstream>

using namespace scribe;

std::mutex mtx;

LoggerToStdOut::~LoggerToStdOut()
{
    std::cout << "Logger destructor called. Memory object direction: " << this << std::endl;
}

void LoggerToStdOut::setMinimunLoggerLevel(scribe::LOG_LEVEL logLevel)
{
    logLevel_ = logLevel;
}

void LoggerToStdOut::logVerbose(const char *file, const char *function, const int line, const std::string &message)
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
    std::lock_guard<std::mutex> lock(mtx);

    std::string fileStr(file);
    size_t pos = fileStr.find_last_of("/\\");
    std::string fileName = (pos == std::string::npos) ? fileStr : fileStr.substr(pos + 1);

    std::stringstream s;

    s << "[" << getDateAndTime() << "]";
    s << "[" << logLevelEnumToStr(logLevel) << "]";
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

std::string LoggerToStdOut::getDateAndTime()
{
    const auto now = std::chrono::system_clock::now();
    const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
    const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    
    std::stringstream nowSs{};
    
#if defined(_WIN32) || defined(__CYGWIN__)

    time_t rawtime = std::time(nullptr);
    struct tm timeinfo;
    auto lc_time = localtime_s(&timeinfo, &rawtime);

    nowSs << std::put_time(&timeinfo, "%Y-%m-%d %X")
    << '.' << std::setfill('0') << std::setw(3) << nowMs.count();

#elif defined(__linux__)

    nowSs << std::put_time(std::localtime(&nowAsTimeT), "%Y-%m-%d %X")
        << '.' << std::setfill('0') << std::setw(3) << nowMs.count();
#else
    nowSs << "[ERROR_GET_TIME]";
#endif

    return nowSs.str();
}