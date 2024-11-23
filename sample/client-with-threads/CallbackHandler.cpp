#include "CallbackHandler.h"

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>

std::mutex logMutex_;
std::string CallbackHandler::logFileName_ = "";

void CallbackHandler::setUpInitialization()
{
    logFileName_ = getFormattedDateTime() + "_client-with-threads.log";
}

void CallbackHandler::staticLoggerCallback(LOG_LEVEL loglevel, std::string logMessage)
{
    std::lock_guard<std::mutex> lock(logMutex_);

    std::string levelString = logLevelToString(loglevel);

    std::string formattedMessage = "[" + levelString + "] " + logMessage;

    writeLogToFile(formattedMessage);
}

std::string CallbackHandler::getFormattedDateTime()
{
    std::time_t now = std::time(nullptr);
    std::tm localTime;
#ifdef _WIN32
    localtime_s(&localTime, &now); // Windows
#else
    localtime_r(&now, &localTime); // Linux/Unix
#endif

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d-%H") 
        << "H-" 
        << std::put_time(&localTime, "%M-%S");

    return oss.str();
}

std::string CallbackHandler::logLevelToString(LOG_LEVEL loglevel) 
{
    switch (loglevel) 
    {
        case LOG_LEVEL::VERBOSE:    return "VERBOSE";
        case LOG_LEVEL::INFO:       return "INFO";
        case LOG_LEVEL::WARNING:    return "WARNING";
        case LOG_LEVEL::ERROR:      return "ERROR";
        case LOG_LEVEL::CRITICAL:   return "CRITICAL";
        default: return "LOG_LEVEL_UNKNOWN";
    }
}

void CallbackHandler::writeLogToFile(const std::string& message) 
{
    std::ofstream logFile(logFileName_, std::ios::app);
    
    if (logFile.is_open()) 
    {
        // Escribir el mensaje en el archivo
        logFile << message << std::endl;
    } else 
    {
        // Manejar errores al abrir el archivo
        std::cerr << "Error: No se pudo abrir el archivo de log para escritura." << std::endl;
    }
}
