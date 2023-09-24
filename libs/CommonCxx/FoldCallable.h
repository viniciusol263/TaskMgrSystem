#pragma once

#include <functional>
#include <memory>
#include <string>
#include <tuple>
#include <vector>
#include <variant>

class VirtualFoldCallable 
{
public:
    virtual ~VirtualFoldCallable() {};
    virtual std::string GetIdentifier() = 0;
    virtual void Execute() = 0;
};
using VirtualFoldCallablePtr = std::shared_ptr<VirtualFoldCallable>;

template<typename... Args>
class FoldCallable : public VirtualFoldCallable
{
public:
    FoldCallable(std::string identifier,std::function<void(Args... args)> callable) :
        m_identifier(identifier),
        m_callable(callable)
    {}

    std::string GetIdentifier() override
    {
        return m_identifier;
    }

    void Execute() override
    {
        // m_callable();
    }

private:
    std::string m_identifier;
    std::function<void(Args... args)> m_callable;
    std::tuple<Args...> m_args;
};
