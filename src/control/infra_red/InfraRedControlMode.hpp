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

class InfraRedControlMode : public IControlMode
{
 public:

    /**
     *  Constructor.
     */
    InfraRedControlMode();

    /**
     *  Controls car via InfraRed remote.
     */
    void Control() override;

 private:

    /**
     *  Updates received value.
     */
    void UpdateIR();

    void ApplySpeed(MoveState move_state);

 private:

    IRrecv ir_receiver_;

    decode_results ir_results_;

    uint32_t ir_value_;
    uint32_t ir_last_value_;

    int8_t speed_;

    bogie::IDriver* bogie_driver_;

    control::infra_red::MoveState move_state_;
};

}
}

#endif
