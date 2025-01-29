/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** main.cpp
*/

#include <iostream>

#include "DirectoryLister.hpp"

int main()
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
