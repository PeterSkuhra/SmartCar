#include "ControlModeFactory.hpp"

#include "ps2/PS2ControlMode.hpp"
#include "infrared/InfraredControlMode.hpp"
#include "bluetooth/BluetoothControlMode.hpp"
#include "line/LineControlMode.hpp"
#include "self/SelfControlMode.hpp"

control::IControlMode* control::ControlModeFactory::GetControlMode(
    ControlModeType control_mode_type)
{
    delete control_mode_;

    switch (control_mode_type) {
        case PS2:
            control_mode_ = ps2::PS2ControlMode::GetInstance();
            break;

        case INFRA_RED:
            control_mode_ = infrared::InfraredControlMode::GetInstance();
            break;

        case BLUETOOTH:
            control_mode_ = bluetooth::BluetoothControlMode::GetInstance();
            break;

        case LINE:
            control_mode_ = line::LineControlMode::GetInstance();
            break;

        case SELF:
            control_mode_ = self::SelfControlMode::GetInstance();
            break;

        default:
            return nullptr;
    }

    return control_mode_;
}

control::ControlModeFactory::ControlModeFactory()
{

}
