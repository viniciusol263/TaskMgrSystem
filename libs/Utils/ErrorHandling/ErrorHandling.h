#pragma once

#include <exception>
#include <memory>
#include <string>

class ErrorHandling : public std::exception
{
public:
    ErrorHandling(std::string errorMessage, int statusCode);
    
    int GetStatusCode();
    std::string GetErrorMessage() const;

protected:
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override; 

private:
    std::string m_errorMessage;
    int m_statusCode;
};
using ErrorHandlingPtr = std::shared_ptr<ErrorHandling>;