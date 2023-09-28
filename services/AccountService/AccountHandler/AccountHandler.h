#pragma once
#include <memory>
#include <filesystem>

#include "ErrorHandling/ErrorHandling.h"
#include "CommonCxx/StatusCode.h"
#include "CommonCxx/Consts.h"
#include "CommonCxx/SqliteTables.h"

#include "AccountAuthentication/AccountAuthentication.h"

class AccountHandler
{
public:
    AccountHandler(const Common::AccountStorage& storage, AccountAuthenticationPtr accountAuth);
    ~AccountHandler() = default;

    AccountAuthenticationPtr GetAccountAuth();
    Common::AccountHandlerStatusCode CreateAccount(std::string username, std::string password);
    Common::AccountHandlerStatusCode DeleteAccount(std::string username);
    

private:
    Common::AccountStorage m_storage;
    AccountAuthenticationPtr m_accountAuth;
};
using AccountHandlerPtr = std::shared_ptr<AccountHandler>;

