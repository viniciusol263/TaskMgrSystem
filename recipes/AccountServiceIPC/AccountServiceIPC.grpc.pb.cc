// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: AccountServiceIPC.proto

#include "AccountServiceIPC.pb.h"
#include "AccountServiceIPC.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace AccountServiceIPC {

static const char* AccountServiceIPC_method_names[] = {
  "/AccountServiceIPC.AccountServiceIPC/Ping",
  "/AccountServiceIPC.AccountServiceIPC/CreateAccount",
  "/AccountServiceIPC.AccountServiceIPC/DeleteAccount",
  "/AccountServiceIPC.AccountServiceIPC/AuthenticateAccount",
};

std::unique_ptr< AccountServiceIPC::Stub> AccountServiceIPC::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< AccountServiceIPC::Stub> stub(new AccountServiceIPC::Stub(channel, options));
  return stub;
}

AccountServiceIPC::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Ping_(AccountServiceIPC_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CreateAccount_(AccountServiceIPC_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DeleteAccount_(AccountServiceIPC_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AuthenticateAccount_(AccountServiceIPC_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status AccountServiceIPC::Stub::Ping(::grpc::ClientContext* context, const ::AccountServiceIPC::Empty& request, ::AccountServiceIPC::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::AccountServiceIPC::Empty, ::AccountServiceIPC::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Ping_, context, request, response);
}

void AccountServiceIPC::Stub::async::Ping(::grpc::ClientContext* context, const ::AccountServiceIPC::Empty* request, ::AccountServiceIPC::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::AccountServiceIPC::Empty, ::AccountServiceIPC::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Ping_, context, request, response, std::move(f));
}

void AccountServiceIPC::Stub::async::Ping(::grpc::ClientContext* context, const ::AccountServiceIPC::Empty* request, ::AccountServiceIPC::Empty* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Ping_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::AccountServiceIPC::Empty>* AccountServiceIPC::Stub::PrepareAsyncPingRaw(::grpc::ClientContext* context, const ::AccountServiceIPC::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::AccountServiceIPC::Empty, ::AccountServiceIPC::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Ping_, context, request);
}

::grpc::ClientAsyncResponseReader< ::AccountServiceIPC::Empty>* AccountServiceIPC::Stub::AsyncPingRaw(::grpc::ClientContext* context, const ::AccountServiceIPC::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncPingRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status AccountServiceIPC::Stub::CreateAccount(::grpc::ClientContext* context, const ::AccountServiceIPC::CreateAccountRequest& request, ::AccountServiceIPC::CreateAccountResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::AccountServiceIPC::CreateAccountRequest, ::AccountServiceIPC::CreateAccountResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CreateAccount_, context, request, response);
}

void AccountServiceIPC::Stub::async::CreateAccount(::grpc::ClientContext* context, const ::AccountServiceIPC::CreateAccountRequest* request, ::AccountServiceIPC::CreateAccountResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::AccountServiceIPC::CreateAccountRequest, ::AccountServiceIPC::CreateAccountResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CreateAccount_, context, request, response, std::move(f));
}

void AccountServiceIPC::Stub::async::CreateAccount(::grpc::ClientContext* context, const ::AccountServiceIPC::CreateAccountRequest* request, ::AccountServiceIPC::CreateAccountResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CreateAccount_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::AccountServiceIPC::CreateAccountResponse>* AccountServiceIPC::Stub::PrepareAsyncCreateAccountRaw(::grpc::ClientContext* context, const ::AccountServiceIPC::CreateAccountRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::AccountServiceIPC::CreateAccountResponse, ::AccountServiceIPC::CreateAccountRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CreateAccount_, context, request);
}

::grpc::ClientAsyncResponseReader< ::AccountServiceIPC::CreateAccountResponse>* AccountServiceIPC::Stub::AsyncCreateAccountRaw(::grpc::ClientContext* context, const ::AccountServiceIPC::CreateAccountRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCreateAccountRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status AccountServiceIPC::Stub::DeleteAccount(::grpc::ClientContext* context, const ::AccountServiceIPC::DeleteAccountRequest& request, ::AccountServiceIPC::DeleteAccountResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::AccountServiceIPC::DeleteAccountRequest, ::AccountServiceIPC::DeleteAccountResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_DeleteAccount_, context, request, response);
}

void AccountServiceIPC::Stub::async::DeleteAccount(::grpc::ClientContext* context, const ::AccountServiceIPC::DeleteAccountRequest* request, ::AccountServiceIPC::DeleteAccountResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::AccountServiceIPC::DeleteAccountRequest, ::AccountServiceIPC::DeleteAccountResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DeleteAccount_, context, request, response, std::move(f));
}

void AccountServiceIPC::Stub::async::DeleteAccount(::grpc::ClientContext* context, const ::AccountServiceIPC::DeleteAccountRequest* request, ::AccountServiceIPC::DeleteAccountResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DeleteAccount_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::AccountServiceIPC::DeleteAccountResponse>* AccountServiceIPC::Stub::PrepareAsyncDeleteAccountRaw(::grpc::ClientContext* context, const ::AccountServiceIPC::DeleteAccountRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::AccountServiceIPC::DeleteAccountResponse, ::AccountServiceIPC::DeleteAccountRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_DeleteAccount_, context, request);
}

