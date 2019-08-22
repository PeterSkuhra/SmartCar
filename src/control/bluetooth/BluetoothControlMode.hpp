#ifndef BLUETOOTH_CONTROL_MODE_HPP
#define BLUETOOTH_CONTROL_MODE_HPP

#include <Arduino.h>

#include "../IControlMode.hpp"

#include "../../bogie/IDriver.hpp"

namespace control
{
namespace bluetooth
{

/******************************************************************************
 *  Class for control SmartCar via bluetooth modul and phone application.
 *****************************************************************************/
class BluetoothControlMode : public IControlMode
{
 public:
    /**
    *  Returns a single instance of BluetoothControlMode.
    *
    *  @return a single instance of BluetoothControlMode.
    */
    static IControlMode* GetInstance();

    /**
     *  Destructor.
     */
    ~BluetoothControlMode();

    /**
     *  Controls car via bluetooth modul and phone application.
     */
    void Control() override;

 private:
    /**
    *  Private constructor.
    */
    BluetoothControlMode();

    /**
    *  Instance of driver for bogie.
    */
    bogie::IDriver* bogie_driver_;
};

}
}

#endif
