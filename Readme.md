# scribe

1. C++ logger implementation based in a expansible concept: write your custom logger implementation.
2. C++ logger usefull logger based in provide a callback function to get traces with log level and message info to be recived from the client sides.

## Architecture (`logger/api` folder)

### Internal logger files.

- `LoggerApi.h`: File not exported to the client that wants to consume the library. Only to the one that wants to use the library. Define the basic functions to be called to log messages with different log levels.

- `Logger.h`: File not exported to the client that wants to consume the library. Only to the one that wants to use the library. It´s allow implement the functions. Define the functions consumed by the macros declared in `LoggerApi.h`. Abstracting to the library that uses `scribe` as logger system.

### External file consumed by the client.

- `ScribeApi.h`: The file that the clients can do `#include` to consume `scribe` logger.

## Usage example:

```
#include <string>
#include "ScribeApi.h"

void logCallbackFunction(LOG_LEVEL loglevel, std::string logMessage)
{
    // TODO: Implement the function reaction. Example, std::cout.
}

int main(int argc, char* argv[])
{
    LOGGER_INFRASTRUCTURE_RESULT initializeLoggerResult = initializeLogger(logCallbackFunction);
    LOGGER_INFRASTRUCTURE_RESULT configLogLevelResult = configMinimunLoggerLevel(LOG_LEVEL::VERBOSE);

    return 0;
}
```

## Summary

`ScribeApi.h` is **the unique file** that must be visible to the client that want consume the callback. `LoggerApi.h` and `Logger.h`, also must be used to work with `scribe` as logger system.

