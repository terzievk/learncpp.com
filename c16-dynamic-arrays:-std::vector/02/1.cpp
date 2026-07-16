#include <iostream>
#include <vector>

int main() {
  std::vector v{1, 4, 9, 16, 25};

  for (const auto &e : v) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}
