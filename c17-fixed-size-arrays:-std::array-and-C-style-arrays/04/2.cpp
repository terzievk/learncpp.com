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
  // either works
  constexpr std::array<Item, 4> arr {{
    {"sword", 5},
    {"dagger", 3},
    {"club", 2},
    {"spear", 7}
  }};

  // constexpr std::array<Item, 4> arr {
  //   "sword", 5,
  //   "dagger", 3,
  //   "club", 2,
  //   "spear", 7
  // };

  print(arr);
}
