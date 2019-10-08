#ifndef IPERFORMANCEWATCH_H
#define IPERFORMANCEWATCH_H

#include "PerformanceWatch_types.h"

namespace Shurikan {

namespace Analyzing {

class IPerformanceWatch
{
public:

    /**
     * @brief creating new instance of the interface
     * @param units - the units to be used for the watch
     * @return shared_ptr to the interface
     */
    static std::shared_ptr<IPerformanceWatch> create(const Analyzing::Units &units);

    /**
     * @brief calculate the time since 1/1/1970 according to units
     * @param units - the units of the calculated time
     * @return the time since 1/1/1970
     */
    static uint128 timeSinceEpoch(const Analyzing::Units &units);

    /**
     * @brief starting the watch
     * @return this
     */
    virtual IPerformanceWatch &start() = 0;

    /**
     * @brief sample the cuurent time since watch start and save it
     * @return the current time since watch start
     */
    virtual uint128 lap() = 0;

    /**
     * @brief reseting the watch, clear all the laps
     * @return this
     */
    virtual IPerformanceWatch &reset() = 0;

    /**
     * @brief getting the number of saved laps
     * @return the number of saved laps
     */
    virtual uint128 getNumOfLaps() const = 0;

    /**
     * @brief getting the current units used for the watch
     * @return the units used for the watch
     */
    virtual Units getUnits() const  = 0;

    /**
     * @brief getting all the saved laps
     * @return vector off all times saved since start of watch
     */
    virtual std::vector<uint128> getTimeOfLaps() const = 0;

    /**
     * @brief getting the differnces between saved laps
     * @return vector of differences between all the saved laps - the length sould be num of laps - 1
     */
    virtual std::vector<uint128> getDiffBetweenLaps() const  = 0;

    /**
     * @brief check if time over since the watch started
     * @param time_to_check - the time to be cheked with the defined units
     * @return true if time over, otherwise return false
     */
    virtual bool isTimeOver(const uint128 & time_to_check) = 0;

    /**
     * @brief sample the time pass from the start
     * @return the sampled time pass from the start
     */
    virtual uint128 sample() const = 0;

    /**
      @brief default destructor
      */
    virtual ~IPerformanceWatch() = default;
};

} //namespace Analyzing

} //namespace Shurikan



#endif // IPERFORMANCEWATCH_H
