#include <memory>
#include <string>

#include "SomeOperations.h"
#include "LoggerLibConsumer.h"

using namespace LoggerLibraryConsumer;

void doSomethingA(std::string msg)
{
    const int value = 1994;
    std::shared_ptr<LoggerLibConsumer> item = std::make_shared<LoggerLibConsumer>();
    int itemResult = item->multiplyByARandomNumber(value);
}

void doSomethingB(std::string msg)
{
    const long value = 123123123123123123;
    std::shared_ptr<LoggerLibConsumer> item = std::make_shared<LoggerLibConsumer>();
    int itemResult = item->multiplyByARandomNumber(value);
}

void doSomethingC(std::string msg)
{
    const double value = 12.123123123123123123;
    std::shared_ptr<LoggerLibConsumer> item = std::make_shared<LoggerLibConsumer>();
    int itemResult = item->multiplyByARandomNumber(value);
}

void doSomethingD(std::string msg)
{
    const float value = -12.123123123123123123;
    std::shared_ptr<LoggerLibConsumer> item = std::make_shared<LoggerLibConsumer>();
    int itemResult = item->multiplyByARandomNumber(value);
}

void doSomethingE(std::string msg)
{
    const float value = -11.11;
    std::shared_ptr<LoggerLibConsumer> item = std::make_shared<LoggerLibConsumer>();
    int itemResult = item->multiplyByARandomNumber(value);
}