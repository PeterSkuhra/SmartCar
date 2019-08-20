#ifndef UNIT_TEST

#include <Arduino.h>
#include "Application.hpp"

Application* app;

void setup()
{
    app = Application::GetInstance();
    app->Once();
}

void loop()
{
    app->Run();
}

#endif
