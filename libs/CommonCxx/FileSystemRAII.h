#pragma once

#include <filesystem>

namespace Common
{
    class FileSystemRAII
    {
    public:
        FileSystemRAII(std::filesystem::path newPath) :
            m_newPath(newPath)
        {
            std::filesystem::current_path(m_newPath);
        }

        std::filesystem::path GetCurrentPath()
        {
            return std::filesystem::current_path();
        }

    private:
        std::filesystem::path m_newPath;
    };

}