#ifndef INFRA_RED_CONTROL_MODE_HPP
#define INFRA_RED_CONTROL_MODE_HPP

#include <Arduino.h>

#include "MoveState.hpp"
#include "../IControlMode.hpp"

#include "../../bogie/IDriver.hpp"
#include "../../lib/IRremote/IRremote.h"

namespace control
{
namespace infra_red
{

/******************************************************************************
 *  Class for control SmartCar via infrared transceiver.
 *****************************************************************************/
class InfraRedControlMode : public IControlMode
{
 public:
    /**
     *  Constructor.
     */
    InfraRedControlMode();

    /**
     *  Destructor.
     */
    ~InfraRedControlMode();

    /**
     *  Controls car via InfraRed remote.
     */
    void Control() override;

 private:
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
    control::infra_red::MoveState move_state_;
};

}
}

#endif
