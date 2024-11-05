#include "SomeOperations.h"
#include <string>

void doSomethingA(std::string msg)
{
    const int value = 1994;
    LOG_INFO("This an ", " example messsge with value: ", value, ". The msg: ", msg);
}

void doSomethingB(std::string msg)
{
    const long value = 123123123123123123;
    LOG_INFO("This an ", " example messsge with value: ", value, ". The msg: ", msg);
}