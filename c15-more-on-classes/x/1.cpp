#include "Random.h"

#include <iostream>

class Monster {
public:
  enum Type {
    dragon,
    goblin,
    ogre,
    orc,
    skeleton,
    troll,
    vampire,
    zombie,
    maxMonsterTypes
  };

private:
  Type type {};
  std::string name {};
  std::string roar {};
  int nHitPoints {};

public:
  Monster(Type t, std::string_view n, std::string_view r, int nhp) :
    type{t}, name{n}, roar{r}, nHitPoints{nhp} {}

  constexpr std::string_view getTypeString() const {
    switch (type) {
    case dragon:   return "dragon";
    case goblin:   return "goblin";
    case ogre:     return "ogre";
    case orc:      return "orc";
    case skeleton: return "skeleton";
    case troll:    return "troll";
    case vampire:  return "vampire";
    case zombie:   return "zombie";
    default: return "???";
    }
  }

  void print() const {
    std::cout << name << " the " << getTypeString() << " has " << nHitPoints
    << " hit points and says " << roar << ".\n";
  }
};

namespace MonsterGenerator {
  constexpr std::string_view getName(int i) {
    switch(i) {
    case 0: return "Ivancho";
    case 1: return "Mariika";
    case 2: return "Goshko";
    case 3: return "Petarcho";
    case 4: return "Nikola";
    case 5: return "Nikoleta";
    default : return "???";
    }
  }

  constexpr std::string_view getRoar(int i) {
    switch(i) {
    case 0: return "*skrrrrt*";
    case 1: return "*bip-bop*";
    case 2: return "*ke-pasa*";
    case 3: return "*auuuuuuuu*";
    case 4: return "*blahblahblah*";
    case 5: return "*oleoleole*";
    default : return "???";
    }
  }

  Monster generate() {
    return Monster {Monster::skeleton, getName(Random::get(0, 5)),
                    getRoar(Random::get(0, 5)), Random::get(1, 100)};
  }
}

int main() {
  Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
  skeleton.print();

  Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
  vampire.print();

  Monster m{ MonsterGenerator::generate() };
  m.print();

  return 0;
}
