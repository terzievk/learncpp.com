#include <iostream>

int fact(int n) {
  if (n == 0) {
    return 1;
  }

  return n * fact(n - 1);
}

int main() {
  for (auto i{0}; i < 7; ++i) {
    std::cout << fact(i) << ' ';
  }
  std::cout << '\n';
}
