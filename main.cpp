#include <csignal>
#include <exception>
#include "TaskMgrSystem.h"

int main() 
{
    try
    {
        TaskMgrSystem taskMgrSystem;
        
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