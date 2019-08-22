#ifndef MOVE_STATE_HPP
#define MOVE_STATE_HPP

namespace control
{
namespace infrared
{

/******************************************************************************
 *  Enumerated type of car move state.
 *****************************************************************************/
enum MoveState
{
    STOP,
    FORWARD,
    BACKWARD,
    CCW,
    CW
};

}
}

#endif
