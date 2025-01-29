/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** IDirectoryLister.cpp
*/

#include <cstring>

#include "IDirectoryLister.hpp"

const char* IDirectoryLister::OpenFailureException::what() const noexcept
{
    return strerror(errno);
}

const char* IDirectoryLister::NoMoreFileException::what() const noexcept
{
    return "End of stream";
}
