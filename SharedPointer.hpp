/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** SharedPointer.hpp
*/

#ifndef SHAREDPOINTER_HPP
    #define SHAREDPOINTER_HPP

    #include <unordered_map>

    #include "IObject.hpp"

class SharedPointer
{
    public:
        SharedPointer();
        SharedPointer(IObject* object);
        SharedPointer(const SharedPointer& sp);
        ~SharedPointer();

        SharedPointer& operator=(IObject* object);
        SharedPointer& operator=(const SharedPointer& sp);
        IObject* operator->() const;
        IObject& operator*() const;

        void reset();
        void reset(IObject* object);
        void swap(SharedPointer& ptr) noexcept;
        unsigned int use_count() const;

    protected:
        IObject* _object = nullptr;
        unsigned int* _count = new unsigned int;
};
#endif //SHAREDPOINTER_HPP
