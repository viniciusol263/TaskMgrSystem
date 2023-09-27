#include "AccountServiceClient.h"


AccountServiceClient::AccountServiceClient()
{
    m_accountServiceClientStub = AccountServiceIPC::AccountServiceIPC::NewStub(grpc::CreateChannel(accountHandlerIpcPath, grpc::InsecureChannelCredentials()));
}

void AccountServiceClient::CreateAccount(std::string username, std::string password)
{
    grpc::ClientContext context;
    ::AccountServiceIPC::CreateAccountRequest request;
    ::AccountServiceIPC::CreateAccountResponse response;
    request.set_username(username);
    request.set_password(password);
    grpc::Status status = m_accountServiceClientStub->CreateAccount(&context, request, &response);
    std::cout << "CLIENT CREATE" << status.error_code() << " " << status.error_message() << std::endl;
}
    
void AccountServiceClient::DeleteAccount(std::string username)
{
    grpc::ClientContext context;
    AccountServiceIPC::DeleteAccountRequest request;
    AccountServiceIPC::DeleteAccountResponse response;
    request.set_username(username);
    grpc::Status status = m_accountServiceClientStub->DeleteAccount(&context, request, &response);
    std::cout << "CLIENT DELETE" << status.error_code() << " " << status.error_message() << std::endl;
}

void AccountServiceClient::AuthenticateAccount(std::string username, std::string password)
{
    grpc::ClientContext context;
    AccountServiceIPC::AuthenticateAccountRequest request;
    AccountServiceIPC::AuthenticateAccountResponse response;
    request.set_username(username);
    request.set_password(password);
    grpc::Status status = m_accountServiceClientStub->AuthenticateAccount(&context, request, &response);
    std::cout << "CLIENT AUTH" << status.error_code() << " " << status.error_message() << std::endl;
}
