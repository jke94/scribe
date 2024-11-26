#include <random>

#include "LoggerLibConsumer.h"
#include "LoggerApi.h"

namespace LoggerLibraryConsumer
{
    #define MAX_NUMBER 4991
    #define MIN_MUBER 1994

    LoggerLibConsumer::LoggerLibConsumer()
    {
        LOG_INFO("Created object: ", this);
    }
    LoggerLibConsumer::~LoggerLibConsumer()
    {
        LOG_INFO("Destroyed object: ", this);
    }

    int LoggerLibConsumer::multiplyByARandomNumber(int numberToByMultiplied)
    {
        LOG_VERBOSE("Input number: ", numberToByMultiplied);
        LOG_VERBOSE("Range of random numbers: [MIN: ", MIN_MUBER, ", MAX: ", MAX_NUMBER, "]");

        int result = 0;
        std::random_device seed;
        std::mt19937 gen(seed());
        std::uniform_int_distribution<> dist{MIN_MUBER, MAX_NUMBER}; // set min and max
        int randomNumber = dist(gen);

        LOG_VERBOSE("Rundom number generated: ", randomNumber);

        result = numberToByMultiplied * randomNumber;

        LOG_VERBOSE("Result generated: ", result);

        return result;
    }
}