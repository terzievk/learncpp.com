#ifndef TILE_H_
#define TILE_H_

#include <iostream>

// tiles are in the format:
// _ _ a _  or  _ a b _  where a/b are single digits
class Tile {
  int value{};

 public:
  Tile() {}
  explicit Tile(int value) : value{value} {}
  int getNum() const { return value; }
  bool isEmpty() const { return value == 0; }
};

std::ostream& operator<<(std::ostream& out, const Tile& tile);

#endif  // TILE_H_
