/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** List.cpp
*/

#include "List.hpp"

List::~List()
{
    this->clear();
}

IObject*& List::front()
{
    if (this->empty())
        throw InvalidOperationException();
    return this->_list.front();
}

IObject* List::front() const
{
    if (this->empty())
        throw InvalidOperationException();
    return this->_list.front();
}

IObject*& List::back()
{
    if (this->empty())
        throw InvalidOperationException();
    return this->_list.back();
}

IObject* List::back() const
{
    if (this->empty())
        throw InvalidOperationException();
    return this->_list.back();
}

void List::popFront()
{
    if (this->empty())
        throw InvalidOperationException();
    return this->_list.pop_front();
}

void List::popBack()
{
    if (this->empty())
        throw InvalidOperationException();
    return this->_list.pop_back();
}

void List::clear()
{
    while (!this->empty()) {
        const auto elem = this->front();
        this->popFront();
        delete elem;
    }
}

void List::forEach(void (*function)(IObject*))
{
    for (const auto elem : this->_list) { function(elem); }
}
