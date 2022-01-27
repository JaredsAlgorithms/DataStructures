#pragma once

#include <iostream>
#include <initializer_list>

namespace MyStaticArray {

  template <typename Array>
  class ArrayIterator {
   public:
    using ValueType = typename Array::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

   public:
    ArrayIterator(PointerType ptr) : m_Ptr(ptr) {}
    ArrayIterator& operator++();
    ArrayIterator& operator--();

    ArrayIterator& operator++(ValueType);
    ArrayIterator& operator--(ValueType);

    ReferenceType operator[](size_t);
    ReferenceType operator*();

    PointerType operator->();

    bool operator==(const ArrayIterator&) const;
    bool operator!=(const ArrayIterator&) const;

   private:
    PointerType m_Ptr;
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
    Iterator begin();
    Iterator end();

   private:
    T m_Data[S];
  };
}  // namespace MyStaticArray
#include "Array.tcc"
#include "ArrayIterator.tcc"
