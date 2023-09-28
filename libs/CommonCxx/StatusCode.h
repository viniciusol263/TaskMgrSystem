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
        FailedToDeleteAccount,
        NotAuthenticatedAccount
    };

    std::string AccountHandlerStatusCodeToString(const AccountHandlerStatusCode& statusCode);

    enum class AccountAuthenticationStatusCode : int
    {
        AuthenticatedAccount = 0,
        ErrorAuthenticationAccount
    };

    std::string AccountAuthenticationStatusCodeToString(const AccountAuthenticationStatusCode& statusCode);
    
    enum class FSFailures : int
    {
        ErrorOpening = 0,
        ErrorWriting,
        ErrorReading,
        ErrorClosing
    };

    enum class gRPCFailures : int
    {
        ErrorOnClientCall = 0
    };
}