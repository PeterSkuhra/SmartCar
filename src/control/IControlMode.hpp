#ifndef ICONTROL_MODE_HPP
#define ICONTROL_MODE_HPP

namespace control
{

/******************************************************************************
 *  Interface that represents any control mode.
 *  Controls the movement of the car.
******************************************************************************/
class IControlMode
{
 public:
    /**
     *  Destructor.
     */
    ~IControlMode() = default;

    /**
     *  Controls car with the current control mode.
     */
    virtual void Control() = 0;
};

}

#endif
