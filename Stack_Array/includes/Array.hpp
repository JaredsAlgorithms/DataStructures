#pragma once

#include <initializer_list>
#include <iostream>
#include <array>

namespace MyStaticArray {

  template <typename Array>
  class ArrayIterator {
   public:
    using ValueType = typename Array::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

   public:
    ArrayIterator(PointerType base, PointerType ptr, int threshold)
        : m_Ptr(base), m_Ptr_Base(ptr), m_Upper_Bound(threshold) {}
    ArrayIterator& operator++();
    ArrayIterator& operator--();

    ArrayIterator& operator++(ValueType);
    ArrayIterator& operator--(ValueType);

    ReferenceType operator[](size_t);
    ReferenceType operator*();

    PointerType operator->();

    bool operator==(const ArrayIterator&) const;
    bool operator!=(const ArrayIterator&) const;

    size_t distance() const;

   private:
    PointerType m_Ptr;  // where the current position is
    PointerType
        m_Ptr_Base;     // where the array starts upon creation of the iterator
    size_t m_Upper_Bound;  // what is out theoretical maxima
  };

  template <typename T, size_t S>
  class Array {
   public:
    using ValueType = T;
    using Iterator = ArrayIterator<Array<T, S>>;

    Array(std::initializer_list<T>);

    size_t size() const;
    T& operator[](size_t i);
    T& operator[](size_t i) const;

    bool operator==(const std::array<T, S>&) const;
    bool operator!=(const std::array<T, S>&) const;

    Iterator begin();
    Iterator end();

   private:
    T m_Data[S];
  };
}  // namespace MyStaticArray
#include "Array.tcc"
#include "ArrayIterator.tcc"
