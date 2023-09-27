#include <exception>
#include <fstream>
#include <string>
#include <iostream>

#include "nlohmann/json.hpp"

#include "CommonCxx/FileSystemRAII.h"
#include "CommonCxx/Consts.h"
#include "AccountAuthentication.h"
#include "Utils/ErrorHandling/ErrorHandling.h"
#include "Utils/CryptoHandler/CryptoHandler.h"

AccountAuthentication::AccountAuthentication(const Common::AccountStorage& storage) :
    m_storage(storage)
{}

Common::AccountAuthenticationStatusCode AccountAuthentication::AuthenticateAccount(std::string username, std::string password)
{
    try
    {
        auto returnedId = m_storage.get_all<Common::Account>(sqlite_orm::where(sqlite_orm::c(&Common::Account::username) = username));
        if(returnedId.size() > 0 && returnedId[0].username == username && returnedId[0].password == CryptoHandler::GenerateSHA256(password))
        {
            std::cout << "Has authenticated " << username << " pass: " << password << std::endl;
            return Common::AccountAuthenticationStatusCode::AuthenticatedAccount;
        }

        return Common::AccountAuthenticationStatusCode::ErrorAuthenticationAccount;
    }
    catch(const std::ifstream::failure& e)
    {
        throw ErrorHandling(std::string("File operations has failed: ") + std::string(e.what()), static_cast<int>(Common::FSFailures::ErrorOpening));
    }
}