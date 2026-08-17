#ifndef BOARD_H_
#define BOARD_H_

#include <array>
#include <cstddef>
#include <iostream>

#include "Point.h"
#include "Tile.h"

class Board {
  static constexpr size_t consoleLines{47};
  static constexpr size_t gridSize{4};

  std::array<std::array<Tile, gridSize>, gridSize> tiles{};

 public:
  Board();

  bool isValidPoint(const Point& p) const;
  Point findEmpty() const;
  void swapTiles(const Point& p, const Point& q);
  bool moveTile(Direction direction);

  void randomize();
  bool operator==(const Board& b) const;

  bool playerWon() const { return this->operator==(Board{}); }

  friend std::ostream& operator<<(std::ostream& out, const Board& b);
};

#endif  // BOARD_H_
