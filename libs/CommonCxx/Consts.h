#pragma once

#include <filesystem>
#include <string>
#include <chrono>

using namespace std::chrono_literals;
namespace Common
{
    constexpr const char* accountHandlerIpcPath = "unix:///home/vinicius/accountHandlerIpc.sock";


    const auto expirationTime = 2min;
}