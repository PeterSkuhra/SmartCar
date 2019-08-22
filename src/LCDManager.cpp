#include "LCDManager.hpp"

IExecutable* LCDManager::GetInstance()
{
    static LCDManager instance;
    return &instance;
}

void LCDManager::Run()
{
    
}
