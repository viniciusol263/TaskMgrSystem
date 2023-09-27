#include <chrono>
#include <thread>
#include <iostream>
#include <sstream>
#include <vector>

#include "AccountMonitor.h"

using namespace std::chrono_literals;

AccountMonitor::AccountMonitor(AccountHandlerPtr accountHandler, AccountAuthenticationPtr accountAuth) 
{
    m_accountServiceIPC = std::make_shared<AccountServiceIPCImpl>(accountHandler, accountAuth);

    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder server;
    server.AddListeningPort(accountHandlerIpcPath, grpc::InsecureServerCredentials());
    server.RegisterService(m_accountServiceIPC.get());
    m_grpcServer = server.BuildAndStart();
}

AccountMonitor::~AccountMonitor()
{
    m_grpcServer->Shutdown();
    m_grpcServer->Wait();
}


AccountServiceIPCImpl::AccountServiceIPCImpl(AccountHandlerPtr accountHandler, AccountAuthenticationPtr accountAuth) :
    m_accountHandler(std::move(accountHandler)),
    m_accountAuth(std::move(accountAuth))
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

grpc::Status AccountServiceIPCImpl::AuthenticateAccount(grpc::ServerContext* context, const AccountServiceIPC::AuthenticateAccountRequest* request, AccountServiceIPC::AuthenticateAccountResponse* response)
{
    m_accountAuth->AuthenticateAccount(request->username(), request->password());
    return grpc::Status::OK;
}

