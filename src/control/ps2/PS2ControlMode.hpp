#ifndef PS2_CONTROL_MODE_HPP
#define PS2_CONTROL_MODE_HPP

#include "../IControlMode.hpp"

#include "../../bogie/IDriver.hpp"

namespace control
{
namespace ps2
{

class PS2ControlMode : public IControlMode
{
 public:

    static IControlMode* GetInstance();

    ~PS2ControlMode();

    void Control() override;

 private:

    PS2ControlMode();

    bogie::IDriver* bogie_driver_;
};

}
}

#endif
