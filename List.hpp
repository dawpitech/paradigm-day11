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

        // ReSharper disable once CppClassCanBeFinal
        class InvalidIteratorException : std::exception {};

        class Iterator
        {
            public:
                explicit Iterator(const List& list, std::size_t idx = 0);
                ~Iterator() = default;
                IObject* operator*() const;
                Iterator& operator++();
                bool operator==(const Iterator& it) const;
                bool operator!=(const Iterator& it) const;

                // ReSharper disable once CppClassCanBeFinal
                class OutOfRangeException : std::exception {};

                std::size_t getIdx() const { return this->_idx; }
                bool isOnTheSameList(const List* list) const { return list == &this->_list ? true : false; }
            protected:
                const List& _list;
                std::size_t _idx;
        };

        Iterator begin() const;
        Iterator end() const;
        Iterator erase(Iterator it);
        Iterator insert(Iterator it, IObject* obj);

    protected:
        std::list<IObject*> _list;
};
#endif //LIST_HPP
