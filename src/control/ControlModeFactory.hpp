#ifndef CONTROL_MODE_FACTORY_HPP
#define CONTROL_MODE_FACTORY_HPP

#include "IControlMode.hpp"
#include "ControlModeType.hpp"

namespace control
{

/******************************************************************************
 *  Class for organize control modes.
 *****************************************************************************/
class ControlModeFactory
{
 public:
    /**
     *  Static method.
     *  Returns specified control mode by ControlModeType.
     *
     *  @param control_mode_type    specified control mode type.
     *
     *  @return chosen control mode.
     */
    static IControlMode* GetControlMode(ControlModeType control_mode_type);

 private:
    /**
     *  Private constructor.
     */
    ControlModeFactory();

 private:
    /**
     *  Current control mode.
     */
    static IControlMode* control_mode_;

};

}

#endif
