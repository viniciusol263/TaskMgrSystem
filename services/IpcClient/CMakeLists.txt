cmake_minimum_required(VERSION 3.0.0)
project(IpcClient)

set(IPCCLIENT_SRC IpcClient.cpp)

add_executable(IpcClient main.cpp ${IPCCLIENT_SRC}
                                  ${TASKMGRSYSTEMSOURCEPATH}/recipes/AccountServiceIPC/AccountStructs.pb.cc
                                  ${TASKMGRSYSTEMSOURCEPATH}/recipes/AccountServiceIPC/AccountStructs.grpc.pb.cc
                                  ${TASKMGRSYSTEMSOURCEPATH}/recipes/AccountServiceIPC/AccountServiceIPC.pb.cc
                                  ${TASKMGRSYSTEMSOURCEPATH}/recipes/AccountServiceIPC/AccountServiceIPC.grpc.pb.cc

                                  ${TASKMGRSYSTEMSOURCEPATH}/libs/IPCClients/AccountServiceClient/AccountServiceClient.cpp
                                  
                                  ${TASKMGRSYSTEMSOURCEPATH}/libs/Utils/ErrorHandling/ErrorHandling.cpp

                                  ${TASKMGRSYSTEMSOURCEPATH}/libs/CommonCxx/StatusCode.cpp
)

target_include_directories(IpcClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                                ${CMAKE_CURRENT_SOURCE_DIR}/AccountHandler
                                                ${CMAKE_CURRENT_SOURCE_DIR}/AccountMonitor

                                                ${TASKMGRSYSTEMSOURCEPATH}/services
                                                ${TASKMGRSYSTEMSOURCEPATH}/libs
                                                ${TASKMGRSYSTEMSOURCEPATH}/libs/Utils
                                                ${TASKMGRSYSTEMSOURCEPATH}/libs/IPCClients
                                                ${TASKMGRSYSTEMSOURCEPATH}/recipes
                                                ${TASKMGRSYSTEMSOURCEPATH}/recipes/AccountService
)
target_link_libraries(IpcClient nlohmann_json::nlohmann_json stduuid::stduuid cryptopp::cryptopp fmt::fmt uuid protobuf::protobuf gRPC::grpc gRPC::grpc++ gRPC::grpc++_reflection gRPC::grpc++_unsecure)