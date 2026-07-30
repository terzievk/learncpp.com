#include <array>
#include <iostream>

namespace Potion {
  enum Type {
    healing,
    mana,
    speed,
    invisibility,
    potions_count
  };

  constexpr std::array potions{healing, mana, speed, invisibility};
  constexpr std::array costs{20, 30, 12, 50};

  using namespace std::string_view_literals;
  constexpr std::array names{"healing"sv, "mana"sv, "speed"sv, "invisibility"sv};

  static_assert(std::size(potions) == potions_count);
  static_assert(std::size(costs) == potions_count);
  static_assert(std::size(names) == potions_count);
}

void shop() {
  std::cout << "Here is our selection for today:\n";

  for (auto p : Potion::potions) {
    std::cout << p << ") " << Potion::names[p] << " costs " << Potion::costs[p] << '\n';
  }
}

int main() {
  shop();
}
