#pragma once

#include <memory>
#include <string>

#include "CommonCxx/StatusCode.h"
#include "CommonCxx/SqliteTables.h"

class AccountAuthentication
{
public:
    AccountAuthentication(const Common::AccountStorage& storage);

    Common::AccountAuthenticationStatusCode AuthenticateAccount(std::string username, std::string password);

private:
    Common::AccountStorage m_storage;
};
using AccountAuthenticationPtr = std::shared_ptr<AccountAuthentication>;
