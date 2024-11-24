# Scribe

C++ logger. Usefull logger based in provide a callback function to get traces with log level and message info to be recived from the client sides.

## Architecture (api folder)

- `ScribeApi.h`: File exported and used by the **client** that allows consume callback and see what events from library that consume `scribe`.

- `ILoggerApi.h`: File not exported to the client that wants to consume the library. Only to the one that wants to use the library. Define the basic functions to be called to log messages with different log levels.

- `Logger.h`: File not exported to the client that wants to consume the library. Only to the one that wants to use the library. It´s allow implement the functions. Define the functions consumed by the macros declared in `ILoggerApi.h`. Abstracting to the library that uses `scribe` as logger system.

## Summary.

`ScribeApi.h` is **the unique file** that must be visible to the client that want consume the callback. `ILoggerApi.h` and `Logger.h`, also must be used to work with `scribe` as logger system.