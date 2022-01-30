#include <iostream>

#include <vector>
#include "../includes/Array.hpp"
#include "../includes/ArrayTests.hpp"

int main() {
  ArrayTestSuite suite = ArrayTestSuite();
  suite.conduct_all();

  return 0;
}
