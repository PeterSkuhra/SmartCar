#include "InfraRedControlMode.hpp"

#include "RemoteButtonsValues.hpp"
#include "SpeedValue.hpp"

#include "../../bogie/FixedBogieDriver.hpp"

#define IR_RECEIVER_PIN     12  //  TODO!!!

control::infra_red::InfraRedControlMode::InfraRedControlMode() :
    ir_receiver_(IR_RECEIVER_PIN),
    ir_value_(0x0),
    speed_(SPEED_1)
{
    ir_receiver_.enableIRIn();
    bogie_driver_ = bogie::FixedBogieDriver::GetInstance();
}

void control::infra_red::InfraRedControlMode::Control()
{
    UpdateIR();

    switch (ir_value_) {
        case FORWARD:
            bogie_driver_->SetSpeed(speed_);
            break;

        case BACKWARD:
            bogie_driver_->SetSpeed(speed_ * (-1));
            break;

        case LEFT:
            bogie_driver_->SetSpeed(speed_ * (-1), speed_);
            break;

        case RIGHT:
            bogie_driver_->SetSpeed(speed_, speed_ * (-1));
            break;

        case OK:
            bogie_driver_->SetSpeed(0);
            break;

        case NUM_1:
            speed_ = SPEED_1;   //  TODO: update speed to driver!
                                // apply speed to last moving command!
            break;

        case NUM_2:
            speed_ = SPEED_2;
            break;

        case NUM_3:
            speed_ = SPEED_3;
            break;

        case NUM_4:
            speed_ = SPEED_4;
            break;
    }
}

void control::infra_red::InfraRedControlMode::UpdateIR()
{
    if (ir_receiver_.decode(&ir_results_)) {
        ir_last_value_ = ir_value_;
        ir_value_ = ir_results_.value;
        ir_receiver_.resume();
    }
}
