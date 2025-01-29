/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** DirectoryLister.cpp
*/

#include <iostream>

#include "DirectoryLister.hpp"

DirectoryLister::~DirectoryLister()
{
    if (this->_dir != nullptr && closedir(this->_dir) == -1) { perror(nullptr); }
}

DirectoryLister::DirectoryLister(const std::string& path, const bool hidden)
{
    this->DirectoryLister::open(path, hidden);
}

bool DirectoryLister::open(const std::string& path, const bool hidden)
{
    if (this->_dir != nullptr && closedir(this->_dir) == -1) { perror(nullptr); }
    DIR* dir = opendir(path.c_str());
    if (dir == nullptr) {
        perror(path.c_str());
        this->_dir = nullptr;
        return false;
    }
    this->_dir = dir;
    this->_showHiddenFiles = hidden;
    return true;
}

std::string DirectoryLister::get()
{
    if (this->_dir == nullptr)
        return {};
    dirent* f_dirent = readdir(this->_dir);
    while (f_dirent != nullptr &&
        (this->_showHiddenFiles ? false : f_dirent->d_name[0] == '.')) {
        f_dirent = readdir(this->_dir);
    }
    if (f_dirent == nullptr)
        return {};
    return {f_dirent->d_name};
}
