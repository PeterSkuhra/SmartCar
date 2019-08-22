#ifndef INFRARED_CONTROL_MODE_HPP
#define INFRARED_CONTROL_MODE_HPP

#include <Arduino.h>

#include "MoveState.hpp"
#include "../IControlMode.hpp"

#include "../../bogie/IDriver.hpp"
#include "../../lib/IRremote/IRremote.h"

namespace control
{
namespace infrared
{

/******************************************************************************
 *  Class for control SmartCar via infrared transceiver.
 *****************************************************************************/
class InfraredControlMode : public IControlMode
{
 public:
    /**
     *  Returns a single instance of InfraredControlMode.
     *
     *  @return a single instance of InfraredControlMode.
     */
    static IControlMode* GetInstance();

    /**
     *  Destructor.
     */
    ~InfraredControlMode();

    /**
     *  Controls car via infrared remote.
     */
    void Control() override;

 private:
    /**
    *  Private constructor.
    */
    InfraredControlMode();

    /**
     *  Updates received value.
     */
    void UpdateIR();

    /**
     *  Process input from IR to driver.
     */
    void ProcessInput();

    /**
     *  Applying specified speeds.
     */
    void ApplySpeed(MoveState move_state);

 private:
    /**
     *  InfraRed receiver instance.
     */
    IRrecv ir_receiver_;

    /**
     *  Results returned from the decoder.
     */
    decode_results ir_results_;

    /**
     *  Decoded current value from IR.
     */
    uint32_t ir_value_;

    /**
     *  Decoded previous value from IR.
     */
    uint32_t ir_last_value_;

    /**
     *  Current set speed.
     */
    int8_t speed_;

    /**
     *  Instance of driver for bogie.
     */
    bogie::IDriver* bogie_driver_;

    /**
     *  Current move state of car.
     */
    control::infrared::MoveState move_state_;
};

}
}

#endif
