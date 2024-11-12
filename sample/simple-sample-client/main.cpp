#include "ScribeAPI.h"
#include "LoggerToStdOut.h"

#include <iostream>
#include <memory>
#include <string>

class ICosa
{
public:
    virtual void something() = 0;

protected:
    virtual ~ICosa() {};
};

class Cosa : public ICosa
{
public:
    Cosa() = default;
    ~Cosa() = default;
    void something() override
    {
        LOG_VERBOSE("It is something!");
    }
};

int main( int argc, char* argv[])
{
    // Create and configure logger.
    std::shared_ptr<scribe::ILogger> logger = std::make_shared<LoggerToStdOut>();
    scribe::initializeLogger(logger);
    scribe::configMinimunLoggerLevel(logger, scribe::LOG_LEVEL::INFO);

    std::shared_ptr<ICosa> cosa = std::make_shared<Cosa>();

    cosa->something();

    LOG_VERBOSE("hello", ' ', 23, ' ', 3.14, " Bye! " , 2);
    LOG_INFO(1994, " [-] ", "Direction: ", cosa.get());
    LOG_WARNING("qweqwe", "-", 1);
    LOG_ERROR(false, "-", 6);
    LOG_CRITICAL(true, "-", 1);

    return 0;
}