#ifndef BOARD_H_
#define BOARD_H_

#include <cassert>
#include <iostream>

#include "Point.h"
#include "Tile.h"

class Board {
  static constexpr size_t consoleLines{47};
  static constexpr size_t gridSize{4};

  std::array<std::array<Tile, gridSize>, gridSize> tiles{};

 public:
  Board();

  bool isValidPoint(const Point& p);
  Point findEmpty();
  void swapTiles(const Point& p, const Point& q);
  bool moveTile(Direction direction);

  friend std::ostream& operator<<(std::ostream& out, const Board& b);
};

#endif  // BOARD_H_
