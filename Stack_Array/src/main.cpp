#include <iostream>

#include <vector>
#include "../includes/Array.hpp"

int main() {
  MyStaticArray::Array<int, 5> arr{1, 2, 3};
  for(int element : arr ) {
    std::cout << element << std::endl;
  }
  return 0;
}
