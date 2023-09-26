#include <csignal>
#include <exception>
#include <iostream>
#include "IpcClient.h"

int main()
{
    try
    {
        IpcClient ipcClient;
        
        sigset_t m_sigset;
        sigemptyset(&m_sigset);
        
        sigaddset(&m_sigset, SIGINT);
        sigaddset(&m_sigset, SIGTERM);
        sigaddset(&m_sigset, SIGSEGV);

        int signum;
        sigprocmask(SIG_BLOCK, &m_sigset, NULL);

        sigwait(&m_sigset, &signum);
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what();
    }
    return 0;
}