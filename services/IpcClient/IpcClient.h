#pragma once

#include <memory>
#include <future>

#include "grpcpp/grpcpp.h"
#include "grpcpp/ext/proto_server_reflection_plugin.h"

#include "AccountServiceClient/AccountServiceClient.h"



class IpcClient
{
public:
    IpcClient();
    ~IpcClient();

private:
    void ThreadHandler();
    bool m_running;
    std::shared_ptr<std::future<void>> m_threadHandler;
    AccountServiceClientPtr m_accountServiceClient;
};
using IpcClientPtr = std::shared_ptr<IpcClient>;