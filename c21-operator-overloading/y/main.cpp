#include <cassert>
#include <iostream>

#include "Board.h"
#include "Direction.h"
#include "Point.h"
#include "Tile.h"
#include "UserInput.h"

void testStep2();
void testStep3();
void testStep4();
void testStep5();
void testStep6();
void testStep7();

void testStep7() {
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

    Direction direction{UserInput::commandToDirection(command)};

    if (board.moveTile(direction)) {
      std::cout << board;
    }
  }
}

int main() { testStep7(); }

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

void testStep6() {
  std::cout << std::boolalpha;
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::up) == Point{0, 1})
            << '\n';
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::down) == Point{2, 1})
            << '\n';
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::left) == Point{1, 0})
            << '\n';
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::right) == Point{1, 2})
            << '\n';
  std::cout << (Point{1, 1} != Point{2, 1}) << '\n';
  std::cout << (Point{1, 1} != Point{1, 2}) << '\n';
  std::cout << !(Point{1, 1} != Point{1, 1}) << '\n';
}
