#pragma once
#include <memory>
#include <string>

#include "AccountHandler/AccountHandler.h"

class AccountService 
{
public:
    AccountService();
    ~AccountService() = default;

private:
    AccountHandlerPtr m_accountHandler;
};
using AccountServicePtr = std::shared_ptr<AccountService>;