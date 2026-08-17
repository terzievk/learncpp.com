#include "Direction.h"

#include <cassert>
#include <utility>

#include "Random.h"

Direction Direction::operator-() {
  switch (this->direction) {
    case up:
      return Direction{down};
    case down:
      return Direction{up};
    case left:
      return Direction{right};
    case right:
      return Direction{left};
    default:
      std::unreachable();
  }
}

Direction Direction::getRandom() {
  return allDirections[Random::get(0uz,
                                   static_cast<size_t>(maxDirections) - 1)];
}

std::ostream& operator<<(std::ostream& out, const Direction& d) {
  return out << d.directions[d.direction];
}
