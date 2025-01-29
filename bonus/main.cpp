/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** main.cpp
*/

#include <iostream>

#include "DirectoryLister.hpp"

#include "SafeDirectoryLister.hpp"

void myLs(const std::string& directory)
{
    try
    {
        SafeDirectoryLister dl(directory, false);
        std::cout << directory << ":" << std::endl;
        for (std::string file = dl.get(); true; file = dl.get())
            std::cout << file << std::endl;
    }
    catch (const IDirectoryLister::NoMoreFileException& e)
    {
        return;
    }
    throw std::runtime_error(" should not happen ");
}

int main_ex01()
{
    try
    {
        myLs("./bonus/testdir/");
        myLs("./not_exist/");
        myLs("./bonus/testdir/");
    }
    catch (const IDirectoryLister::OpenFailureException& e)
    {
        std::cerr << "failure: " << e.what() << std::endl;
    } catch (const std::exception& e)
    {
        std::cerr << "unexpected error: " << e.what() << std::endl;
    }
    return 0;
}

int main_ex00()
{
    DirectoryLister dl("./bonus/testdir/", true);
    for (std::string file = dl.get(); !file.empty(); file = dl.get())
        std::cout << file << std::endl;
    dl.open("invalid path", true);
    if (dl.open("./bonus/testdir/", false) == true)
        for (std::string file = dl.get(); !file.empty(); file = dl.get())
            std::cout << file << std::endl;
    return 0;
}

int main()
{
    //return main_ex00();
    return main_ex01();
}
