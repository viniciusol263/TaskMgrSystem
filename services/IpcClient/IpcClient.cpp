#include <thread>
#include <sstream>
#include <chrono>
#include <iostream>

#include "IpcClient.h"

#include "CommonCxx/Consts.h"
#include "CommonCxx/StatusCode.h"
#include "Utils/ErrorHandling/ErrorHandling.h"


IpcClient::IpcClient()
{   
    try 
    {
        m_accountServiceClient = std::make_shared<AccountServiceClient>();
        m_threadHandler = std::make_shared<std::future<void>>(std::async(std::launch::async, &IpcClient::ThreadHandler, this));
        m_running = true;
    }
    catch(const ErrorHandling& e)
    {
        std::cout << "Couldn't authenticate: " << e.GetErrorMessage() << std::endl;
    }
}

IpcClient::~IpcClient()
{
    m_running = false;
    m_threadHandler.get();
}

void IpcClient::ThreadHandler()
{
    try
    {
        using namespace std::chrono_literals;
        std::string readFromStream;
        std::stringstream separatorStream;
        std::vector<std::string> argStrings;
        while(m_running)
        {
            std::getline(std::cin, readFromStream);
            std::stringstream separatorStream(readFromStream);
            for(std::string tmpString; separatorStream >> tmpString;)
            {
                argStrings.push_back(tmpString);
                if(argStrings.size() == 3 && argStrings[0] == "CREATE") {
                    auto statusCode = m_accountServiceClient->CreateAccount(argStrings[1], argStrings[2]);
                    std::cout << Common::AccountHandlerStatusCodeToString(statusCode) << std::endl;
                    argStrings.clear();
                }
                else if(argStrings.size() == 3 && argStrings[0] == "AUTH") {
                    auto statusCode = m_accountServiceClient->AuthenticateAccount(argStrings[1], argStrings[2]);
                    std::cout << Common::AccountAuthenticationStatusCodeToString(statusCode) << std::endl;
                    argStrings.clear();
                }
                else if(argStrings.size() == 2 && argStrings[0] == "DELETE") {
                    auto statusCode = m_accountServiceClient->DeleteAccount(argStrings[1]);
                    std::cout << Common::AccountHandlerStatusCodeToString(statusCode) << std::endl;
                    argStrings.clear();
                }
            }
            std::this_thread::sleep_for(100ms);
        }
    }
    catch(const ErrorHandling& e)
    {
        std::cout << "Couldn't authenticate: " << e.GetErrorMessage() << std::endl;
    }
}
