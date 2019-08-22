#include "Application.hpp"

#include "IExecutable.hpp"

IExecutable* Application::GetInstance()
{
    static Application instance;
    return &instance;
}

void Application::Run()
{
    Once();

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
}
