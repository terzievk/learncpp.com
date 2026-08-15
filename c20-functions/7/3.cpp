#include <cstdlib> // for std::exit
#include <iostream>
#include <limits> // for std::numeric_limits
#include <string_view>
#include <vector>

#include "Random.h"

int getInt(std::string_view greeting);

void generateValues(int start, int count, int multiplier, std::vector<int>& values) {
  for (int i{}; i < count; ++i) {
    values.push_back((start + i) * (start + i) * multiplier );
  }
}

void printValues(const std::vector<int> &values) {
  for (const int &x : values) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

int main() {
  int start {getInt("Start where? ")};
  int count {getInt("How many? ")};

  int multiplier{Random::get(2, 4)};

  std::vector<int> values{};

  generateValues(start, count, multiplier, values);

  printValues(values);
}

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction() {
  if (!std::cin) {
    if (std::cin.eof()) {
      std::exit(0);
    }

    std::cin.clear();  // Put us back in 'normal' operation mode
    ignoreLine();      // And remove the bad input

    return true;
  }

  return false;
}

int getInt(std::string_view greeting) {
  while (true) {
    std::cout << greeting;
    int x{};
    std::cin >> x;

    if (clearFailedExtraction()) {
      std::cout << "Oops, that input is invalid. Enter an integer.\n";
      continue;
    }

    ignoreLine(); // Remove any extraneous input
    return x;     // Return the value we extracted
  }
}
