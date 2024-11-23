#include <memory>

#include "ILoggerContainer.h"
#include "ILogger.h"

namespace scribe
{
    std::shared_ptr<ILogger> ILoggerContainer::logger_ = nullptr;
}