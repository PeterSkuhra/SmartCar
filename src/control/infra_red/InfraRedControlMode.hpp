#ifndef INFRA_RED_CONTROL_MODE_HPP
#define INFRA_RED_CONTROL_MODE_HPP

#include <Arduino.h>

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

 private:

    IRrecv ir_receiver_;

    decode_results ir_results_;

    uint32_t ir_value_;
    uint32_t ir_last_value_;

    bogie::IDriver* bogie_driver_;

    int8_t speed_;
};

}
}

#endif
