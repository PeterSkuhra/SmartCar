#ifndef SELF_CONTROL_MODE_HPP
#define SELF_CONTROL_MODE_HPP

#include "../IControlMode.hpp"

#include "../../bogie/IDriver.hpp"

namespace control
{
namespace self
{

class SelfControlMode : public IControlMode
{
 public:

    static IControlMode* GetInstance();

    ~SelfControlMode();

    void Control() override;

 private:

    SelfControlMode();

    bogie::IDriver* bogie_driver_;
};

}
}

#endif
