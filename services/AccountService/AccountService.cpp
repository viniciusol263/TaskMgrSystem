#include <iostream>

#include "AccountService.h"
#include "ErrorHandling/ErrorHandling.h"

AccountService::AccountService()
{
    try
    {
        m_accountHandler = std::make_shared<AccountHandler>();
        m_accountHandler->CreateAccount("vinicius", "123445");
    }
    catch(const ErrorHandling& e)
    {
        std::cerr << e.GetErrorMessage() << std::endl;
    }
}