#pragma once

#include <string>

namespace Common
{
    enum class AccountHandlerStatusCode : int 
    {
        AccountSuccessfullyCreated = 0,
        AccountSuccessfullyDeleted,
        AccountAlreadyExists,
        AccountCouldntBeFound,
        FailedToCreateAccount,
        FailedToDeleteAccount
    };

    std::string AccountHandlerStatusCodeToString(const AccountHandlerStatusCode& statusCode);
}