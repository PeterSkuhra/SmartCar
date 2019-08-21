#ifndef REMOTE_BUTTONS_VALUES_HPP
#define REMOTE_BUTTONS_VALUES_HPP

namespace control
{
namespace infra_red
{

/******************************************************************************
 *  Enumerated type of buttons values on infrared remote controller.
 *****************************************************************************/
enum IRButtonsValues
{
    OK = 0xFF02FD,
    UP = 0xFF629D,
    DOWN = 0xFFA857,
    LEFT = 0xFF22DD,
    RIGHT = 0xFFC23D,

    NUM_0 = 0xFF4AB5,
    NUM_1 = 0xFF6897,
    NUM_2 = 0xFF9867,
    NUM_3 = 0xFFB04F,
    NUM_4 = 0xFF30CF,
    NUM_5 = 0xFF18E7,
    NUM_6 = 0xFF7A85,
    NUM_7 = 0xFF10EF,
    NUM_8 = 0xFF38C7,
    NUM_9 = 0xFF5AA5,

    STAR = 0xFF42BD,
    HASH = 0xFF52AD,
};

}
}

#endif
