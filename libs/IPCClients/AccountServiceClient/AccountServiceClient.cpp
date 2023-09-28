#include "AccountServiceClient.h"

#include "Utils/ErrorHandling/ErrorHandling.h"
#include "CommonCxx/StatusCode.h"

AccountServiceClient::AccountServiceClient()
{
    m_accountServiceClientStub = AccountServiceIPC::AccountServiceIPC::NewStub(grpc::CreateChannel(Common::accountHandlerIpcPath, grpc::InsecureChannelCredentials()));
}

Common::AccountHandlerStatusCode AccountServiceClient::CreateAccount(std::string username, std::string password)
{
    grpc::ClientContext context;
    AccountServiceIPC::CreateAccountRequest request;
    AccountServiceIPC::CreateAccountResponse response;
    request.set_username(username);
    request.set_password(password);
    auto status = m_accountServiceClientStub->CreateAccount(&context, request, &response);
    if(status.error_code() != 0) 
        throw ErrorHandling("Error message: " +  status.error_message() + " error details: " + status.error_details(), static_cast<int>(Common::gRPCFailures::ErrorOnClientCall));
    return static_cast<Common::AccountHandlerStatusCode>(response.status_code());
}
    
Common::AccountHandlerStatusCode AccountServiceClient::DeleteAccount(std::string username)
{
    grpc::ClientContext context;
    AccountServiceIPC::DeleteAccountRequest request;
    AccountServiceIPC::DeleteAccountResponse response;
    request.set_username(username);
    auto status = m_accountServiceClientStub->DeleteAccount(&context, request, &response);
    if(status.error_code() != 0) 
        throw ErrorHandling("Error message: " +  status.error_message() + " error details: " + status.error_details(), static_cast<int>(Common::gRPCFailures::ErrorOnClientCall));
    return static_cast<Common::AccountHandlerStatusCode>(response.status_code());
}

Common::AccountAuthenticationStatusCode AccountServiceClient::AuthenticateAccount(std::string username, std::string password)
{
    grpc::ClientContext context;
    AccountServiceIPC::AuthenticateAccountRequest request;
    AccountServiceIPC::AuthenticateAccountResponse response;
    request.set_username(username);
    request.set_password(password);
    auto status = m_accountServiceClientStub->AuthenticateAccount(&context, request, &response);
    // std::cout << "Error message: " +  status.error_message() + " error details: " + status.error_details() + " error code: " << int(status.error_code()) << std::endl;
    if(int(status.error_code()) != 0) 
        throw ErrorHandling("Error message: " +  status.error_message() + " error details: " + status.error_details(), static_cast<int>(Common::gRPCFailures::ErrorOnClientCall));
    return static_cast<Common::AccountAuthenticationStatusCode>(response.status_code());
}
