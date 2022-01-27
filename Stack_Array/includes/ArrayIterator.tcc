#include "Array.hpp"

namespace MyStaticArray {

  template <typename Array>
  ArrayIterator<Array>& ArrayIterator<Array>::operator++() {
    /*
     * Increment the pointer one position
     *
     * This is the postfix notation of an increment operation
     * Throws an exception if you attempt to breach the confines
     * of the array
     *
     * @return ArrayIterator incremented one step
     */

    if (this->distance() + 1 > this->m_Upper_Bound) {
      throw std::overflow_error(
          "cannot increment pointer further, exceeds confines of the array");
    }
    this->m_Ptr++;
    return *this;
  }

  template <typename Array>
  ArrayIterator<Array>& ArrayIterator<Array>::operator--() {
    /*
     * Decrement the pointer one position
     *
     * This is the postfix nottion of a decrement operation
     * Throws an exception if you attempt to read past the beginning of
     * the m_Data member
     *
     * @return ArrayIterator decremented one step
     */

    if (this->distance() == 0) {
      throw std::underflow_error(
          "cannot decrement pointer further, exceeds confines of the array");
    }
    --this->m_Ptr;
    return *this;
  }

  template <typename Array>
  ArrayIterator<Array>& ArrayIterator<Array>::operator--(
      ArrayIterator<Array>::ValueType) {
    /*
     * Decrement the pointer one position
     *
     * This is the infix nottion of a decrement operation
     * Create a copy of the current iterator, decrement the current instance and
     * return the copy
     * Throws an exception if you attempt to read past the
     * beginning of the m_Data member
     *
     * @return ArrayIterator decremented one step
     */

    if (this->distance() == 0) {
      // NOTE: This might be excessive, because we call --(*this) will already
      // check the distance

      throw std::underflow_error(
          "cannot decrement pointer further, exceeds confines of the array");
    }

    ArrayIterator _it = *this;
    --(*this);
    return _it;
  }

  template <typename Array>
  ArrayIterator<Array>& ArrayIterator<Array>::operator++(
      ArrayIterator<Array>::ValueType) {
    /*
     * Increment the pointer one position
     *
     * This is the infix nottion of a increment operation
     * Create a copy of the current iterator, increment the current instance and
     * return the copy
     * Throws an exception if you attempt to read past the
     * end of the m_Data member
     *
     * @return ArrayIterator decremented one step
     */

    if (this->distance() + 1 > this->m_Upper_Bound) {
      throw std::overflow_error(
          "cannot increment pointer, exceeds the confines of the array");
    }

    ArrayIterator _it = *this;
    ++(*this);
    return _it;
  }

  template <typename Array>
  typename ArrayIterator<Array>::ReferenceType ArrayIterator<Array>::operator[](
      size_t index) {
    /*
     * Obtain the current element at a specified address
     *
     * This is independent of where the current pointer is
     * If we used m_Ptr exclusively, we would constantly encounter memory
     * access errors
     *
     * Throw an exception if the index is out of range
     *
     * @return ReferenceType of an element in the Array
     */

    if (index < 0 || index > this->m_Upper_Bound) {
      throw std::out_of_range(
          "cannot access index, exceeds the confines of the array");
    }
    return *(this->m_Ptr_Base + index);
  }

  template <typename Array>
  typename ArrayIterator<Array>::PointerType
  ArrayIterator<Array>::operator->() {
    /*
     * Obtain the pointer of the itetator
     *
     * @return ArrayIterator<Array>::PointerType
    */

    return this->m_Ptr;
  }
  template <typename Array>
  typename ArrayIterator<Array>::ReferenceType
  ArrayIterator<Array>::operator*() {
    /*
     * Get the value of the pointer the iterator is at
     *
     * @return ArrayIterator<Array>::ReferenceType
    */

    return *(this->m_Ptr);
  }

  template <typename Array>
  bool ArrayIterator<Array>::operator==(const ArrayIterator<Array>& rhs) const {
    /*
     * Check if the value contained in both iterators are the same
     *
     * @return bool; true data is the same, false otherwise
    */

    return *(this->m_Ptr) == *(rhs.m_Ptr);
  }

  template <typename Array>
  bool ArrayIterator<Array>::operator!=(const ArrayIterator<Array>& rhs) const {
    /*
     * Check if the value contained in both iterators are not the same
     *
     * @return bool; false if the data is not the same, true otherwise
    */

    return !ArrayIterator<Array>::operator==(rhs);
  }

  template <typename Array>
  size_t ArrayIterator<Array>::distance() const {
    /*
     * Get the distance from the base pointer
     *
     * @return size_t representing the amount of spaces from the base address
     */
    return ((this->m_Ptr - this->m_Ptr_Base) /
            sizeof(ArrayIterator<Array>::ValueType));
  }
};  // namespace MyStaticArray
