#include <cassert>
#include <iostream>
#include <vector>

namespace Items {
  enum Items {
    health_potions,
    torches,
    arrows,
    max_items
  };

  std::vector count{1, 5, 10};

  int getTotal(const std::vector<int> &count) {
    int sum{};

    for (int x : count) {
      sum += x;
    }

    return sum;
  }

  void printTotal(const std::vector<int>& count) {
    int sum{getTotal(count)};

    if (sum == 1) {
      std::cout << "You have 1 total item\n";
      return;
    }

    std::cout << "You have " << sum << " total items\n";
  }

  std::string getName(auto item) {
    switch (item) {
    case health_potions:
      return "health potion"
             + std::string{count[health_potions] == 1 ? "" : "s"};
    case torches:
      return "torch"
             + std::string{ count[torches] == 1 ? "" : "es"};
    case arrows:
      return "arrow"
             + std::string{ count[arrows] == 1 ? "" : "s"};
    default: return "???";
    }
  }

  void printItems(const std::vector<int> &count) {
    for (auto i{0u}; i < count.size(); ++i) {
      std::cout << "You have " << count[i] << ' ' << getName(i) << '\n';
    }
  }
}

int main() {
  assert(Items::max_items == Items::count.size() && "mismatch");

  Items::printItems(Items::count);
  Items::printTotal(Items::count);
}
