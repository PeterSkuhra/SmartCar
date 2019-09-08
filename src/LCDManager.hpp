#ifndef LCD_MANAGER_HPP
#define LCD_MANAGER_HPP

#include <Arduino.h>

#include "IExecutable.hpp"

#include "../lib/LiquidCrystal/LiquidCrystal_I2C.h"


class LCDManager : public IExecutable
{
 public:

    static IExecutable* GetInstance();

    void Run() override;

 private:

    LCDManager();

    void Intro();

    void Show();

 private:
    LiquidCrystal_I2C lcd_;

    uint16_t refresh_time_;

    uint32_t current_time_;

    uint32_t previous_time_;

    uint16_t i_;
};

#endif
