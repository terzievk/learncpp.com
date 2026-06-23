#include <iostream>

enum class MonsterType {
  ogre,
  dragon,
  orc,
  giantSpider,
  slime
};

struct Monster {
  MonsterType type{};
  std::string name{};
  int health{};
};

void print(const Monster& monster) {
  std::cout << "This ";

  using enum MonsterType;

  switch(monster.type) {
  case ogre:
    std::cout << "Ogre";
    break;
  case dragon:
    std::cout << "Dragon";
    break;
  case orc:
    std::cout << "Orc";
    break;
  case giantSpider:
    std::cout << "Giant spider";
    break;
  case slime: std::cout << "Ogre";
    break;
  }

  std::cout << " is named " << monster.name << " and has "
  << monster.health << " health.\n";
}

int main() {
  Monster a {.type{0}, .name{"Torg"}, .health{145}};
  Monster b {MonsterType::slime, "Blurp", 23};

  print(a);
  print(b);
  return 0;
}
