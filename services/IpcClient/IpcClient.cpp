#include <thread>
#include <sstream>
#include <chrono>
#include <iostream>

#include "IpcClient.h"

#include "CommonCxx/Consts.h"

AccountClientIPC::AccountClientIPC()
{
    m_accountServiceClientStub = AccountServiceIPC::AccountServiceIPC::NewStub(grpc::CreateChannel(accountHandlerIpcPath, grpc::InsecureChannelCredentials()));
}

void AccountClientIPC::CreateAccount(std::string username, std::string password)
{
    grpc::ClientContext context;
    ::AccountServiceIPC::CreateAccountRequest request;
    ::AccountServiceIPC::CreateAccountResponse response;
    request.set_username(username);
    request.set_password(password);
    grpc::Status status = m_accountServiceClientStub->CreateAccount(&context, request, &response);
    std::cout << "CLIENT CREATE" << status.error_code() << " " << status.error_message() << std::endl;
}
    
void AccountClientIPC::DeleteAccount(std::string username)
{
    grpc::ClientContext context;
    AccountServiceIPC::DeleteAccountRequest request;
    AccountServiceIPC::DeleteAccountResponse response;
    request.set_username(username);
    grpc::Status status = m_accountServiceClientStub->DeleteAccount(&context, request, &response);
    std::cout << "CLIENT DELETE" << status.error_code() << " " << status.error_message() << std::endl;
}

IpcClient::IpcClient()
{   
    m_accountClientIpc = std::make_shared<AccountClientIPC>();
    m_threadHandler = std::make_shared<std::future<void>>(std::async(std::launch::async, &IpcClient::ThreadHandler, this));
    m_running = true;
}

IpcClient::~IpcClient()
{
    m_running = false;
    m_threadHandler.get();
}

void IpcClient::ThreadHandler()
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
                m_accountClientIpc->CreateAccount(argStrings[1], argStrings[2]);
                argStrings.clear();
            }
            if(argStrings.size() == 2 && argStrings[0] == "DELETE") {
                m_accountClientIpc->DeleteAccount(argStrings[1]);
                argStrings.clear();
            }
        }
        std::this_thread::sleep_for(100ms);
    }
}
