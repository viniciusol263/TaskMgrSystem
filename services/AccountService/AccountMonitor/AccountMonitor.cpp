#include <chrono>
#include <thread>
#include <iostream>
#include <sstream>
#include <vector>

#include "AccountMonitor.h"
#include "CommonCxx/FoldCallable.h"

using namespace std::chrono_literals;

AccountMonitor::AccountMonitor(AccountHandlerPtr accountHandler) :
    m_accountHandler(std::move(accountHandler))
{
    InitializeCallables();
    m_watcherThread = std::make_unique<std::future<void>>(std::async(std::launch::async, &AccountMonitor::AccountWatcher, this));
    m_isRunning = true;
}

AccountMonitor::~AccountMonitor()
{
    m_isRunning = false;
    m_watcherThread->get();
}

void AccountMonitor::AccountWatcher()
{
    std::string readFromStream;
    std::stringstream separatorStream;
    std::vector<std::string> argStrings;
    while(m_isRunning)
    {
        std::getline(std::cin, readFromStream);
        std::stringstream separatorStream(readFromStream);
        for(std::string tmpString; separatorStream >> tmpString;)
        {
            argStrings.push_back(tmpString);
            for(const auto& callable : m_callables)
            {
                if(callable->GetIdentifier() == argStrings[0])
                {
                    std::cout << "Testing " + callable->GetIdentifier() << std::endl;
                    argStrings.erase(argStrings.begin());
                    // callable->Execute();
                    argStrings.clear();
                }
            }
        }
        std::this_thread::sleep_for(100ms);
    }
}

void AccountMonitor::InitializeCallables()
{
    using namespace std::placeholders;
    
    m_callables.push_back(std::make_shared<FoldCallable<std::string, std::string>>(std::string("CREATE"), std::bind(&AccountHandler::CreateAccount, m_accountHandler, _1, _2)));
    m_callables.push_back(std::make_shared<FoldCallable<std::string>>(std::string("DELETE"), std::bind(&AccountHandler::DeleteAccount, m_accountHandler, _1)));
}