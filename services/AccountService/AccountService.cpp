#include <iostream>

#include "AccountService.h"
#include "ErrorHandling/ErrorHandling.h"

AccountService::AccountService()
{
    try
    {
        auto storage = Common::InitAccountStorage(accountDataBase);
        storage.sync_schema();
        
        m_accountAuthentication = std::make_shared<AccountAuthentication>(storage);
        m_accountHandler = std::make_shared<AccountHandler>(storage, m_accountAuthentication);
        m_accountMonitor = std::make_shared<AccountMonitor>(m_accountHandler);
    }
    catch(const ErrorHandling& e)
    {
        std::cerr << e.GetErrorMessage() << std::endl;
    }
}