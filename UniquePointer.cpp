/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** UniquePointer.cpp
*/

#include "UniquePointer.hpp"

UniquePointer::UniquePointer(IObject* object)
{
    this->_object = object;
}

UniquePointer& UniquePointer::operator=(IObject* object)
{
    delete this->_object;
    this->_object = object;
    return *this;
}

IObject* UniquePointer::operator->() const
{
    return this->_object;
}

IObject& UniquePointer::operator*() const
{
    return *this->_object;
}

void UniquePointer::reset()
{
    this->reset(nullptr);
}

void UniquePointer::reset(IObject* object)
{
    delete this->_object;
    this->_object = object;
}

void UniquePointer::swap(UniquePointer& ptr) noexcept
{
    const auto ptrObject = ptr._object;
    ptr._object = this->_object;
    this->_object = ptrObject;
}
