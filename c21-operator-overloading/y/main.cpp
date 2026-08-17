#include <array>
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

class Board {
  static constexpr size_t consoleLines{47};
  static constexpr size_t gridSize{4};

  std::array<std::array<Tile, gridSize>, gridSize> tiles{};

 public:
  Board();

  friend std::ostream& operator<<(std::ostream& out, const Board& b);
};

void testStep2();
void testStep3();

int main() { return 0; }

void testStep2() {
  Tile tile1{10};
  Tile tile2{8};
  Tile tile3{0};  // the missing tile
  Tile tile4{1};

  // to make it easy to see how many spaces are in the next line
  std::cout << "0123456789ABCDEF\n";
  std::cout << tile1 << tile2 << tile3 << tile4 << '\n';

  std::cout << std::boolalpha << tile1.isEmpty() << ' ' << tile3.isEmpty()
            << '\n';

  std::cout << "Tile 2 has number: " << tile2.getNum()
            << "\nTile 4 has number: " << tile4.getNum() << '\n';
}

void testStep3() {
  Board board{};
  std::cout << board;
}

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
  int value{tile.getNum()};

  // double padding if single digit
  out << (value < 10 ? "  " : " ");

  // don't print the zero
  if (value == 0) {
    return out << "  ";
  }

  return out << value << ' ';
}

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
