#include <exception>
#include <fstream>
#include <string>
#include <iostream>
#include <chrono>
#include <memory>
#include <future>
#include <mutex>

#include "nlohmann/json.hpp"

#include "CommonCxx/FileSystemRAII.h"
#include "CommonCxx/Consts.h"
#include "AccountAuthentication.h"
#include "Utils/ErrorHandling/ErrorHandling.h"
#include "Utils/CryptoHandler/CryptoHandler.h"

AccountAuthentication::AccountAuthentication(const Common::AccountStorage& storage) :
    m_storage(storage),
    m_endTimer(false)
{
    m_session = std::make_shared<AuthenticationStructure>();
}

Common::AccountAuthenticationStatusCode AccountAuthentication::AuthenticateAccount(std::string username, std::string password)
{
    try
    {
        auto returnedId = m_storage.get_all<Common::Account>(sqlite_orm::where(sqlite_orm::c(&Common::Account::username) = username));
        if(returnedId.size() > 0 && returnedId[0].username == username && returnedId[0].password == CryptoHandler::GenerateSHA256(password))
        {
            std::cout << "Has authenticated " << username << " pass: " << password << std::endl;
            if(m_session->expirationTimer != nullptr)
            {
                if(!m_session->Expired()) m_endTimer = true;
                m_session->expirationTimer->get();
            }
            m_session->expirationTimer = std::make_unique<std::future<void>>(std::async(std::launch::async, [&]() {
                auto startingTime = std::chrono::steady_clock::now();
                while((std::chrono::duration<double>(std::chrono::steady_clock::now() - startingTime) <= Common::expirationTime) && !m_endTimer){}
                m_endTimer = false;
                return;
            }));
            
            return Common::AccountAuthenticationStatusCode::AuthenticatedAccount;
        }

        return Common::AccountAuthenticationStatusCode::ErrorAuthenticationAccount;
    }
    catch(const std::ifstream::failure& e)
    {
        throw ErrorHandling(std::string("File operations has failed: ") + std::string(e.what()), static_cast<int>(Common::FSFailures::ErrorOpening));
    }
}

std::shared_ptr<AuthenticationStructure> AccountAuthentication::GetSession()
{
    if(m_session->expirationTimer == nullptr)
    {
        return nullptr;
    }
    return m_session;
}

bool AuthenticationStructure::Expired()
{
    using namespace std::chrono_literals;
    return expirationTimer->wait_for(0s) == std::future_status::ready;
}
