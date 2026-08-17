#include "Point.h"

#include <cassert>
#include <cstdlib>
#include <utility>

#include "Direction.h"

Point Point::getAdjacentPoint(Direction direction) {
  switch (direction.getDirection()) {
    case Direction::up:
      return Point{x - 1, y};
    case Direction::down:
      return Point{x + 1, y};
    case Direction::left:
      return Point{x, y - 1};
    case Direction::right:
      return Point{x, y + 1};
    default:
      std::unreachable();
  }
}
