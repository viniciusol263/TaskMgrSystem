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

    enum class AccountAuthenticationStatusCode : int
    {
        AuthenticatedAccount = 0,
        ErrorAuthenticationAccount
    };

    enum class FSFailures : int
    {
        ErrorOpening = 0,
        ErrorWriting,
        ErrorReading,
        ErrorClosing
    };
}