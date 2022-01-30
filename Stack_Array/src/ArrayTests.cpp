#include "../includes/ArrayTests.hpp"
#include <cassert>
#include <stdexcept>
#include "../includes/Array.hpp"

void ArrayTestSuite::conduct_all() {
  this->test_initializer_list();
  this->test_incrementing_iterator();
  this->test_decrementing_iterator();
}

void ArrayTestSuite::test_initializer_list() {
  /*
   * Make sure we can initialize an array using an initializer list
   * and compare it with a std::array using the same constructor
   */

  bool caught_exception = false;

  MyStaticArray::Array<int, 5> arr{1, 2, 3, 4, 5};
  std::array<int, 5> std_arr{1, 2, 3, 4, 5};

  assert(arr == std_arr);

  try {
    MyStaticArray::Array<int, 1> a{1, 1, 2};
  } catch (std::bad_array_new_length& e) {
    caught_exception = true;
  }
  if (caught_exception) {
    std::cout << "[PASSED] Unequal length initializer list attempted and caught"
              << std::endl;
  } else {
    assert(true == false);
  }
}

void ArrayTestSuite::test_incrementing_iterator() {
  /*
   * Test all the cases where the iterator can fail
   */

  using namespace MyStaticArray;

  bool caught_exception = false;

  Array<int, 5> arr{1, 2, 3, 4, 5};
  ArrayIterator<Array<int, 5>> iter = std::end(arr);

  for (int element : arr) {
    // Check if we can use a range based for loop
    std::cout << element << std::endl;
    continue;
  }

  std::cout << "DIRECTION" << std::endl;

  std::cout << iter.direction << std::endl;

  try {
    ++iter;
  } catch (std::overflow_error e) {
    caught_exception = true;
  }

  return;

  if (caught_exception) {
    std::cout
        << "[PASSED] Iterator attempted to exceed the confines of the array"
        << std::endl;
  } else {
    assert(true == false);
  }
  iter = std::begin(arr);
  assert(*iter++ == 1);
  assert(++*iter == 3);
  assert(*++iter ==
         3);  // since we move where the * is, it appears that value hops one
}

void ArrayTestSuite::test_decrementing_iterator() {
  /*
   * Test all the cases where the iterator can fail
   * This does not take into account a reverse iterator, therefore
   * the range based for loop does not work here.
   * Nor would the idea from running from the back to the front
   * We will use a while loop to go backwards until the beginning of the
   * container
   */

  using namespace MyStaticArray;

  bool caught_exception = false;

  Array<int, 5> arr{1, 2, 3, 4, 5};
  ArrayIterator<Array<int, 5>> iter = std::end(arr);  // FIXME

  while (iter != std::begin(arr)) {
    std::cout << *iter << std::endl;
    --iter;
  }

  // reset the iterator
  ArrayIterator<Array<int, 5>> new_iter = std::end(arr);
  // assert(*iter-- == 5);
  // assert(--*iter == 4);
  // assert(*--iter == 4);
}
