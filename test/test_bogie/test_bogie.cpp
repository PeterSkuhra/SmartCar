#if defined(ARDUINO) && defined(UNIT_TEST)

#include <Arduino.h>
#include "unity.h"

#include "../../src/bogie/IDriver.hpp"
#include "../../src/bogie/FixedBogieDriver.hpp"

bogie::IDriver* bogie_driver = bogie::FixedBogieDriver::GetInstance();

void stop()
{
    bogie_driver->SetSpeed(0, 0);
}

void speed_test()
{

}

void angle_test()
{

}

void sync_speed_test()
{

}

void setup()
{
    delay(2000);

    UNITY_BEGIN();

    RUN_TEST(speed_test);
    delay(1000);

    RUN_TEST(angle_test);
    delay(1000);

    RUN_TEST(sync_speed_test);

    UNITY_END();
}

void loop()
{

}

#endif
