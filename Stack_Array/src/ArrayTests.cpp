#include "../includes/ArrayTests.hpp"
#include <cassert>
#include <stdexcept>
#include "../includes/Array.hpp"

void ArrayTestSuite::test_initializer_list() {
  /*
   * Make sure we can initialize an array using an initializer list
   * and compare it with a std::array using the same constructor
   */

  MyStaticArray::Array<int, 5> arr{1, 2, 3, 4, 5};
  std::array<int, 5> std_arr{1, 2, 3, 4, 5};

  assert(arr == std_arr);
}

void ArrayTestSuite::test_incrementing_iterator() {
  using namespace MyStaticArray;

  bool caught_exception = false;

  Array<int, 5> arr{1, 2, 3, 4, 5};
  ArrayIterator<Array<int, 5>> iter = std::end(arr);
  for (int element : arr) {
    // Check if we can use a range based for loop
    continue;
  }

  try {
    ++iter;
  } catch (std::overflow_error e) {
    caught_exception = true;
  }

  if (caught_exception) {
    std::cout << "successfully caught the out_of_range exception" << std::endl;
  } else {
    assert(true == false);
  }
  iter = std::begin(arr);
  assert(*iter++ == 1);
  assert(*++iter == 3);
}
