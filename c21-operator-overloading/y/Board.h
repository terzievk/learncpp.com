#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>

#include "Point.h"
#include "Tile.h"

class Board {
  static constexpr size_t consoleLines{47};
  static constexpr size_t gridSize{4};

  std::array<std::array<Tile, gridSize>, gridSize> tiles{};

 public:
  Board();

  bool isValidPoint(const Point& p) {
    size_t x{p.getX()};
    size_t y{p.getY()};
    return x < gridSize && y < gridSize;
  }

  // Point findEmpty() {
  //   for (int i{}; i < gridSize; ++i) {
  //     for (int j{}; j < gridSize; ++j) {
  //     }
  //   }
  // }
  friend std::ostream& operator<<(std::ostream& out, const Board& b);  //
};

#endif  // BOARD_H_
