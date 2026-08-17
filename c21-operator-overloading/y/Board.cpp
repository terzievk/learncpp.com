#include "Board.h"

Board::Board() {
  int max{gridSize * gridSize};
  // puzzle starts with Tile 1
  int count{1};

  for (auto i{0uz}; i < gridSize; ++i) {
    for (auto j{0uz}; j < gridSize; ++j) {
      // % max so 16th Tile is 0, when gridSize is 4
      tiles[i][j] = Tile{count++ % max};
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Board& b) {
  for (auto i{0uz}; i < Board::consoleLines; ++i) {
    out << '\n';
  }

  for (auto i{0uz}; i < Board::gridSize; ++i) {
    for (auto j{0uz}; j < Board::gridSize; ++j) {
      out << b.tiles[i][j];
    }
    out << '\n';
  }
  return out;
}
