#include <fstream>
#include <filesystem>
#include <iostream>

#define UUID_SYSTEM_GENERATOR
#include "uuid.h"
#include "nlohmann/json.hpp"

#include "AccountHandler.h"
#include "CryptoHandler/CryptoHandler.h"
#include "ErrorHandling/ErrorHandling.h"


AccountHandler::AccountHandler()
{}

AccountHandlerStatusCode AccountHandler::CreateAccount(std::string username, std::string password)
{
    try
    {
        auto rootPath = std::filesystem::current_path();
        auto accountsPath = rootPath.parent_path() / "objects/accounts";
        auto accountFilename = username + "_account.json";

        std::filesystem::current_path(accountsPath);

        for(const auto& filePath : std::filesystem::recursive_directory_iterator(std::filesystem::current_path()))
            if(filePath.path().filename().string() == accountFilename) return AccountHandlerStatusCode::AccountAlreadyExists;

        std::ofstream accountFile;
        accountFile.exceptions(std::ios::badbit | std::ios::failbit);
        accountFile.open(accountFilename, std::ios::out | std::ios::trunc);
        
        auto accountId = uuids::to_string(uuids::uuid_system_generator{}());
        nlohmann::json accountJson;
        accountJson["Id"] = accountId;
        accountJson["Username"] = username;
        accountJson["Password"] = CryptoHandler::GenerateSHA256(password);

        accountFile << accountJson.dump(4) << std::endl;
        accountFile.close();

        std::filesystem::current_path(rootPath);
    }
    catch(const std::ifstream::failure& e)
    {
        throw(ErrorHandling("AccountHandler failed to create a new account", static_cast<int>(AccountHandlerStatusCode::FailedToCreateAccount)));
    }

    return AccountHandlerStatusCode::AccountSuccessfullyCreated;
}

AccountHandlerStatusCode AccountHandler::DeleteAccount(std::string username)
{
    auto rootPath = std::filesystem::current_path();
    auto accountsPath = rootPath.parent_path() / "objects/accounts";
    auto accountFilename = username + "_account.json";

    std::filesystem::current_path(accountsPath);

    for(const auto& filePath : std::filesystem::recursive_directory_iterator(std::filesystem::current_path()))
        if(filePath.path().filename().string() == accountFilename)
        {
            std::filesystem::remove(filePath.path());
            return AccountHandlerStatusCode::AccountSuccessfullyDeleted;
        }
}
