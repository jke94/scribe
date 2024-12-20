#ifndef I_LOGGER_CONTAINTER_H
#define I_LOGGER_CONTAINTER_H

#include <memory>

#include "ILogger.h"

namespace scribe
{
    class LoggerContainer
    {
    public:
        static std::shared_ptr<ILogger> logger_;
    };
}

#endif