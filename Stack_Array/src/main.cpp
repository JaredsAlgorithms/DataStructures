#include <iostream>

#include <vector>
#include "../includes/Array.hpp"
#include "../includes/ArrayTests.hpp"

int main() {
  ArrayTestSuite suite = ArrayTestSuite();
  suite.test_initializer_list();
  suite.test_incrementing_iterator();

  return 0;
}
