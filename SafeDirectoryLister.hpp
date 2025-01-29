/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** SafeDirectoryLister.hpp
*/

#ifndef SAFEDIRECTORYLISTER_HPP
    #define SAFEDIRECTORYLISTER_HPP

    #include <dirent.h>

    #include "IDirectoryLister.hpp"

// ReSharper disable once CppClassCanBeFinal
class SafeDirectoryLister : public IDirectoryLister
{
public:
    explicit SafeDirectoryLister() = default;
    SafeDirectoryLister(const std::string& path, bool hidden);
    ~SafeDirectoryLister() override;
    bool open(const std::string& path, bool hidden) override;
    std::string get() override;

protected:
    DIR* _dir = nullptr;
    bool _showHiddenFiles = false;
};
#endif //SAFEDIRECTORYLISTER_HPP
