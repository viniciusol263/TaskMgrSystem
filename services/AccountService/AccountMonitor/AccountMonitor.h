#pragma once

#include <memory>
#include <future>
#include <functional>
#include <vector>

#include "AccountHandler/AccountHandler.h"
#include "CommonCxx/FoldCallable.h"


class AccountMonitor 
{
public:
    AccountMonitor(AccountHandlerPtr accountHandler);
    ~AccountMonitor();

private:
    void AccountWatcher();

    AccountHandlerPtr m_accountHandler;
    bool m_isRunning;
    std::unique_ptr<std::future<void>> m_watcherThread;

    std::vector<VirtualFoldCallablePtr> m_callables;
protected:
    void InitializeCallables();
};
using AccountMonitorPtr = std::shared_ptr<AccountMonitor>;