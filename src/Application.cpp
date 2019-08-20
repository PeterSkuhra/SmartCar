#include "Application.hpp"

Application* Application::GetInstance()
{
    static Application instance;
    return &instance;
}

void Application::Run()
{

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

}
