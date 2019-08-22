#ifndef UNIT_TEST

#include <Arduino.h>
#include "Application.hpp"

IExecutable* app;

void setup()
{
    app = Application::GetInstance();
}

void loop()
{
    app->Run();
}

#endif
