#include <algorithm>
#include <cstdlib> // for std::exit
#include <iostream>
#include <limits> // for std::numeric_limits
#include <string_view>
#include <vector>

#include "Random.h"

int getInt(std::string_view greeting);
void generateValues(int start, int count, int multiplier, std::vector<int>& values);
void printValues(const std::vector<int> &values);
void play(std::vector<int>& values);

int main() {
  int start {getInt("Start where? ")};

  int count {getInt("How many? ")};
  while (count <= 0) {
    std::cout << "Count must be positive.\n";
    count = getInt( "How many? ");
  }

  int multiplier{Random::get(2, 4)};

  std::vector<int> values{};

  generateValues(start, count, multiplier, values);
  //  printValues(values);

  std::cout << "I generated " << count << " square numbers. Do you know what";
  std::cout << " each number is after multiplying by " << multiplier << "?\n";

  play(values);
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

int getNearest(int guess, const std::vector<int>& values) {
  auto comp {
    [=](const int &a, const int &b) {
      return std::abs(guess - a) < std::abs(guess - b);
    }};

  return *std::min_element(values.begin(), values.end(), comp);
}

void play(std::vector<int>& values) {
  while (true) {
    int guess{ getInt("> ") };

    auto found{ std::find(values.begin(), values.end(), guess) };

    if (found == values.end()) {
      std::cout << guess << " is wrong! Try " << getNearest(guess, values) << " next time.\n";
      continue;
    }

    values.erase(found);

    if (values.size()) {
      std::cout << "Nice! " << values.size() << " numbers left.\n";
      continue;
    }

    std::cout << "Nice! You found all numbers, good job!\n";
    return;
  }
}
