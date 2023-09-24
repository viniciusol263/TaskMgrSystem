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
        }
        return "Unknown";
    }
}
