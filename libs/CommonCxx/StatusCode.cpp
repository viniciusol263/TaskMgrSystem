#include "StatusCode.h"

namespace Common
{
    std::string AccountHandlerStatusCodeToString(const AccountHandlerStatusCode& statusCode)
    {
        switch(statusCode)
        {
            case AccountHandlerStatusCode::AccountSuccessfullyCreated: return "AccountSuccessfullyCreated";
            case AccountHandlerStatusCode::AccountSuccessfullyDeleted: return "AccountSuccessfullyDeleted";
            case AccountHandlerStatusCode::AccountAlreadyExists: return "AccountAlreadyExists";
            case AccountHandlerStatusCode::AccountCouldntBeFound: return "AccountCouldntBeFound";
            case AccountHandlerStatusCode::FailedToCreateAccount: return "FailedToCreateAccount";
            case AccountHandlerStatusCode::FailedToDeleteAccount: return "FailedToDeleteAccount";
            case AccountHandlerStatusCode::NotAuthenticatedAccount: return "NotAuthenticatedAccount";
        }
        return "Unknown";
    }

    std::string AccountAuthenticationStatusCodeToString(const AccountAuthenticationStatusCode& statusCode)
    {
        switch(statusCode)
        {
            case AccountAuthenticationStatusCode::AuthenticatedAccount: return "AuthenticatedAccount";
            case AccountAuthenticationStatusCode::ErrorAuthenticationAccount: return "ErrorAuthenticationAccount";
        }
        return "Unknown";
    }
}
