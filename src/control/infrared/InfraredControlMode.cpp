#include "InfraredControlMode.hpp"

#include "RemoteButtonsValues.hpp"
#include "SpeedValue.hpp"

#include "../../bogie/FixedBogieDriver.hpp"

#define IR_RECEIVER_PIN     12  //  TODO!!!

control::IControlMode* control::infrared::InfraredControlMode::GetInstance()
{
    static InfraredControlMode instance;
    return &instance;
}

control::infrared::InfraredControlMode::~InfraredControlMode()
{
    ir_value_ = 0x0;
    ir_last_value_ = 0x0;
    speed_ = 0;
    move_state_ = STOP;
    ApplySpeed(move_state_);

    ir_results_.~decode_results();
    ir_receiver_.~IRrecv();
    delete bogie_driver_;
}

void control::infrared::InfraredControlMode::Control()
{
    UpdateIR();

    ProcessInput();

    ApplySpeed(move_state_);
}

control::infrared::InfraredControlMode::InfraredControlMode() :
    ir_receiver_(IR_RECEIVER_PIN),
    ir_value_(0x0),
    speed_(SPEED_1)
{
    ir_receiver_.enableIRIn();
    bogie_driver_ = bogie::FixedBogieDriver::GetInstance();
    bogie_driver_->SetSpeed(0);
    bogie_driver_->SetAngle(0);
}

void control::infrared::InfraredControlMode::UpdateIR()
{
    if (ir_receiver_.decode(&ir_results_)) {
        ir_last_value_ = ir_value_;
        ir_value_ = ir_results_.value;
        ir_receiver_.resume();
    }
}

void control::infrared::InfraredControlMode::ProcessInput()
{
    switch (ir_value_) {
        case OK:
            move_state_ = STOP;
            break;

        case UP:
            move_state_ = FORWARD;
            break;

        case DOWN:
            move_state_ = BACKWARD;
            break;

        case LEFT:
            move_state_ = CCW;
            break;

        case RIGHT:
            move_state_ = CW;
            break;

        case NUM_0:
            speed_ = SPEED_0;
            break;

        case NUM_1:
            speed_ = SPEED_1;
            break;

        case NUM_2:
            speed_ = SPEED_2;
            break;

        case NUM_3:
            speed_ = SPEED_3;
            break;
    }
}

void control::infrared::InfraredControlMode::ApplySpeed(MoveState move_state)
{
    switch (move_state) {
        case STOP:
            bogie_driver_->SetSpeed(0);
            break;

        case FORWARD:
            bogie_driver_->SetSpeed(speed_);
            break;

        case BACKWARD:
            bogie_driver_->SetSpeed(speed_ * (-1));
            break;

        case CCW:
            bogie_driver_->SetSpeed(90 * (-1), 90);
            break;

        case CW:
            bogie_driver_->SetSpeed(90, 90 * (-1));
            break;
    }
}
