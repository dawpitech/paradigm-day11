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
    delete this->_list.front();
    return this->_list.pop_front();
}

void List::popBack()
{
    if (this->empty())
        throw InvalidOperationException();
    delete this->_list.back();
    return this->_list.pop_back();
}

void List::clear()
{
    while (!this->empty()) { this->popFront(); }
}

void List::forEach(void (*function)(IObject*))
{
    for (const auto elem : this->_list) { function(elem); }
}

List::Iterator List::begin() const
{
    return Iterator(*this, 0);
}

List::Iterator List::end() const
{
    return Iterator(*this, this->_list.size());
}

List::Iterator List::erase(const Iterator it)
{
    if (it.getIdx() > this->_list.size() || !it.isOnTheSameList(this))
        throw InvalidIteratorException();
    delete *std::next(this->_list.begin(), static_cast<int>(it.getIdx()));
    this->_list.erase(
        std::next(this->_list.begin(),
            static_cast<int>(it.getIdx())));
    return it;
}

List::Iterator List::insert(Iterator it, IObject* obj)
{
    if (it.getIdx() > this->_list.size() || !it.isOnTheSameList(this))
        throw InvalidIteratorException();
    this->_list.insert(
        std::next(this->_list.begin(),
            static_cast<int>(it.getIdx())), obj);
    return ++it;
}

List::Iterator::Iterator(const List& list, const std::size_t idx)
    : _list(list), _idx(idx) {}

IObject* List::Iterator::operator*() const
{
    if (_idx > this->_list.size())
        throw OutOfRangeException();
    return *std::next(this->_list._list.begin(), static_cast<int>(this->_idx));
}

List::Iterator& List::Iterator::operator++()
{
    this->_idx += 1;
    return *this;
}

bool List::Iterator::operator==(const Iterator& it) const
{
    return &this->_list == &it._list && this->_idx == it._idx;
}

bool List::Iterator::operator!=(const Iterator& it) const
{
    return !operator==(it);
}
