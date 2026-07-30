#include <array>
#include <iostream>
#include <optional>
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
  int getPotion(Potion::Type p) const { return inventory[p]; }

  bool buyPotion(Potion::Type p) {
    int cost {Potion::costs[p]};

    if (gold >= cost) {
      gold -= cost;
      ++inventory[p];
      return true;
    }

    return false;
  }
};

void shop() {
  std::cout << "Here is our selection for today:\n";

  for (auto p : Potion::potions) {
    std::cout << p << ") " << Potion::names[p] << " costs " << Potion::costs[p] << '\n';
  }
}

void ignoreLine();
bool clearFailedExtraction();
int charToInt(char c) { return c - '0'; }

std::optional<Potion::Type> getPotion() {
  std::cout << '\n';
  shop();

  std::string_view message {
    "Enter the number of potion you'd like to buy, ro 'q' to quit: "};

  while (true) {
    std::cout << message;
    message = "That is invalid input. Try again: ";

    char c{};
    std::cin >> c;

    if (clearFailedExtraction()) {
      continue;
    }

    ignoreLine(); // Remove any extraneous input

    if (c == 'q') {
      return {};
    }

    for (auto potion : Potion::potions) {
      if (potion == charToInt(c)) {
        return potion;
      }
    }
  }
}

int main() {
  std::cout << "Welcome to Roscoe's potion emporium!\n";
  std::cout << "Enter your name: ";

  std::string name;
  std::getline(std::cin >> std::ws, name);

  Player player{name};

  std::cout << "Hello, "
  << player.getName() << ", you have " << player.getGold() << " gold.\n";

  auto potion {getPotion()};
  while (potion) {
    if (player.buyPotion(*potion)) {
      std::cout << "You purchased a potion of " << Potion::names[*potion] << ".\n"
      << "You have " << player.getGold() << " gold left.\n";
    } else {
      std::cout << "You can not afford that.\n";
    }

    potion = getPotion();
  }

  std::cout << "\nYour inventory contains:\n";
  for (auto p : Potion::potions) {
    int count {player.getPotion(p)};
    if (count) {
      std::cout << count << "x potion of " << Potion::names[p] << '\n';
    }
  }
  std::cout << "You escaped with " << player.getGold() << " remaining.\n";

  std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
}

// learncpp.com Ch. 9.5
void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// learncpp.com Ch. 9.5
// returns true if extraction failed, false otherwise
bool clearFailedExtraction() {
  if (!std::cin) {
    if (std::cin.eof()) {    // If the stream was closed
      std::exit(0);  // Shut down the program now
    }

    // Let's handle the failure
    std::cin.clear();  // Put us back in 'normal' operation mode
    ignoreLine();      // And remove the bad input

    return true;
  }

  return false;
}
