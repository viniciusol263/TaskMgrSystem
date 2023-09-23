#pragma once

enum class AccountHandlerStatusCode : int 
{
    AccountSuccessfullyCreated = 0,
    AccountSuccessfullyDeleted,
    AccountAlreadyExists,
    FailedToCreateAccount,
    FailedToDeleteAccount
};