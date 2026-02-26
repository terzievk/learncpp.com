// copyright
#include <iostream>

int main() {
  [[maybe_unused]] double pi {3.141592};  // Don't complain if pi is unused
  [[maybe_unused]] double gravity {9.8};  // Don't complain if gravity is unused
  [[maybe_unused]] double phi {1.61803};  // Don't complain if phi is unused

  std::cout << pi << std::endl;

  return 0;
}
