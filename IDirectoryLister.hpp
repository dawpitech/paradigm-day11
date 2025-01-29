/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** IDirectoryLister.hpp
*/

#ifndef IDIRECTORYLISTER_HPP
    #define IDIRECTORYLISTER_HPP

    #include <string>

class IDirectoryLister
{
    public:
        virtual ~IDirectoryLister() = default;
        virtual bool open(const std::string& path, bool hidden) = 0;
        virtual std::string get() = 0;
};
#endif //IDIRECTORYLISTER_HPP
