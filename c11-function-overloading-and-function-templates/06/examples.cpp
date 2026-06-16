#include <iostream>

template <typename T>
T max(T x, T y) {
  return x < y ? y : x;
}

int main() {
  std::cout << max(2, 3) << '\n';
  std::cout << max(2.9, 3.2) << '\n';
  std::cout << max(2.9, double{3}) << '\n';
  return 0;
}
