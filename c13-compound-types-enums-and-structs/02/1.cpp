#include <iostream>

enum MonsterType {
  orc,
  goblin,
  troll,
  ogre,
  skeleton
};

int main() {
  MonsterType m{orc};

  std::cout << (m == orc) << '\n';

  return 0;
}
