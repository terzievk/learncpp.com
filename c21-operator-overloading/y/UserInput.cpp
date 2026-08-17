#include "UserInput.h"

#include <cassert>
#include <iostream>

#include "Direction.h"

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
      std::cout
          << "Enter one of the following: h, j, k, l(or a, w, s, d) and  q: ";
      char command{};
      std::cin >> command;

      if (clearFailedExtraction()) {
        continue;
      }

      ignoreLine();  // remove any extraneous input

      // Check whether the user entered meaningful input
      switch (command) {
        case 'h':
        case 'j':
        case 'k':
        case 'l':
        case 'a':
        case 'w':
        case 's':
        case 'd':
        case 'q':
          return command;
        default:
          continue;
      }
    }
  }

  Direction commandToDirection(char command) {
    assert(command == 'h' || command == 'j' || command == 'k' ||
           command == 'l' || command == 'a' || command == 'w' ||
           command == 's' || command == 'd');
    switch (command) {
      case 'h':
      case 'a':
        return Direction{Direction::Type::left};
      case 'j':
      case 's':
        return Direction{Direction::Type::down};
      case 'k':
      case 'w':
        return Direction{Direction::Type::up};
      case 'l':
      case 'd':
        return Direction{Direction::Type::right};
      default:
        exit(1);
    }
  }
}  // namespace UserInput
