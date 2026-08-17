#include "Board.h"

#include <utility>

#include "Direction.h"

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

bool Board::isValidPoint(const Point& p) {
  size_t x{p.getX()};
  size_t y{p.getY()};
  return x < gridSize && y < gridSize;
}

Point Board::findEmpty() {
  for (auto i{0uz}; i < gridSize; ++i) {
    for (auto j{0uz}; j < gridSize; ++j) {
      if (tiles[i][j].isEmpty()) {
        return Point{i, j};
      }
    }
  }
  std::unreachable();
}

void Board::swapTiles(const Point& p, const Point& q) {
  std::swap(tiles[p.getX()][p.getY()], tiles[q.getX()][q.getY()]);
}

bool Board::moveTile(Direction direction) {
  Point empty{findEmpty()};
  Point adj{empty.getAdjacentPoint(-direction)};

  if (isValidPoint(adj)) {
    swapTiles(empty, adj);
    return true;
  }

  return false;
}

void Board::randomize() {
  int someBigNumber{1000};
  for (int i{}; i < someBigNumber; ++i) {
    Point empty{findEmpty()};

    Point adj{empty.getAdjacentPoint(Direction::getRandom())};

    if (isValidPoint(adj)) {
      swapTiles(empty, adj);
    }
  }
}

bool Board::operator==(const Board& b) {
  for (auto i{0uz}; i < gridSize; ++i) {
    for (auto j{0uz}; j < gridSize; ++j) {
      if (tiles[i][j].getNum() != b.tiles[i][j].getNum()) {
        return false;
      }
    }
  }

  return true;
}
