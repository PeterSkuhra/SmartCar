#ifndef FIXED_BOGIE_DRIVER_HPP
#define FIXED_BOGIE_DRIVER_HPP

#include "IDriver.hpp"
#include "motor/IMotor.hpp"

namespace bogie
{

/******************************************************************************
 *  Singleton class represents a car driver that changes the direction
 *  of movement by changing the speed of one side of the wheels.
 *****************************************************************************/
class FixedBogieDriver : public IDriver
{
 public:
    /**
     *  Returns a single instance of FixedBogieDriver.
     *
     *  @return a single instance of FixedBogieDriver.
     */
    static IDriver* GetInstance();

    /**
     *  Destructor.
     */
    ~FixedBogieDriver();

    /**
     *  Returns the current angle of change
     *  the direction of movement of the car.
     *
     *  @return current angle.
     */
    int8_t GetAngle() override;

    /**
     *  Sets angle of change the direction
     *  of movement of the car.
     *
     *  @param specified angle to set from range [-90, 90].
     */
    void SetAngle(int angle) override;

    /**
     *  Returns current speed of the car.
     *
     *  @return current speed of the car.
     */
    int8_t GetSpeed() override;

    /**
     *  Sets speed of the movement of the car.
     *
     *  @param speed    specified speed to set from range [-100, 100].
     */
    void SetSpeed(int speed) override;

    /**
     *  Sets the speed of each side of the car.
     *
     *  @param left_speed       speed of the left side from range [-100, 100].
     *  @param right_speed      speed of the right side from range [-100, 100].
     */
    void SetSpeed(int left_speed, int right_speed) override;

    /**
     *  Synchronizes speed on both sides of the car.
     */
    void SyncSpeed() override;

 private:
    /**
     *  Private constructor.
     *  Constructs instance of FixedBogieDriver with specified numbers of pins.
     *
     *  @param motor ena    enable pin of motor A.
     *  @param motor_enb    enable pin of motor B.
     *  @param motor_in1    forward pin of motor A.
     *  @param motor_in2    backward pin of motor A.
     *  @param motor_in3    forward pin of motor B.
     *  @param motor_in4    backward pin of motor B.
     */
    FixedBogieDriver(uint8_t motor_ena,
                     uint8_t motor_enb,
                     uint8_t motor_in1,
                     uint8_t motor_in2,
                     uint8_t motor_in3,
                     uint8_t motor_in4);

 private:
    /**
     *  Instance of motors on left side.
     */
    motor::IMotor* left_motor_;

    /**
     *  Instance of motors on left side.
     */
    motor::IMotor* right_motor_;

    /**
     *  Current angle of change the direction of movement of the car.
     */
    int8_t angle_;

    /**
     *  Current speed of the car.
     */
    int8_t speed_;

};

}

#endif
