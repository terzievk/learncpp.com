#include <array>
#include <cassert>
#include <concepts>
#include <cstdlib>  // for std::exit
#include <iostream>
#include <limits>  // for std::numeric_limits
#include <string_view>

#include "Random.h"

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

class Direction;

namespace UserInput {
  char getCommand();

  Direction commandToDirection(char command);
}  // namespace UserInput

using namespace std::string_view_literals;

class Direction {
 public:
  enum Type { up, down, left, right, maxDirections };

  static constexpr std::array allDirections{up, down, left, right};
  static_assert(allDirections.size() == maxDirections);

  static constexpr std::array directions{"up"sv, "down"sv, "left"sv, "right"sv};
  static_assert(directions.size() == maxDirections);

 private:
  Type direction{};

 public:
  Direction(Type direction) : direction{direction} {}

  Direction operator-();

  static Direction getRandom();

  friend std::ostream& operator<<(std::ostream& out, const Direction& d);
};

void testStep2();
void testStep3();
void testStep4();
void testStep5();

void testStep5() {
  Board board{};
  std::cout << board;

  for (int i{}; i < 4; ++i) {
    std::cout << "Generating random direction... " << Direction::getRandom()
              << '\n';
  }

  while (true) {
    char command{UserInput::getCommand()};

    if (command == 'q') {
      std::cout << "Valid command: q\n\nBye!\n\n";
      break;
    }

    std::cout << "Valid command: "
              << Direction{UserInput::commandToDirection(command)} << '\n';
  }
}

int main() { testStep5(); }

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

void testStep4() {
  Board board{};
  std::cout << board;

  while (true) {
    char command{UserInput::getCommand()};

    std::cout << "Valid command: " << command << '\n';

    if (command == 'q') {
      std::cout << "\n\nBye!\n\n";
      break;
    }
  }
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

namespace UserInput {
  void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  // returns true if extraction failed, false otherwise
  bool clearFailedExtraction() {
    if (!std::cin) {
      if (std::cin.eof()) {
        std::exit(0);  // Shut down the program now
      }

      std::cin.clear();  // Put us back in 'normal' operation mode
      ignoreLine();      // And remove the bad input

      return true;
    }

    return false;
  }

  // hard-coded commands for now
  char getCommand() {
    while (true) {
      // go with h, j, k, l instread of a, w, s, d
      std::cout << "Enter one of the following: h, j, k, l, q: ";
      char command{};
      std::cin >> command;

      ignoreLine();  // remove any extraneous input regardless

      // Check whether the user entered meaningful input
      switch (command) {
        case 'h':
        case 'j':
        case 'k':
        case 'l':
        case 'q':
          return command;
        default:
          continue;
      }
    }
  }

  Direction commandToDirection(char command) {
    assert(command == 'h' || command == 'j' || command == 'k' ||
           command == 'l');
    switch (command) {
      case 'h':
        return Direction{Direction::Type::left};
      case 'j':
        return Direction{Direction::Type::down};
      case 'k':
        return Direction{Direction::Type::up};
      case 'l':
        return Direction{Direction::Type::right};
      default:
        exit(1);
    }
  }
}  // namespace UserInput

Direction Direction::operator-() {
  switch (this->direction) {
    case up:
      return Direction{down};
    case down:
      return Direction{up};
    case left:
      return Direction{right};
    case right:
      return Direction{left};
    default:
      assert("Invalid direction");
      exit(1);
  }
}

Direction Direction::getRandom() {
  return allDirections[Random::get(0uz,
                                   static_cast<size_t>(maxDirections) - 1)];
}

std::ostream& operator<<(std::ostream& out, const Direction& d) {
  return out << d.directions[d.direction];
}
