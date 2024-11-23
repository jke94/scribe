#ifndef I_CALLBACK_HANDLER_H
#define I_CALLBACK_HANDLER_H

class ICallbackHandler
{
public:
    virtual void setUpInitialization() = 0;

protected:
    ~ICallbackHandler() = default;      
};

#endif