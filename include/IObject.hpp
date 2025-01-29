/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Day 11
*/

#pragma once

#include <iostream>

class IObject
{
    public:
        virtual ~IObject() = default;

        virtual void touch() = 0;
};

//TODO: remove TestObject class
class TestObject final : public IObject
{
    public:
        explicit TestObject(std::string name)
        {
            this->_name = name;
            std::cout << this->_name  << " is alive" << std::endl;
        }
        ~TestObject() override
        {
            std::cout << this->_name << " is dead" << std::endl;
        }
        void touch() override
        {
            std::cout << this->_name << " is touched" << std::endl;
        }

    protected:
        std::string _name;
};
