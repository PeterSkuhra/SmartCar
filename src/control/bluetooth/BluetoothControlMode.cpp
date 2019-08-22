#include "BluetoothControlMode.hpp"

#include "../../bogie/FixedBogieDriver.hpp"

control::IControlMode* control::bluetooth::BluetoothControlMode::GetInstance()
{
    static BluetoothControlMode instance;
    return &instance;
}

control::bluetooth::BluetoothControlMode::~BluetoothControlMode()
{
    delete bogie_driver_;
}

void control::bluetooth::BluetoothControlMode::Control()
{
    // TODO
}

control::bluetooth::BluetoothControlMode::BluetoothControlMode()
{
    bogie_driver_ = bogie::FixedBogieDriver::GetInstance();
    bogie_driver_->SetSpeed(0);
    bogie_driver_->SetAngle(0);
}
