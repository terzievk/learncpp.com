#include <iostream>

int main() {
  int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

  auto size{std::size(array)};

  for (auto i{0uz}; i < size - 1; ++i) {
    bool swaped{false};

    for (auto j{0uz}; j < size - 1 - i; ++j) {
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
        swaped = true;
      }
    }

    if (!swaped) {
      break;
    }
  }

  for (auto x : array) {
    std::cout << x << ' ';
  }

  std::cout << '\n';
}
