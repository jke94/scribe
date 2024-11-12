cmake_minimum_required(VERSION 3.18)

project(ScribeLogger)

add_library(ScribeLogger STATIC
    logger/src/ScribeAPI.cpp
)

target_include_directories(ScribeLogger PUBLIC
    logger/api
)

add_executable(SimpleSampleClient 
    sample/simple-sample-client/main.cpp
    sample/simple-sample-client/LoggerToStdOut.cpp
)

target_link_libraries(SimpleSampleClient PRIVATE 
    ScribeLogger
)

add_executable(ClientWithThreads 
    sample/client-with-threads/main.cpp
    sample/client-with-threads/LoggerToStdOut.cpp
    sample/client-with-threads/SomeOperations.cpp
)

target_link_libraries(ClientWithThreads PRIVATE 
    ScribeLogger
)