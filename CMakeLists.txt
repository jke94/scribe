cmake_minimum_required(VERSION 3.18)

project(ScribeLogger)

add_library(ScribeLogger STATIC
    logger/src/LoggerToFile.cpp
    logger/src/LoggerToStdOut.cpp
    logger/src/ScribeAPI.cpp
)

target_include_directories(ScribeLogger PUBLIC
    logger/include
    logger/api
)

add_executable(SimpleSampleClient 
    sample/simple-sample-client/main.cpp
)

target_link_libraries(SimpleSampleClient PRIVATE 
    ScribeLogger
)

add_executable(ClientWithThreads 
    sample/client-with-threads/main.cpp
    sample/client-with-threads/SomeOperations.cpp
)

target_link_libraries(ClientWithThreads PRIVATE 
    ScribeLogger
)