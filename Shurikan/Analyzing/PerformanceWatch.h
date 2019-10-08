#ifndef PERFORMANCEWATCH_H
#define PERFORMANCEWATCH_H

#include "IPerformanceWatch.h"

namespace Shurikan {

namespace Analyzing {

class PerformanceWatch : public IPerformanceWatch
{
public:

    PerformanceWatch(const Analyzing::Units &units);
    virtual PerformanceWatch &start() override;
    virtual uint128 lap() override;
    virtual PerformanceWatch &reset() override;
    virtual bool isTimeOver(const uint128 & time_to_check) override;
    virtual uint128 sample() const override;
    virtual uint128 getNumOfLaps() const override {return _laps.size();}
    virtual Units getUnits() const override {return _units;}
    virtual std::vector<uint128> getTimeOfLaps() const override {return _laps;}
    virtual std::vector<uint128> getDiffBetweenLaps() const override {return _diff_laps;}

private: //members
    uint128 _first_sample;
    Units _units;
    std::vector<uint128> _laps;
    std::vector<uint128> _diff_laps;
    bool _is_first_sample;
};

} //namespace Analyzing

} //namespace Shurikan



#endif // PERFORMANCEWATCH_H
