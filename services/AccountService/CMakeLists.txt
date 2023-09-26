cmake_minimum_required(VERSION 3.0.0)
project(AccountService)

set(ACCOUNTSERVICE_SRC AccountService.cpp
                       AccountHandler/AccountHandler.cpp
                       AccountMonitor/AccountMonitor.cpp
                       
                       ${TASKMGRSYSTEMSOURCEPATH}/libs/Utils/ErrorHandling/ErrorHandling.cpp
                       ${TASKMGRSYSTEMSOURCEPATH}/libs/Utils/CryptoHandler/CryptoHandler.cpp
                       
                       ${TASKMGRSYSTEMSOURCEPATH}/libs/CommonCxx/StatusCode.cpp
                       
                       ${TASKMGRSYSTEMSOURCEPATH}/recipes/AccountServiceIPC/AccountServiceIPC.pb.cc
                       ${TASKMGRSYSTEMSOURCEPATH}/recipes/AccountServiceIPC/AccountServiceIPC.grpc.pb.cc)

add_executable(AccountService main.cpp ${ACCOUNTSERVICE_SRC})
target_include_directories(AccountService PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                                ${CMAKE_CURRENT_SOURCE_DIR}/AccountHandler
                                                ${CMAKE_CURRENT_SOURCE_DIR}/AccountMonitor

                                                ${TASKMGRSYSTEMSOURCEPATH}/services
                                                ${TASKMGRSYSTEMSOURCEPATH}/libs
                                                ${TASKMGRSYSTEMSOURCEPATH}/libs/Utils
                                                ${TASKMGRSYSTEMSOURCEPATH}/recipes
                                                ${TASKMGRSYSTEMSOURCEPATH}/recipes/AccountService
)
target_link_libraries(AccountService nlohmann_json::nlohmann_json stduuid::stduuid cryptopp::cryptopp fmt::fmt uuid protobuf::protobuf gRPC::grpc gRPC::grpc++ gRPC::grpc++_reflection gRPC::grpc++_unsecure)