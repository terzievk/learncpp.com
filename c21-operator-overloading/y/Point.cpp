#include "Point.h"

#include <cassert>
#include <cstdlib>

#include "Direction.h"

Point Point::getAdjacentPoint(Direction::Type direction) {
  // assume the given "weird" orientation of the x and y axes
  switch (direction) {
    case Direction::up:
      return Point{x, y - 1};
    case Direction::down:
      return Point{x, y + 1};
    case Direction::left:
      return Point{x - 1, y};
    case Direction::right:
      return Point{x + 1, y};
    default:
      assert("getAdjacentPoint invalid direction");
      exit(1);
  }
}
