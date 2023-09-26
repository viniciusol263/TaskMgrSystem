#pragma once

#include <memory>
#include <future>

#include "grpcpp/grpcpp.h"
#include "grpcpp/ext/proto_server_reflection_plugin.h"

#include "AccountServiceIPC/AccountServiceIPC.grpc.pb.h"

class AccountClientIPC 
{
public:
    AccountClientIPC();

    void CreateAccount(std::string username, std::string password);
    void DeleteAccount(std::string username);
private:
    std::unique_ptr<AccountServiceIPC::AccountServiceIPC::Stub> m_accountServiceClientStub;
};
using AccountClientIPCPtr = std::shared_ptr<AccountClientIPC>;

class IpcClient
{
public:
    IpcClient();
    ~IpcClient();

private:
    void ThreadHandler();
    bool m_running;
    std::shared_ptr<std::future<void>> m_threadHandler;
    AccountClientIPCPtr m_accountClientIpc;
};
using IpcClientPtr = std::shared_ptr<IpcClient>;