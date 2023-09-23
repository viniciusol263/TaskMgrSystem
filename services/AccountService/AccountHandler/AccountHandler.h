#pragma once
#include <memory>
#include <filesystem>

#include "ErrorHandling/ErrorHandling.h"
#include "CommonCxx/StatusCode.h"

class AccountHandler
{
public:
    AccountHandler();
    ~AccountHandler() = default;

    AccountHandlerStatusCode CreateAccount(std::string username, std::string password);
    AccountHandlerStatusCode DeleteAccount(std::string username);
};
using AccountHandlerPtr = std::shared_ptr<AccountHandler>;
