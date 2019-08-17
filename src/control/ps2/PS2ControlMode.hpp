#ifndef PS2_CONTROL_MODE_HPP
#define PS2_CONTROL_MODE_HPP

#include "../IControlMode.hpp"

namespace control
{
namespace ps2
{

class PS2ControlMode : public IControlMode
{
 public:

    void Control() override;

};

}
}

#endif
