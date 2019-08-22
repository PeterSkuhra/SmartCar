#include "PS2ControlMode.hpp"

#include "../../bogie/FixedBogieDriver.hpp"

control::IControlMode* control::ps2::PS2ControlMode::GetInstance()
{
    static PS2ControlMode instance;
    return &instance;
}

control::ps2::PS2ControlMode::~PS2ControlMode()
{
    delete bogie_driver_;
}

void control::ps2::PS2ControlMode::Control()
{
    // TODO
}

control::ps2::PS2ControlMode::PS2ControlMode()
{
    bogie_driver_ = bogie::FixedBogieDriver::GetInstance();
    bogie_driver_->SetSpeed(0);
    bogie_driver_->SetAngle(0);
}
