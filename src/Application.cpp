#include "Application.hpp"

#include "IExecutable.hpp"

#include "control/ControlModeFactory.hpp"
#include "control/ControlModeType.hpp"
#include "control/infrared/InfraredControlMode.hpp"

IExecutable* Application::GetInstance()
{
    static Application instance;
    return &instance;
}

void Application::Run()
{
    Once();

    control_mode_->Control();

    lcd_manager_->Run();
}

void Application::Once()
{
    if (!once_launched_) {
        once_launched_ = true;

        // CODE...
    }
}

Application::Application() :
    once_launched_(false)
{
    lcd_manager_ = LCDManager::GetInstance();

    control_mode_ = control::ControlModeFactory::GetInstance()->GetControlMode(
        control::INFRARED);     // TODO: Switcher
}
