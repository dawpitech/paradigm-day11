/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** SharedPointer.cpp
*/

#include "SharedPointer.hpp"

SharedPointer::SharedPointer()
{
    *this->_count += 1;
}

SharedPointer::SharedPointer(IObject* object)
{
    this->_object = object;
    *this->_count += 1;
}

SharedPointer::SharedPointer(const SharedPointer& sp)
{
    this->_object = sp._object;
    this->_count = sp._count;
    *this->_count += 1;
}

SharedPointer::~SharedPointer()
{
    delete this->_object;
    *this->_count -= 1;
}

SharedPointer& SharedPointer::operator=(IObject* object)
{
    *this->_count -= 1;
    if (*this->_count == 0)
        delete this->_object;
    this->_object = object;
    this->_count = new unsigned int;
    *this->_count += 1;
    return *this;
}

SharedPointer& SharedPointer::operator=(const SharedPointer& sp)
{
    *this->_count -= 1;
    if (*this->_count == 0)
        delete this->_object;
    this->_object = sp._object;
    this->_count = sp._count;
    *this->_count += 1;
    return *this;
}

IObject* SharedPointer::operator->() const
{
    return this->_object;
}

IObject& SharedPointer::operator*() const
{
    return *this->_object;
}

void SharedPointer::reset()
{
    this->reset(nullptr);
}

void SharedPointer::reset(IObject* object)
{
    *this->_count -= 1;
    if (*this->_count == 0)
        delete this->_object;
    this->_object = object;
    this->_count = new unsigned int;
    *this->_count += 1;
}

void SharedPointer::swap(SharedPointer& ptr) noexcept
{
    const auto ptrObject = ptr._object;
    const auto ptrCount = ptr._count;
    ptr._object = this->_object;
    ptr._count = this->_count;
    this->_object = ptrObject;
    this->_count = ptrCount;
}

unsigned int SharedPointer::use_count() const
{
    if (this->_object == nullptr)
        return 0;
    return *this->_count;
}
