#include <cassert>
#include <iostream>

#include "Board.h"
#include "Direction.h"
#include "Tile.h"
#include "UserInput.h"

class Point {
  size_t x{};
  size_t y{};

 public:
  Point(size_t x, size_t y) : x{x}, y{y} {}

  Point getAdjacentPoint(Direction::Type direction);

  bool operator==(const Point& p) const { return x == p.x && y == p.y; }
  bool operator!=(const Point& p) const { return x != p.x || y != p.y; }
};

Point Point::getAdjacentPoint(Direction::Type direction) {
  // assume the given "weird" orientation of the x and y axes
  switch (direction) {
    case Direction::up:
      return Point{x, y - 1};
    case Direction::down:
      return Point{x, y + 1};
    case Direction::left:
      return Point{x - 1, y};
    case Direction::right:
      return Point{x + 1, y};
    default:
      assert("getAdjacentPoint invalid direction");
      exit(1);
  }
}

void testStep2();
void testStep3();
void testStep4();
void testStep5();
void testStep6();

void testStep6() {
  std::cout << std::boolalpha;
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::up) == Point{1, 0})
            << '\n';
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::down) == Point{1, 2})
            << '\n';
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::left) == Point{0, 1})
            << '\n';
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::right) == Point{2, 1})
            << '\n';
  std::cout << (Point{1, 1} != Point{2, 1}) << '\n';
  std::cout << (Point{1, 1} != Point{1, 2}) << '\n';
  std::cout << !(Point{1, 1} != Point{1, 1}) << '\n';
}

int main() { testStep6(); }

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
