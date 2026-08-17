#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>

#include "Tile.h"

class Board {
  static constexpr size_t consoleLines{47};
  static constexpr size_t gridSize{4};

  std::array<std::array<Tile, gridSize>, gridSize> tiles{};

 public:
  Board();

  friend std::ostream& operator<<(std::ostream& out, const Board& b);
};

#endif  // BOARD_H_
