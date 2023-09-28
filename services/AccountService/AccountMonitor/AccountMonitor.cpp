#include <chrono>
#include <thread>
#include <iostream>
#include <sstream>
#include <vector>

#include "AccountMonitor.h"

using namespace std::chrono_literals;

AccountMonitor::AccountMonitor(AccountHandlerPtr accountHandler) 
{
    m_accountServiceIPC = std::make_shared<AccountServiceIPCImpl>(accountHandler);

    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder server;
    server.AddListeningPort(Common::accountHandlerIpcPath, grpc::InsecureServerCredentials());
    server.RegisterService(m_accountServiceIPC.get());
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
    auto statusCode = m_accountHandler->CreateAccount(request->username(), request->password());
    response->set_status_code(static_cast<AccountServiceIPC::AccountHandlerStatusCode>(statusCode));
    return grpc::Status::OK;
}

grpc::Status AccountServiceIPCImpl::DeleteAccount(grpc::ServerContext* context, const AccountServiceIPC::DeleteAccountRequest* request, AccountServiceIPC::DeleteAccountResponse* response)
{
    auto statusCode = m_accountHandler->DeleteAccount(request->username());
    response->set_status_code(static_cast<AccountServiceIPC::AccountHandlerStatusCode>(statusCode));
    return grpc::Status::OK;
}

grpc::Status AccountServiceIPCImpl::AuthenticateAccount(grpc::ServerContext* context, const AccountServiceIPC::AuthenticateAccountRequest* request, AccountServiceIPC::AuthenticateAccountResponse* response)
{
    auto statusCode = m_accountHandler->GetAccountAuth()->AuthenticateAccount(request->username(), request->password());
    response->set_status_code(static_cast<AccountServiceIPC::AccountAuthenticationStatusCode>(statusCode));
    return grpc::Status::OK;
}

