#include <memory>

#include "LoggerContainer.h"
#include "ILogger.h"

namespace scribe
{
    std::shared_ptr<ILogger> LoggerContainer::logger_ = nullptr;
}