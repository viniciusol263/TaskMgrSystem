#include <fstream>
#include <filesystem>
#include <iostream>

#define UUID_SYSTEM_GENERATOR
#include "uuid.h"
#include "nlohmann/json.hpp"

#include "AccountHandler.h"
#include "CryptoHandler/CryptoHandler.h"
#include "ErrorHandling/ErrorHandling.h"
#include "CommonCxx/FileSystemRAII.h"

AccountHandler::AccountHandler()
{}

Common::AccountHandlerStatusCode AccountHandler::CreateAccount(std::string username, std::string password)
{
    try
    {
        auto rootPath = std::filesystem::current_path();
        auto accountFilename = username + accountFileSuffix;

        Common::FileSystemRAII fileSystem(accountPath);

        for(const auto& filePath : std::filesystem::recursive_directory_iterator(fileSystem.GetCurrentPath()))
            if(filePath.path().filename().string() == accountFilename) return Common::AccountHandlerStatusCode::AccountAlreadyExists;

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
    }
    catch(const std::ifstream::failure& e)
    {
        throw(ErrorHandling("Failed to create a new account", static_cast<int>(Common::AccountHandlerStatusCode::FailedToCreateAccount)));
    }

    return Common::AccountHandlerStatusCode::AccountSuccessfullyCreated;
}

Common::AccountHandlerStatusCode AccountHandler::DeleteAccount(std::string username)
{
    try
    {
        auto rootPath = std::filesystem::current_path();
        auto accountFilename = username + accountFileSuffix;

        Common::FileSystemRAII fileSystem(accountPath);

        for(const auto& filePath : std::filesystem::recursive_directory_iterator(fileSystem.GetCurrentPath()))
            if(filePath.path().filename().string() == accountFilename)
            {
                std::filesystem::remove(filePath.path());
                return Common::AccountHandlerStatusCode::AccountSuccessfullyDeleted;
            }
        
    }
    catch(const std::filesystem::filesystem_error& e)
    {
        throw ErrorHandling("Couldn't delete the account", static_cast<int>(Common::AccountHandlerStatusCode::FailedToDeleteAccount));
    }
    return Common::AccountHandlerStatusCode::AccountCouldntBeFound;
}
