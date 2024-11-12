#include "ScribeAPI.h"
#include "SomeOperations.h"
#include "LoggerToStdOut.h"

#include <thread>

int main( int argc, char* argv[] )
{
    // Create and configure logger.
    std::shared_ptr<scribe::ILogger> logger = std::make_shared<LoggerToStdOut>();
    scribe::initializeLogger(logger);
    scribe::configMinimunLoggerLevel(logger, scribe::LOG_LEVEL::INFO);

    const int n_threads = 500;
    std::thread threads[n_threads] = {};

    for(int i=0; i<n_threads; i++)
    {
        if(i % 2 == 0)
        {
            threads[i] = std::thread(doSomethingA, "[THREAD] " + std::to_string(i) + ": A simple trace message.");
        }
        else if (i % 3 == 0)
        {
            threads[i] = std::thread(doSomethingB, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }
        else if (i % 5 == 0)
        {
            threads[i] = std::thread(doSomethingC, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }
        else if (i % 7 == 0)
        {
            threads[i] = std::thread(doSomethingD, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }        
        else
        {
            threads[i] = std::thread(doSomethingE, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }
    }

    for(int i=0; i<n_threads; i++)
    {
        threads[i].join();
    }

    return 0;
}