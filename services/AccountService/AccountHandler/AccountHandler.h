#pragma once
#include <memory>
#include <filesystem>

#include "ErrorHandling/ErrorHandling.h"
#include "CommonCxx/StatusCode.h"
#include "CommonCxx/Consts.h"
#include "CommonCxx/SqliteTables.h"

class AccountHandler
{
public:
    AccountHandler(const Common::AccountStorage& storage);
    ~AccountHandler() = default;

    Common::AccountHandlerStatusCode CreateAccount(std::string username, std::string password);
    Common::AccountHandlerStatusCode DeleteAccount(std::string username);
    

private:
    Common::AccountStorage m_storage;
};
using AccountHandlerPtr = std::shared_ptr<AccountHandler>;

