/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** DirectoryLister.hpp
*/

#ifndef DIRECTORYLISTER_HPP
    #define DIRECTORYLISTER_HPP

    #include <dirent.h>

    #include "IDirectoryLister.hpp"

// ReSharper disable once CppClassCanBeFinal
class DirectoryLister : public IDirectoryLister
{
    public:
        explicit DirectoryLister() = default;
        DirectoryLister(const std::string& path, bool hidden);
        ~DirectoryLister() override;
        bool open(const std::string& path, bool hidden) override;
        std::string get() override;

    protected:
        DIR* _dir = nullptr;
        bool _showHiddenFiles = false;
};
#endif //DIRECTORYLISTER_HPP