::grpc::ClientAsyncResponseReader< ::AccountServiceIPC::DeleteAccountResponse>* AccountServiceIPC::Stub::AsyncDeleteAccountRaw(::grpc::ClientContext* context, const ::AccountServiceIPC::DeleteAccountRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDeleteAccountRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status AccountServiceIPC::Stub::AuthenticateAccount(::grpc::ClientContext* context, const ::AccountServiceIPC::AuthenticateAccountRequest& request, ::AccountServiceIPC::AuthenticateAccountResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::AccountServiceIPC::AuthenticateAccountRequest, ::AccountServiceIPC::AuthenticateAccountResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AuthenticateAccount_, context, request, response);
}

void AccountServiceIPC::Stub::async::AuthenticateAccount(::grpc::ClientContext* context, const ::AccountServiceIPC::AuthenticateAccountRequest* request, ::AccountServiceIPC::AuthenticateAccountResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::AccountServiceIPC::AuthenticateAccountRequest, ::AccountServiceIPC::AuthenticateAccountResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AuthenticateAccount_, context, request, response, std::move(f));
}

void AccountServiceIPC::Stub::async::AuthenticateAccount(::grpc::ClientContext* context, const ::AccountServiceIPC::AuthenticateAccountRequest* request, ::AccountServiceIPC::AuthenticateAccountResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AuthenticateAccount_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::AccountServiceIPC::AuthenticateAccountResponse>* AccountServiceIPC::Stub::PrepareAsyncAuthenticateAccountRaw(::grpc::ClientContext* context, const ::AccountServiceIPC::AuthenticateAccountRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::AccountServiceIPC::AuthenticateAccountResponse, ::AccountServiceIPC::AuthenticateAccountRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AuthenticateAccount_, context, request);
}

::grpc::ClientAsyncResponseReader< ::AccountServiceIPC::AuthenticateAccountResponse>* AccountServiceIPC::Stub::AsyncAuthenticateAccountRaw(::grpc::ClientContext* context, const ::AccountServiceIPC::AuthenticateAccountRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAuthenticateAccountRaw(context, request, cq);
  result->StartCall();
  return result;
}

AccountServiceIPC::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      AccountServiceIPC_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< AccountServiceIPC::Service, ::AccountServiceIPC::Empty, ::AccountServiceIPC::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](AccountServiceIPC::Service* service,
             ::grpc::ServerContext* ctx,
             const ::AccountServiceIPC::Empty* req,
             ::AccountServiceIPC::Empty* resp) {
               return service->Ping(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      AccountServiceIPC_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< AccountServiceIPC::Service, ::AccountServiceIPC::CreateAccountRequest, ::AccountServiceIPC::CreateAccountResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](AccountServiceIPC::Service* service,
             ::grpc::ServerContext* ctx,
             const ::AccountServiceIPC::CreateAccountRequest* req,
             ::AccountServiceIPC::CreateAccountResponse* resp) {
               return service->CreateAccount(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      AccountServiceIPC_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< AccountServiceIPC::Service, ::AccountServiceIPC::DeleteAccountRequest, ::AccountServiceIPC::DeleteAccountResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](AccountServiceIPC::Service* service,
             ::grpc::ServerContext* ctx,
             const ::AccountServiceIPC::DeleteAccountRequest* req,
             ::AccountServiceIPC::DeleteAccountResponse* resp) {
               return service->DeleteAccount(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      AccountServiceIPC_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< AccountServiceIPC::Service, ::AccountServiceIPC::AuthenticateAccountRequest, ::AccountServiceIPC::AuthenticateAccountResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](AccountServiceIPC::Service* service,
             ::grpc::ServerContext* ctx,
             const ::AccountServiceIPC::AuthenticateAccountRequest* req,
             ::AccountServiceIPC::AuthenticateAccountResponse* resp) {
               return service->AuthenticateAccount(ctx, req, resp);
             }, this)));
}

AccountServiceIPC::Service::~Service() {
}

::grpc::Status AccountServiceIPC::Service::Ping(::grpc::ServerContext* context, const ::AccountServiceIPC::Empty* request, ::AccountServiceIPC::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status AccountServiceIPC::Service::CreateAccount(::grpc::ServerContext* context, const ::AccountServiceIPC::CreateAccountRequest* request, ::AccountServiceIPC::CreateAccountResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status AccountServiceIPC::Service::DeleteAccount(::grpc::ServerContext* context, const ::AccountServiceIPC::DeleteAccountRequest* request, ::AccountServiceIPC::DeleteAccountResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status AccountServiceIPC::Service::AuthenticateAccount(::grpc::ServerContext* context, const ::AccountServiceIPC::AuthenticateAccountRequest* request, ::AccountServiceIPC::AuthenticateAccountResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace AccountServiceIPC

