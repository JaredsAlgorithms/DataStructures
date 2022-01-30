#pragma once

#include <array>
#include <initializer_list>
#include <iostream>

namespace MyStaticArray {

  enum Direction { LEFT = 0, RIGHT = 1 };

  template <typename Array>
  class ArrayIterator {
   public:
    using ValueType = typename Array::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

   public:
    ArrayIterator(PointerType base,
                  PointerType ptr,
                  int threshold,
                  Direction _direction) {
      this->m_Ptr_Base = base;
      this->m_Ptr = ptr;
      this->m_Upper_Bound = threshold;
      this->direction = _direction;
    }
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

    Direction direction;

   private:
    PointerType m_Ptr;  // where the current position is
    PointerType
        m_Ptr_Base;  // where the array starts upon creation of the iterator
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
