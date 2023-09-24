#include <iostream>

#include "AccountService.h"
#include "ErrorHandling/ErrorHandling.h"

AccountService::AccountService()
{
    try
    {
        m_accountHandler = std::make_shared<AccountHandler>();
        m_accountMonitor = std::make_shared<AccountMonitor>(m_accountHandler);
    }
    catch(const ErrorHandling& e)
    {
        std::cerr << e.GetErrorMessage() << std::endl;
    }
}