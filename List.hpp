/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** List.hpp
*/

#ifndef LIST_HPP
    #define LIST_HPP

    #include <cstddef>
    #include <list>

#include "IObject.hpp"

class List
{
    public:
        ~List();
        bool empty() const { return this->_list.empty(); }
        std::size_t size() const { return this->_list.size(); }
        IObject*& front();
        IObject* front() const;
        IObject*& back();
        IObject* back() const;
        void pushBack(IObject* obj) { this->_list.push_back(obj); }
        void pushFront(IObject* obj) { this->_list.push_front(obj); }
        void popFront();
        void popBack();
        void clear();
        void forEach(void(*function)(IObject*));

        // ReSharper disable once CppClassCanBeFinal
        class InvalidOperationException : std::exception {};

    protected:
        std::list<IObject*> _list;
};
#endif //LIST_HPP
