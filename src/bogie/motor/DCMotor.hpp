#ifndef DC_MOTOR_HPP
#define DC_MOTOR_HPP

#include <Arduino.h>
#include "IMotor.hpp"

namespace bogie
{
namespace motor
{

/******************************************************************************
 *  A class representing a DC motor that can be controlled by three wires
 *  through an L298N expansion board.
 *****************************************************************************/
class DCMotor : public IMotor
{
 public:
    /**
     *  Constructor.
     *
     *  @param forward_pin  The direction pin.
     *                      When set to HIGH makes the motor spin forward.
     *
     *  @param backward_pin The direction pin.
     *                      When set to HIGH makes the motor spin backward.
     *
     *  @param enable_pin   The speed pin. Controls motors speed.
     *
     *  Example:
     *      DCMotor dc_motor(IN1, IN2, ENA);
     */
    DCMotor(uint8_t forward_pin, uint8_t backward_pin, uint8_t enable_pin);

    /**
     *  Destructor.
     */
    ~DCMotor();

    /**
     *  Returns current speed of motor.
     *
     *  @return current speed of motor.
     */
    int8_t GetSpeed() const override;

    /**
     *  Sets current speed of motor.
     *
     *  @param speed    current speed of motor in range [-100, 100].
     *                  Positive value makes motor spin forward.
     *                  Negative value makes motor spin backward.
     */
    void SetSpeed(int speed) override;

 private:
    /**
     *  Sets direction of motor.
     *
     *  @param direction    enumerated type of direction of motor.
     */
    void SetDirection(MotorDirection direction) override;

 private:
    /**
     *  Minimum value of PWM (Pulse width modulation) signal for enable pin.
     */
    const uint8_t kMinPWMSpeed = 0;

    /**
     *  Maximum value of PWM (Pulse width modulation) signal for enable pin.
     */
    const uint8_t kMaxPWMSpeed = 255;

    /**
     *  The direction pin. When set to HIGH makes the motor spin forward.
     */
    uint8_t forward_pin_;

    /**
     *  The direction pin. When set to HIGH makes the motor spin backward.
     */
    uint8_t backward_pin_;

    /**
     *  The direction pin. When set to HIGH makes the motor spin forward.
     */
    uint8_t enable_pin_;

    /**
     *  The speed.
     */
    int8_t speed_;

    /**
     *  The PWM speed.
     */
    int8_t pwm_speed_;
};

}
}

#endif
