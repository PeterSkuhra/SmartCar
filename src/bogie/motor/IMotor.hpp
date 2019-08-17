#ifndef IMOTOR_HPP
#define IMOTOR_HPP

#include <Arduino.h>

#include "MotorDirection.hpp"

namespace bogie
{
namespace motor
{
const int8_t kMinSpeed = -100;

const int8_t kNoSpeed = 0;

const int8_t kMaxSpeed = 100;

/******************************************************************************
 *  Interface that represents any motor.
 *  You can control speed and direction of its rotation.
******************************************************************************/
class IMotor
{
 public:
    virtual ~IMotor() = default;

    /**
     *  Returns current speed of motor.
     *
     *  @return current speed of motor.
     */
    virtual int8_t GetSpeed() const = 0;

    /**
     *  Sets current speed of motor.
     *
     *  @param speed    current speed of motor in range [-100, 100].
     *                  Positive value makes motor spin forward.
     *                  Negative value makes motor spin backward.
     */
    virtual void SetSpeed(int8_t speed) = 0;

 protected:
    /**
     *  Sets direction of motor.
     *
     *  @param direction    enumerated type of direction of motor.
     */
    virtual void SetDirection(MotorDirection direction) = 0;
};

}
}

#endif
