#ifndef LINE_CONTROL_MODE_HPP
#define LINE_CONTROL_MODE_HPP

#include "../IControlMode.hpp"

#include "../../bogie/IDriver.hpp"

namespace control
{
namespace line
{

class LineControlMode : public IControlMode
{
 public:

    static IControlMode* GetInstance();

    ~LineControlMode();

    void Control() override;

 private:

    LineControlMode();

    bogie::IDriver* bogie_driver_;
};

}
}

#endif
