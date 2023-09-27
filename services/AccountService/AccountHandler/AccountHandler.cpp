#include <fstream>
#include <filesystem>
#include <iostream>

#define UUID_SYSTEM_GENERATOR
#include "uuid.h"
#include "nlohmann/json.hpp"
#include "fmt/format.h"

#include "AccountHandler.h"
#include "CryptoHandler/CryptoHandler.h"
#include "ErrorHandling/ErrorHandling.h"
#include "CommonCxx/FileSystemRAII.h"


AccountHandler::AccountHandler(const Common::AccountStorage& storage) :
    m_storage(storage)
{}

Common::AccountHandlerStatusCode AccountHandler::CreateAccount(std::string username, std::string password)
{
    try
    {   
        auto returnedId = m_storage.get_all<Common::Account>(sqlite_orm::where(sqlite_orm::c(&Common::Account::username) = username));
        if(returnedId.size() > 0)
        {
            std::cout << m_storage.dump(returnedId[0]) << std::endl;
            return Common::AccountHandlerStatusCode::AccountAlreadyExists;
        }
        auto accountId = uuids::to_string(uuids::uuid_system_generator{}());
        Common::Account account {
            .id = 0,
            .accountId = accountId,
            .username = username,
            .password = CryptoHandler::GenerateSHA256(password),
            .typeId = 1
        };
        m_storage.insert(account);   
    }
    catch(const std::ifstream::failure& e)
    {
        throw(ErrorHandling(std::string("Failed to create a new account: ") + std::string(e.what()), static_cast<int>(Common::AccountHandlerStatusCode::FailedToCreateAccount)));
    }

    return Common::AccountHandlerStatusCode::AccountSuccessfullyCreated;
}

Common::AccountHandlerStatusCode AccountHandler::DeleteAccount(std::string username)
{
    try
    {
        auto returnedId = m_storage.get_all<Common::Account>(sqlite_orm::where(sqlite_orm::c(&Common::Account::username) = username));
        if(returnedId.size() > 0)
        {
            m_storage.remove<Common::Account>(returnedId[0].id);
            return Common::AccountHandlerStatusCode::AccountAlreadyExists;
        }
    }
    catch(const std::filesystem::filesystem_error& e)
    {
        throw ErrorHandling(std::string("Couldn't delete the account: ") + std::string(e.what()), static_cast<int>(Common::AccountHandlerStatusCode::FailedToDeleteAccount));
    }
    return Common::AccountHandlerStatusCode::AccountCouldntBeFound;
}
