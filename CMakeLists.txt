cmake_minimum_required(VERSION 3.0.0)
project(TaskMgrSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "g++")

find_package(nlohmann_json REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(Microsoft.GSL REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(stduuid REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(cryptopp REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(fmt REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)



set(TASKMGRSYSTEM_MAIN main.cpp)
set(TASKMGRSYSTEM_SRC  TaskMgrSystem.cpp

                       services/AccountService/AccountService.cpp
                       services/AccountService/AccountHandler/AccountHandler.cpp
                       
                       libs/Utils/ErrorHandling/ErrorHandling.cpp
                       libs/Utils/CryptoHandler/CryptoHandler.cpp)

add_executable(TaskMgrSystem ${TASKMGRSYSTEM_MAIN} ${TASKMGRSYSTEM_SRC})
target_include_directories(TaskMgrSystem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                                ${CMAKE_CURRENT_SOURCE_DIR}/services
                                                ${CMAKE_CURRENT_SOURCE_DIR}/libs
                                                ${CMAKE_CURRENT_SOURCE_DIR}/libs/Utils
                                                
                                                ${CMAKE_CURRENT_SOURCE_DIR}/services/AccountService)

target_link_directories(TaskMgrSystem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
target_link_libraries(TaskMgrSystem nlohmann_json::nlohmann_json stduuid::stduuid cryptopp::cryptopp fmt::fmt uuid)
