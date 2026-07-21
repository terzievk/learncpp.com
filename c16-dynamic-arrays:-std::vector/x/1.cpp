#include <iostream>
#include <string_view>
#include <vector>

int main() {
  // a
  std::vector even {0, 2, 4, 6, 8, 10};

  // b
  const std::vector nums{1.2, 3.4, 5.6, 7.8};

  // c
  const std::vector<std::string_view> names {"Alex", "Brad", "Charles", "Dave"};

  // d
  std::vector single{12};

  // e
  std::vector<int> dozen(12);
}
