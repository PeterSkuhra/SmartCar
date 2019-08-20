#ifndef FIXED_BOGIE_DRIVER_HPP
#define FIXED_BOGIE_DRIVER_HPP

#include "IDriver.hpp"
#include "motor/IMotor.hpp"

namespace bogie
{

class FixedBogieDriver : public IDriver
{
 public:
    static IDriver* GetInstance();

    int8_t GetAngle() override;

    void SetAngle(int angle) override;

    int8_t GetSpeed() override;

    void SetSpeed(int speed) override;

    void SetSpeed(int left_speed, int right_speed) override;

    void SyncSpeed() override;

 private:
    FixedBogieDriver(uint8_t motor_ena,
                     uint8_t motor_enb,
                     uint8_t motor_in1,
                     uint8_t motor_in2,
                     uint8_t motor_in3,
                     uint8_t motor_in4);

 private:
    motor::IMotor* left_motor_;
    motor::IMotor* right_motor_;

    int8_t angle_;
    int8_t speed_;

};

}

#endif
