#pragma once
#include <memory>
#include <string>
#include <iostream>
#include <tuple>

#include "AccountHandler/AccountHandler.h"
#include "AccountMonitor/AccountMonitor.h"
#include "AccountAuthentication/AccountAuthentication.h"
#include "CommonCxx/SqliteTables.h"

const std::string accountDataBase = "account.db";

class AccountService 
{
public:
    AccountService();
    
private:
    AccountHandlerPtr m_accountHandler;
    AccountMonitorPtr m_accountMonitor;
    AccountAuthenticationPtr m_accountAuthentication;
};
using AccountServicePtr = std::shared_ptr<AccountService>;