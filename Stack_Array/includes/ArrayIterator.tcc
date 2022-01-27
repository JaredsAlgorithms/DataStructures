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
     * @return current class instance after moving the pointer
     */

    if (this->m_Ptr + 1 == nullptr) {
      throw std::overflow_error(
          "cannot increment pointer further, exceeds confines of the array");
    }
    this->m_Ptr++;
    return *this;
  }

  template <typename Array>
  ArrayIterator<Array>& ArrayIterator<Array>::operator--() {
    this->m_Ptr--;
    return *this;
  }

  template <typename Array>
  ArrayIterator<Array>& ArrayIterator<Array>::operator--(
      ArrayIterator<Array>::ValueType) {
    ArrayIterator _it = *this;
    --(*this);
    return _it;
  }

  template <typename Array>
  ArrayIterator<Array>& ArrayIterator<Array>::operator++(
      ArrayIterator<Array>::ValueType) {
    ArrayIterator _it = *this;
    ++(*this);
    return _it;
  }

  template <typename Array>
  typename ArrayIterator<Array>::ReferenceType ArrayIterator<Array>::operator[](
      size_t index) {
    return *(this->m_Ptr + index);
  }

  template <typename Array>
  typename ArrayIterator<Array>::PointerType
  ArrayIterator<Array>::operator->() {
    return this->m_Ptr;
  }
  template <typename Array>
  typename ArrayIterator<Array>::ReferenceType
  ArrayIterator<Array>::operator*() {
    return *(this->m_Ptr);
  }

  template <typename Array>
  bool ArrayIterator<Array>::operator==(const ArrayIterator<Array>& rhs) const {
    return this->m_Ptr == rhs.m_Ptr;
  }

  template <typename Array>
  bool ArrayIterator<Array>::operator!=(const ArrayIterator<Array>& rhs) const {
    return !ArrayIterator<Array>::operator==(rhs);
  }
};  // namespace MyStaticArray
