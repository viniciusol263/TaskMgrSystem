#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>

#include "AccountService/AccountService.h"

class TaskMgrSystem
{
public:
    TaskMgrSystem();
    ~TaskMgrSystem() = default;
    
private:
    AccountServicePtr m_accountService;
};