#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "IExecutable.hpp"

class Application : public IExecutable
{
 public:
    static Application* GetInstance();

    void Run();

 private:
    Application();

};

#endif
