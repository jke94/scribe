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

add_executable(ScribeClient 
    sample/main.cpp
)

target_link_libraries(ScribeClient PRIVATE 
    ScribeLogger
)