#include <iostream>

namespace Monster {
  enum MonsterType {
    orc,
    goblin,
    troll,
    ogre,
    skeleton
  };
}

int main() {
  Monster::MonsterType m{Monster::orc};

  std::cout << (m == Monster::orc) << '\n';

  return 0;
}
