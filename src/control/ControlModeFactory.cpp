#include "ControlModeFactory.hpp"

#include "ps2/PS2ControlMode.hpp"
#include "infra_red/InfraRedControlMode.hpp"

control::IControlMode* control::ControlModeFactory::GetControlMode(
    ControlModeType control_mode_type)
{
    delete control_mode_;
    control_mode_ = nullptr;

    switch (control_mode_type) {
        case PS2:
            control_mode_ = new ps2::PS2ControlMode();
            break;

        case INFRA_RED:
            control_mode_ = new infra_red::InfraRedControlMode();
            break;

        case BLUETOOTH:
            break;

        case LINE:
            break;

        case SELF:
            break;

        default:
            return nullptr;
    }

    return control_mode_;
}

control::ControlModeFactory::ControlModeFactory()
{

}
