#include <Arduino.h>

#include "FixedBogieDriver.hpp"

#include "motor/DCMotor.hpp"

#define MotorENA        5  // PWM (Right motors)
#define MotorENB        6  // PWM (Left motors)
#define MotorIN1        7  // forward A
#define MotorIN2        8  // backward A
#define MotorIN3        9  // forward B
#define MotorIN4        10 // backward B
//  TODO:   control pins and functions !!!


bogie::IDriver* bogie::FixedBogieDriver::GetInstance()
{
    static FixedBogieDriver driver_instance(MotorENA,
                                            MotorENB,
                                            MotorIN1,
                                            MotorIN2,
                                            MotorIN3,
                                            MotorIN4);
    return &driver_instance;
}

bogie::FixedBogieDriver::~FixedBogieDriver()
{
    SetAngle(0);
    SetSpeed(0, 0);

    delete left_motor_;
    delete right_motor_;
}

int8_t bogie::FixedBogieDriver::GetAngle()
{
    return angle_;
}

void bogie::FixedBogieDriver::SetAngle(int angle)
{
    angle_ = constrain(angle, kMinAngle, kMaxAngle);

    float angle_ratio =
        (kMaxAngle - abs(angle_)) / static_cast<float>(kMaxAngle);

    if (angle_ > kNoAngle) {
        left_motor_->SetSpeed(speed_);
        right_motor_->SetSpeed(static_cast<int8_t>(speed_ * angle_ratio));
    }
    else if (angle_ < kNoAngle) {
        left_motor_->SetSpeed(static_cast<int8_t>(speed_ * angle_ratio));
        right_motor_->SetSpeed(speed_);
    }
    else {
        left_motor_->SetSpeed(speed_);
        right_motor_->SetSpeed(speed_);
    }
}

int8_t bogie::FixedBogieDriver::GetSpeed()
{
    return speed_;
}

void bogie::FixedBogieDriver::SetSpeed(int speed)
{
    speed_ = speed;
    SetAngle(angle_);
}

void bogie::FixedBogieDriver::SetSpeed(int left_speed, int right_speed)
{
    int8_t left_motor_speed = constrain(left_speed,
                                        motor::kMinSpeed,
                                        motor::kMaxSpeed);
    int8_t right_motor_speed = constrain(right_speed,
                                         motor::kMinSpeed,
                                         motor::kMaxSpeed);

    speed_ = (right_motor_speed + left_motor_speed) / 2;

    left_motor_->SetSpeed(left_motor_speed);
    right_motor_->SetSpeed(right_motor_speed);
}

void bogie::FixedBogieDriver::SyncSpeed()
{
    SetSpeed(speed_, speed_);
}

bogie::FixedBogieDriver::FixedBogieDriver(uint8_t motor_ena,
                                          uint8_t motor_enb,
                                          uint8_t motor_in1,
                                          uint8_t motor_in2,
                                          uint8_t motor_in3,
                                          uint8_t motor_in4)
{
    speed_ = motor::kNoSpeed;
    angle_ = kNoAngle;

    right_motor_ = new motor::DCMotor(motor_in1, motor_in2, motor_ena);
    left_motor_ = new motor::DCMotor(motor_in3, motor_in4, motor_enb);
}
