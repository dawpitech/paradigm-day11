/*
** EPITECH PROJECT, 2025
** paradigm-day11
** File description:
** UniquePointer.hpp
*/

#ifndef UNIQUEPOINTER_HPP
    #define UNIQUEPOINTER_HPP

    #include "IObject.hpp"

class UniquePointer
{
    public:
        UniquePointer() = default;
        UniquePointer(IObject* object);
        UniquePointer(UniquePointer& _) = delete;
        ~UniquePointer() { delete this->_object; }

        UniquePointer& operator=(IObject* object);
        UniquePointer& operator=(UniquePointer& _) = delete;
        IObject* operator->() const;
        IObject& operator*() const;

        void reset();
        void reset(IObject* object);
        void swap(UniquePointer& ptr) noexcept;
    protected:
        IObject* _object = nullptr;
};
#endif //UNIQUEPOINTER_HPP
