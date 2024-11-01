#include "ScribeAPI.h"

#include <iostream>
#include <memory>
#include <string>

class ICosa
{
protected:
    virtual ~ICosa() {};
};

class Cosa : public ICosa
{
public:
    Cosa() = default;
    ~Cosa() = default;
};

int main( int argc, char* argv[] )
{
    std::shared_ptr<ICosa> cosa = std::make_shared<Cosa>();

    LOG_VERBOSE("hello", ' ', 23, ' ', 3.14, " Bye! " , 2);
    LOG_INFO(1994, " [-] ", "Direction: ", cosa.get());
    LOG_WARNING("qweqwe", "-", 1);
    LOG_ERROR(false, "-", 6);
    LOG_CRITICAL(true, "-", 1);

    return 0;
}