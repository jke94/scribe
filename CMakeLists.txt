cmake_minimum_required(VERSION 3.20)

project(TheScribe)

set(CMAKE_CXX_STANDARD 11)

#####################################################################################
# Static library logger: ScribeLogger
#####################################################################################

file(GLOB_RECURSE SCRIBE_SRC_FILES RELATIVE
    ${CMAKE_SOURCE_DIR} "logger/src/*.cpp"
)

add_library(ScribeLogger STATIC
    ${SCRIBE_SRC_FILES}
)

target_include_directories(ScribeLogger PUBLIC
    ${CMAKE_SOURCE_DIR} "logger/api"
    ${CMAKE_SOURCE_DIR} "logger/include"
)

#####################################################################################
# Static library logger consumer: LoggerLibConsumer
#####################################################################################

add_library(LoggerLibConsumer STATIC
    ${CMAKE_SOURCE_DIR} "logger-lib-consumer/src/LoggerLibConsumer.cpp"
)

target_include_directories(LoggerLibConsumer PUBLIC
    ${CMAKE_SOURCE_DIR} "logger/api"
    ${CMAKE_SOURCE_DIR} "logger-lib-consumer/include"
)

target_link_libraries(LoggerLibConsumer PRIVATE 
    ScribeLogger
)

#####################################################################################
# Executable to simulate a client that consumes logger callback: SimpleSampleClient
#####################################################################################

add_executable(SimpleSampleClient 
    ${CMAKE_SOURCE_DIR} "sample/simple-sample-client/main.cpp"
)

target_link_libraries(SimpleSampleClient PRIVATE 
    ScribeLogger
    LoggerLibConsumer
)

#####################################################################################
# Executable to simulate a client that consumes logger callback wtih threads: SimpleClientWithThreads
#####################################################################################

file(GLOB_RECURSE SIMPLE_CLIENT_WITH_THREADS_FILES RELATIVE
    ${CMAKE_SOURCE_DIR} "sample/client-with-threads/*.cpp"
)

add_executable(SimpleClientWithThreads 
    ${SIMPLE_CLIENT_WITH_THREADS_FILES}
)

target_link_libraries(SimpleClientWithThreads PRIVATE 
    ScribeLogger
    LoggerLibConsumer
)