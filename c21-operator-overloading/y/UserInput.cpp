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
