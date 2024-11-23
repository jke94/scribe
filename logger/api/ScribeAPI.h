#ifndef SCRIBE_API_H
#define SCRIBE_API_H

#include <string>

enum class LOG_LEVEL
{
    VERBOSE,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

enum class LOGGER_INFRASTRUCTURE_RESULT
{
    /** Something was wrong, contact with the logger author. */
    WTF = -1,

    /** OK, logger callback has initialize correctly. */
    OK,

    /** Failure, You've already initialized the logger! */
    FAILURE_HEY_YOU_HAVE_ALREADY_INITIALIZE_THE_LOGGER,

    /** Failure, callback logger is null! */
    FAILURE_CALLBACK_LOGGER_IS_NULL,

    /** Failure, you are trying configure log minimun level log callback before to initialize! */
    FAILURE_CALLBACK_IS_NULL_PLEASE_INITIALIZE_FIRST_THE_CALLBACK_BEFORE_TO_SET_MIN_LOGGER_LEVEL,
};

// SCRIBE INFRASTRUCTURE FUNCTIONS.

LOGGER_INFRASTRUCTURE_RESULT initializeLogger(void(*logCallback)(LOG_LEVEL loglevel, std::string logMessage));
LOGGER_INFRASTRUCTURE_RESULT configMinimunLoggerLevel(LOG_LEVEL loglevel); 


#endif // DEMO_VARIADIC_H