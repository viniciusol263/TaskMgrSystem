#pragma once
#include <memory>
#include <filesystem>

#include "ErrorHandling/ErrorHandling.h"
#include "CommonCxx/StatusCode.h"

const std::filesystem::path accountPath = std::filesystem::current_path().parent_path() / "objects/accounts";
const std::string accountFileSuffix = "_account.json";

class AccountHandler
{
public:
    AccountHandler();
    ~AccountHandler() = default;

    Common::AccountHandlerStatusCode CreateAccount(std::string username, std::string password);
    Common::AccountHandlerStatusCode DeleteAccount(std::string username);
};
using AccountHandlerPtr = std::shared_ptr<AccountHandler>;
