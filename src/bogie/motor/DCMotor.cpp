#include "DCMotor.hpp"

bogie::motor::DCMotor::DCMotor(
    uint8_t forward_pin,
    uint8_t backward_pin,
    uint8_t enable_pin) :
    forward_pin_(forward_pin),
    backward_pin_(backward_pin),
    enable_pin_(enable_pin),
    speed_(motor::kNoSpeed)
{
    pinMode(forward_pin_, OUTPUT);
    pinMode(backward_pin_, OUTPUT);
    pinMode(enable_pin_, OUTPUT);
}

bogie::motor::DCMotor::~DCMotor()
{
    SetSpeed(0);
}

int8_t bogie::motor::DCMotor::GetSpeed() const
{
    return speed_;
}

void bogie::motor::DCMotor::SetSpeed(int speed)
{
    if (speed > 0) {
        SetDirection(FORWARD);
    }
    else if (speed < 0) {
        SetDirection(BACKWARD);
    }
    else {
        SetDirection(STOP);
    }

    speed_ = constrain(speed, motor::kMinSpeed, motor::kMaxSpeed);

    uint8_t absolute_speed = abs(constrain(
        speed_,
        motor::kMinSpeed,
        motor::kMaxSpeed));

    uint8_t pwm_speed_ = map(
        absolute_speed,
        motor::kNoSpeed,
        motor::kMaxSpeed,
        kMinPWMSpeed,
        kMaxPWMSpeed);

    analogWrite(enable_pin_, pwm_speed_);
}

void bogie::motor::DCMotor::SetDirection(MotorDirection direction)
{
    switch (direction) {
        case FORWARD:
            digitalWrite(forward_pin_, HIGH);
            digitalWrite(backward_pin_, LOW);
            break;

        case BACKWARD:
            digitalWrite(forward_pin_, LOW);
            digitalWrite(backward_pin_, HIGH);
            break;

        case STOP:
            digitalWrite(forward_pin_, LOW);
            digitalWrite(backward_pin_, LOW);
            break;
    }
}
