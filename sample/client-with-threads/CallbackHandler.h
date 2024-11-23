#ifndef CALLBACK_HANDLER_H
#define CALLBACK_HANDLER_H

#include <string>
#include "ICallbackHandler.h"
#include "ScribeApi.h"

class CallbackHandler : public ICallbackHandler
{
public:
    CallbackHandler() = default;
    void setUpInitialization() override;

    static void staticLoggerCallback(LOG_LEVEL loglevel, std::string logMessage);

private:
    static void writeLogToFile(const std::string& message);
    static std::string logLevelToString(LOG_LEVEL loglevel);
    std::string getFormattedDateTime();
    static std::string logFileName_;
};

#endif