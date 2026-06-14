#include <cstdlib> // for std::exit
#include <iostream>
#include <limits> // for std::numeric_limits

#include "./Random.h"


bool wannaPlay();

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if std::cin has unextracted input on the current line, false otherwise
bool hasUnextractedInput() {
  return !std::cin.eof() && std::cin.peek() != '\n';
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction() {
  if (std::cin) {
    return false;
  }

  if (std::cin.eof()) {  // If the stream was closed
    std::exit(0); // Shut down the program now
  }

  // Let's handle the failure
  std::cin.clear();  // Put us back in 'normal' operation mode
  ignoreLine();      // And remove the bad input

  return true;
}

int takeAGuess() {
  while (true) {
    std::cout << "Enter your guess(int):\n";
    int x;
    std::cin >> x;

    if (clearFailedExtraction()) {
      std::cout << "Invalid guess. Try again.\n";
      continue;
    }

    // if there is extraneous input, treat as failure case
    if (hasUnextractedInput()) {
      std::cout << "Invalid guess. Try again.\n";
      ignoreLine();
      continue;
    }

    return x;
  }
}



void play() {
  int min;
  int max;
  std::cout << "Enter min & max\n";
  std::cin >> min >> max;

  int x {Random::get(min, max)};

  for (int i{}; i < 7; ++i) {
    int y{takeAGuess()};

    if (y == x) {
      std::cout << "you win\n";
      return;
    } else if (y > x) {
      std::cout << "high\n";
    } else {
      std::cout << "low\n";
    }
  }

  std::cout << "you lose\n";
}

int main() {
  while (wannaPlay()) {
    play();
  }

  return 0;
}

bool wannaPlay() {
  std::cout << "wanna play?\n";
  char c;
  std::cin >> c;

  return c == 'y';
}
