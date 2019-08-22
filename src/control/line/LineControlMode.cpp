#include "LineControlMode.hpp"

#include "../../bogie/FixedBogieDriver.hpp"

control::IControlMode* control::line::LineControlMode::GetInstance()
{
    static LineControlMode instance;
    return &instance;
}

control::line::LineControlMode::~LineControlMode()
{
    delete bogie_driver_;
}

void control::line::LineControlMode::Control()
{
    // TODO
}

control::line::LineControlMode::LineControlMode()
{
    bogie_driver_ = bogie::FixedBogieDriver::GetInstance();
    bogie_driver_->SetSpeed(0);
    bogie_driver_->SetAngle(0);
}
