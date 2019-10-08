#include "PerformanceWatch.h"

namespace Shurikan {

namespace Analyzing {


std::shared_ptr<IPerformanceWatch> IPerformanceWatch::create(const Analyzing::Units &units)
{
    return std::make_shared<PerformanceWatch>(units);
}

uint128 IPerformanceWatch::timeSinceEpoch(const Analyzing::Units &units)
{
    auto time = std::chrono::high_resolution_clock::now().time_since_epoch();

    if(units == Units::NANO_SEC)
    {
        return static_cast<unsigned long long>(std::chrono::duration_cast<std::chrono::nanoseconds>(time).count());
    }
    else if(units == Units::MICRO_SEC)
    {
        return static_cast<unsigned long long>(std::chrono::duration_cast<std::chrono::microseconds>(time).count());
    }
    else if(units == Units::MILLI_SEC)
    {
        return static_cast<unsigned long long>(std::chrono::duration_cast<std::chrono::milliseconds>(time).count());
    }

    return static_cast<unsigned long long>(std::chrono::duration_cast<std::chrono::seconds>(time).count());
}


} //namespace Profiling

} //namespace Shurikan

