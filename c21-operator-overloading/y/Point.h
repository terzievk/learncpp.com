#ifndef POINT_H_
#define POINT_H_

#include "Direction.h"

class Point {
  size_t x{};
  size_t y{};

 public:
  Point(size_t x, size_t y) : x{x}, y{y} {}

  Point getAdjacentPoint(Direction::Type direction);

  bool operator==(const Point& p) const { return x == p.x && y == p.y; }
  bool operator!=(const Point& p) const { return x != p.x || y != p.y; }
};

#endif  // POINT_H_
