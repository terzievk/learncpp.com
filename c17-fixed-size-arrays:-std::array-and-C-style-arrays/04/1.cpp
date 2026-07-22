#include <iostream>
#include <string_view>
#include <array>

struct Item {
  std::string_view name{};
  int gold {};
};

template <typename T, auto N>
void print(const std::array<T, N> &arr) {
  for (const Item &item : arr) {
    std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
  }
}

int main() {
  constexpr std::array arr {
    Item{"sword", 5},
    Item{"dagger", 3},
    Item{"club", 2},
    Item{"spear", 7}
  };

  print(arr);
}
