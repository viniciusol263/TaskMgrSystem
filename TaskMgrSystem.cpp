#include "TaskMgrSystem.h"

TaskMgrSystem::TaskMgrSystem() 
{
    m_accountService = std::make_shared<AccountService>();
    // std::cout << "Hello World" << std::endl;

    // std::ifstream jsonFile;
    // jsonFile.exceptions(std::fstream::badbit | std::fstream::failbit);
    // jsonFile.open("test.json", std::fstream::in);
    
    // auto json = nlohmann::json::parse(jsonFile);

    // std::for_each(json["Accounts"].begin(), json["Accounts"].end(), [](const auto& elem) {
    //     std::cout << elem << std::endl;
    // });
}