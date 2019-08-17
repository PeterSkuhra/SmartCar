#ifndef IDRIVER_HPP
#define IDRIVER_HPP

#include <Arduino.h>

namespace bogie
{
const int8_t kMinAngle = -90;

const int8_t kNoAngle = 0;

const int8_t kMaxAngle = 90;

/******************************************************************************
 *  Interface
 *****************************************************************************/
class IDriver
{
 public:
    virtual ~IDriver() = default;

    virtual int8_t GetAngle() = 0;

    virtual void SetAngle(int8_t angle) = 0;

    virtual int8_t GetSpeed() = 0;

    virtual void SetSpeed(int8_t speed) = 0;

    virtual void SetSpeed(int8_t left_speed, int8_t right_speed) = 0;

    virtual void SyncSpeed() = 0;
};

}

#endif
