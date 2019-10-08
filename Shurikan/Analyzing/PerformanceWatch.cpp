#include "PerformanceWatch.h"

namespace Shurikan {

namespace Analyzing {

PerformanceWatch::PerformanceWatch(const Analyzing::Units &units) :
    _first_sample(0),
    _units(units),
    _laps(),
    _diff_laps(),
    _is_first_sample(false)
{

}

PerformanceWatch &PerformanceWatch::start()
{
    _is_first_sample = true;

    _first_sample = sample();

    return *this;
}

uint128 PerformanceWatch::lap()
{
    if(!_is_first_sample)
    {
        info("cannot use lap without start the PerformaceWatch first");
        return 0;
    }

    auto curr_sample = sample();

    _laps.push_back(curr_sample);

    if(_laps.size() > 1)
    {
        _diff_laps.push_back(curr_sample - _laps[_laps.size() - 2]);
    }

    return curr_sample;
}

PerformanceWatch &PerformanceWatch::reset()
{
    _first_sample = 0;
    _laps.clear();
    _diff_laps.clear();
    _is_first_sample = false;

    return *this;
}

bool PerformanceWatch::isTimeOver(const uint128 &time_to_check)
{
    if(!_is_first_sample)
    {
        info("cannot check time without start the PerformaceWatch first");
        return 0;
    }

    return sample() >= time_to_check;
}

uint128 PerformanceWatch::sample() const
{
    return timeSinceEpoch(_units) - _first_sample;
}

} //namespace Profiling

} //namespace Shurikan


