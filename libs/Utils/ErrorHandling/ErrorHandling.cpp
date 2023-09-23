#include "ErrorHandling.h"

ErrorHandling::ErrorHandling(std::string errorMessage, int statusCode) :
    m_errorMessage(errorMessage),
    m_statusCode(statusCode)
{}

int ErrorHandling::GetStatusCode() 
{
    return m_statusCode;
}

std::string ErrorHandling::GetErrorMessage() const
{
    return std::string(what());
}

const char* ErrorHandling::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
    return m_errorMessage.c_str();
}