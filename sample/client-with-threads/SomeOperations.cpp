#include "SomeOperations.h"
#include <string>

void doSomethingA(std::string msg)
{
    const int value = 1994;
    LOG_VERBOSE("This an ", "example messsge with value: ", value, ". The msg: ", msg);
}

void doSomethingB(std::string msg)
{
    const long value = 123123123123123123;
    LOG_INFO("This an ", "example messsge with value: ", value, ". The msg: ", msg);
}

void doSomethingC(std::string msg)
{
    const double value = 12.123123123123123123;
    LOG_WARNING("This an ", "example messsge with value: ", value, ". The msg: ", msg);
}

void doSomethingD(std::string msg)
{
    const float value = -12.123123123123123123;
    LOG_ERROR("This an ", "example messsge with value: ", value, ". The msg: ", msg);
}

void doSomethingE(std::string msg)
{
    const float value = -11.11;
    LOG_CRITICAL("This an ", "example messsge with value: ", value, ". The msg: ", msg);    
}