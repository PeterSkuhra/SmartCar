#ifndef CONTROL_MODE_FACTORY_HPP
#define CONTROL_MODE_FACTORY_HPP

#include "IControlMode.hpp"
#include "ControlModeType.hpp"

namespace control
{

class ControlModeFactory
{
 public:
    static IControlMode* GetControlMode(ControlModeType control_mode_type);

 private:
    ControlModeFactory();

 private:
    static IControlMode* control_mode_;

};

}

#endif
