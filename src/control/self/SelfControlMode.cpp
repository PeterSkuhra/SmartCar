#include "SelfControlMode.hpp"

#include "../../bogie/FixedBogieDriver.hpp"

control::IControlMode* control::self::SelfControlMode::GetInstance()
{
    static SelfControlMode instance;
    return &instance;
}

control::self::SelfControlMode::~SelfControlMode()
{
    delete bogie_driver_;
}

void control::self::SelfControlMode::Control()
{
    // TODO
}

control::self::SelfControlMode::SelfControlMode()
{
    bogie_driver_ = bogie::FixedBogieDriver::GetInstance();
    bogie_driver_->SetSpeed(0);
    bogie_driver_->SetAngle(0);
}
