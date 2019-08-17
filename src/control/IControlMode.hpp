#ifndef ICONTROL_MODE_HPP
#define ICONTROL_MODE_HPP

namespace control
{

class IControlMode
{
 public:

    ~IControlMode() = default;

    virtual void Control() = 0;
};

}

#endif
