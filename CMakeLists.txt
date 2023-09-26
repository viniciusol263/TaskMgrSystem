cmake_minimum_required(VERSION 3.0.0)
project(TaskMgrSystem)

set(CMAKE_CXX_STANDARD 17)
set(TASKMGRSYSTEMSOURCEPATH ${CMAKE_CURRENT_SOURCE_DIR})

find_package(nlohmann_json REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(Microsoft.GSL REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(stduuid REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(cryptopp REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(fmt REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(absl REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(c-ares REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(ZLIB REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(OpenSSL REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(re2 REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(protobuf REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
find_package(gRPC REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)




set(TASKMGRSYSTEM_MAIN main.cpp)
set(TASKMGRSYSTEM_SRC  TaskMgrSystem.cpp
                       
                       libs/Utils/ErrorHandling/ErrorHandling.cpp
                       libs/Utils/CryptoHandler/CryptoHandler.cpp
                       
                       libs/CommonCxx/StatusCode.cpp)

add_executable(TaskMgrSystem ${TASKMGRSYSTEM_MAIN} ${TASKMGRSYSTEM_SRC})
target_include_directories(TaskMgrSystem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                                ${CMAKE_CURRENT_SOURCE_DIR}/libs
                                                ${CMAKE_CURRENT_SOURCE_DIR}/libs/Utils
)

target_link_directories(TaskMgrSystem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/ConanLibs)
target_link_libraries(TaskMgrSystem nlohmann_json::nlohmann_json stduuid::stduuid cryptopp::cryptopp fmt::fmt uuid protobuf::protobuf gRPC::grpc gRPC::grpc++ gRPC::grpc++_reflection)
add_subdirectory(services/AccountService)
add_subdirectory(services/IpcClient)