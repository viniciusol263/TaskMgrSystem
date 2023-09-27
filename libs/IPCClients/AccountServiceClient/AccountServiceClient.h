#pragma once

#include <memory>
#include <future>

#include "grpcpp/grpcpp.h"
#include "grpcpp/ext/proto_server_reflection_plugin.h"

#include "AccountServiceIPC/AccountServiceIPC.grpc.pb.h"
#include "CommonCxx/Consts.h"

class AccountServiceClient
{
public:
    AccountServiceClient();

    void CreateAccount(std::string username, std::string password);
    void DeleteAccount(std::string username);
    void AuthenticateAccount(std::string username, std::string password);

private:
    std::unique_ptr<AccountServiceIPC::AccountServiceIPC::Stub> m_accountServiceClientStub;
};
using AccountServiceClientPtr = std::shared_ptr<AccountServiceClient>;