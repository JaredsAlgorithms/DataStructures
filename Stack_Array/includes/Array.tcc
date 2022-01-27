namespace MyStaticArray {
  template <typename T, size_t S>
  Array<T, S>::Array(std::initializer_list<T> l) {
    if (l.size() > S) {
      throw std::bad_array_new_length();
    }

    typename std::initializer_list<T>::iterator it = std::begin(l);
    size_t i = 0;

    while(it != std::end(l)) {
      this->m_Data[i++] = *it++;
    }

    while(i < S) {
      this->m_Data[i++] = 0;
    }
  }
  template <typename T, size_t S>
  size_t Array<T, S>::size() const {
    return S;
  }

  template <typename T, size_t S>
  T& Array<T, S>::operator[](size_t i) {
    return this->m_Data[i];
  }

  template <typename T, size_t S>
  T& Array<T, S>::operator[](size_t i) const {
    return this->m_Data[i];
  }

  template <typename T, size_t S>
  ArrayIterator<Array<T, S>> Array<T, S>::begin() {
    return ArrayIterator<Array<T, S>>(this->m_Data);
  }

  template <typename T, size_t S>
  ArrayIterator<Array<T, S>> Array<T, S>::end() {
    return ArrayIterator<Array<T, S>>(this->m_Data + S);
  }
};  // namespace MyStaticArray
