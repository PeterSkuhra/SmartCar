#if defined(ARDUINO) && defined(UNIT_TEST)

#include <Arduino.h>
#include "unity.h"

#include "../../src/bogie/motor/DCMotor.hpp"

#define MotorENA        5  // PWM (Right motors)
#define MotorENB        6  // PWM (Left motors)
#define MotorIN1        7  // forward A
#define MotorIN2        8  // backward A
#define MotorIN3        9  // forward B
#define MotorIN4        10 // backward B

bogie::motor::DCMotor right_motor(MotorIN1, MotorIN2, MotorENA);
bogie::motor::DCMotor left_motor(MotorIN3, MotorIN4, MotorENB);

void stop_motors()
{
    right_motor.SetSpeed(0);
    left_motor.SetSpeed(0);
}

void speed_test()
{
    stop_motors();

    for (int i = INT_MIN; i < INT_MAX; ++i) {
        right_motor.SetSpeed(i);
        left_motor.SetSpeed(i);
        delay(1);

        if (i == 0)
            delay(1000);

        if (i < -100) {
            TEST_ASSERT_EQUAL_INT(-100, right_motor.GetSpeed());
            TEST_ASSERT_EQUAL_INT(-100, left_motor.GetSpeed());
        }
        else if (i > 100) {
            TEST_ASSERT_EQUAL_INT(100, right_motor.GetSpeed());
            TEST_ASSERT_EQUAL_INT(100, left_motor.GetSpeed());
        }
        else {
            TEST_ASSERT_EQUAL_INT(i, right_motor.GetSpeed());
            TEST_ASSERT_EQUAL_INT(i, left_motor.GetSpeed());
        }
    }

    stop_motors();
}

void speed_raise()
{
    stop_motors();

    for (int i = 0; i <= 100; ++i) {
        right_motor.SetSpeed(i);
        left_motor.SetSpeed(i);
        TEST_ASSERT_EQUAL_INT(i, right_motor.GetSpeed());
        TEST_ASSERT_EQUAL_INT(i, left_motor.GetSpeed());

        if (i < 30) {
            delay(20);
        }
        else {
            delay(100);
        }
    }

    delay(5000);
    stop_motors();
    TEST_ASSERT_EQUAL_INT(0, right_motor.GetSpeed());
    TEST_ASSERT_EQUAL_INT(0, left_motor.GetSpeed());
}

void setup()
{
    delay(2000);

    UNITY_BEGIN();

    RUN_TEST(speed_test);
    delay(1000);
    RUN_TEST(speed_raise);

    UNITY_END();
}

void loop()
{

}

#endif
