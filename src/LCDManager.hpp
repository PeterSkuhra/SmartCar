#ifndef LCD_MANAGER_HPP
#define LCD_MANAGER_HPP

#include "IExecutable.hpp"

class LCDManager : public IExecutable
{
 public:
    static LCDManager* GetInstance();

    void Run();

 private:

};

#endif
