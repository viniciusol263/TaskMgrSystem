#pragma once

#include <filesystem>
#include <string>

constexpr const char* accountHandlerIpcPath = "unix:///home/vinicius/accountHandlerIpc.sock";
const std::filesystem::path accountPath = std::filesystem::current_path().parent_path().parent_path().parent_path() / "objects/accounts";
const std::string accountFileSuffix = "_account.json";