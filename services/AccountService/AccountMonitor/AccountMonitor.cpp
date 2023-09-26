#include <chrono>
#include <thread>
#include <iostream>
#include <sstream>
#include <vector>

#include "AccountMonitor.h"

using namespace std::chrono_literals;

AccountMonitor::AccountMonitor(AccountHandlerPtr accountHandler) :
    m_accountHandler(std::move(accountHandler))
{
    m_accountServiceIPC = std::make_shared<AccountServiceIPCImpl>(m_accountHandler);

    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder server;
    server.AddListeningPort(accountHandlerIpcPath, grpc::InsecureServerCredentials());
    server.RegisterService(m_accountServiceIPC.get());
    std::cout << m_accountServiceIPC.get() << std::endl;
    m_grpcServer = server.BuildAndStart();
}

AccountMonitor::~AccountMonitor()
{
    m_grpcServer->Shutdown();
    m_grpcServer->Wait();
}


AccountServiceIPCImpl::AccountServiceIPCImpl(AccountHandlerPtr accountHandler) :
    m_accountHandler(std::move(accountHandler))
{}

grpc::Status AccountServiceIPCImpl::CreateAccount(grpc::ServerContext* context, const AccountServiceIPC::CreateAccountRequest* request, AccountServiceIPC::CreateAccountResponse* response)
{
    m_accountHandler->CreateAccount(request->username(), request->password());
    return grpc::Status::OK;
}

grpc::Status AccountServiceIPCImpl::DeleteAccount(grpc::ServerContext* context, const AccountServiceIPC::DeleteAccountRequest* request, AccountServiceIPC::DeleteAccountResponse* response)
{
    m_accountHandler->DeleteAccount(request->username());
    return grpc::Status::OK;
}
