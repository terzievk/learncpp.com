#include <iostream>
#include <vector>

int main() {
  std::vector arr{ 9, 7, 5, 3, 1 };

  auto length {std::ssize(arr)};  // in C++20, prefer std::ssize()
  for (auto index{ length - 1 }; index >= 0; --index)
    std::cout << arr.data()[index] << ' ';       // use data() to avoid sign conversion warning

  return 0;
}
