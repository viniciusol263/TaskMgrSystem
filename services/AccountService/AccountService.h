#pragma once
#include <memory>
#include <string>
#include <iostream>

#include "AccountHandler/AccountHandler.h"
#include "AccountMonitor/AccountMonitor.h"

class AccountService 
{
public:
    AccountService();
    
private:
    AccountHandlerPtr m_accountHandler;
    AccountMonitorPtr m_accountMonitor;
};
using AccountServicePtr = std::shared_ptr<AccountService>;