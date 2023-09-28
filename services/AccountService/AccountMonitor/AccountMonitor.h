#pragma once

#include <memory>
#include <future>
#include <functional>
#include <vector>
#include <map>

#include "grpcpp/grpcpp.h"
#include "grpcpp/ext/proto_server_reflection_plugin.h"
#include "grpcpp/health_check_service_interface.h"

#include "AccountHandler/AccountHandler.h"
#include "AccountServiceIPC/AccountServiceIPC.grpc.pb.h"
#include "CommonCxx/Consts.h"

class AccountServiceIPCImpl final : public AccountServiceIPC::AccountServiceIPC::Service 
{
public:
    AccountServiceIPCImpl(AccountHandlerPtr accountHandler);
    grpc::Status CreateAccount(grpc::ServerContext* context, const AccountServiceIPC::CreateAccountRequest* request, AccountServiceIPC::CreateAccountResponse* response);
    grpc::Status DeleteAccount(grpc::ServerContext* context, const AccountServiceIPC::DeleteAccountRequest* request, AccountServiceIPC::DeleteAccountResponse* response);
    grpc::Status AuthenticateAccount(grpc::ServerContext* context, const AccountServiceIPC::AuthenticateAccountRequest* request, AccountServiceIPC::AuthenticateAccountResponse* response);

private:
    AccountHandlerPtr m_accountHandler;
    AccountAuthenticationPtr m_accountAuth;

};
using AccountServiceIPCImplPtr = std::shared_ptr<AccountServiceIPCImpl>;

class AccountMonitor 
{
public:
    AccountMonitor(AccountHandlerPtr accountHandler);
    ~AccountMonitor();

private:
    std::shared_ptr<grpc::Service> m_accountServiceIPC;
    std::unique_ptr<grpc::Server> m_grpcServer{nullptr};
};
using AccountMonitorPtr = std::shared_ptr<AccountMonitor>;


