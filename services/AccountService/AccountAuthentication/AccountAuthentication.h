#pragma once

#include <memory>
#include <string>
#include <future>
#include <optional>

#include "CommonCxx/StatusCode.h"
#include "CommonCxx/SqliteTables.h"

struct AuthenticationStructure 
{
public:
    AuthenticationStructure() = default;
    std::string username;
    std::shared_ptr<std::future<void>> expirationTimer;

    bool Expired();
};

class AccountAuthentication
{
public:
    AccountAuthentication(const Common::AccountStorage& storage);

    Common::AccountAuthenticationStatusCode AuthenticateAccount(std::string username, std::string password);
    std::shared_ptr<AuthenticationStructure> GetSession();
private:
    Common::AccountStorage m_storage;
    std::shared_ptr<AuthenticationStructure> m_session;
    bool m_endTimer;
};
using AccountAuthenticationPtr = std::shared_ptr<AccountAuthentication>;
