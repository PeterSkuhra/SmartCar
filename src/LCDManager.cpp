#include "LCDManager.hpp"

IExecutable* LCDManager::GetInstance()
{
    static LCDManager instance;
    return &instance;
}

void LCDManager::Run()
{
    current_time_ = millis();

    if ((current_time_ - previous_time_) >= refresh_time_) {
        previous_time_ = current_time_;

        // CODE to refresh every 1000 ms
        Show();
    }
}

LCDManager::LCDManager() :
    lcd_(0x27, 16, 2),
    refresh_time_(1000),
    current_time_(0),
    previous_time_(0),
    i_(0)
{
    Intro();
}

void LCDManager::Intro()
{
    lcd_.begin();

    lcd_.setCursor(4, 0);
    lcd_.print("SmartCar");

    lcd_.setCursor(2, 1);
    lcd_.print("Peter Skuhra");

    delay(1000);
    lcd_.clear();
}

void LCDManager::Show()
{
    lcd_.clear();
    lcd_.print(i_++);
}
