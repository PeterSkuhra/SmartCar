#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "IExecutable.hpp"
#include "LCDManager.hpp"
#include "control/IControlMode.hpp"

class Application : public IExecutable
{
 public:
    static IExecutable* GetInstance();

    void Run() override;

 private:
    Application();

    void Once();

 private:
    bool once_launched_;

    LCDManager* lcd_manager_;

    control::IControlMode* control_mode_;
};

#endif
