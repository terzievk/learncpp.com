#include <iostream>

int main() {
  int s { -1 };
  std::cout << static_cast<unsigned int>(s) << '\n'; // prints 4294967295

  unsigned int u { 4294967295 }; // largest 32-bit unsigned int
  std::cout << static_cast<int>(u) << '\n'; // implementation-defined prior to C++20, -1 as of C++20

  return 0;
}
