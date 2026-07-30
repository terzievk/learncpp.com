#include <array>
#include <iostream>
#include <string>

#include "Random.h"

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

class Player {
  static constexpr int minGold{80};
  static constexpr int maxGold{120};
  std::string name{};
  std::array<int, Potion::Type::potions_count> inventory{};
  int gold{};

public:
  Player(std::string_view name)
  : name{name}, gold{Random::get(minGold, maxGold)} {}

  int getGold() const { return gold; }
  std::string_view getName() const { return name; }
};

void shop() {
  std::cout << "Here is our selection for today:\n";

  for (auto p : Potion::potions) {
    std::cout << p << ") " << Potion::names[p] << " costs " << Potion::costs[p] << '\n';
  }
}

int main() {
  std::cout << "Welcome to Roscoe's potion emporium!\n";
  std::cout << "Enter your name: ";

  std::string name;
  std::getline(std::cin >> std::ws, name);

  Player player{name};

  std::cout << "Hello, "
  << player.getName() << ", you have " << player.getGold() << " gold.\n\n";

  shop();

  std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
}
