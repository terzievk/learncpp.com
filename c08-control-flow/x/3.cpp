#include <iostream>
#include "./Random.h"

void play(int min, int max) {
  int x {Random::get(min, max)};

  for (int i{}; i < 7; ++i) {
    int y;
    std::cin >> y;

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
  int min;
  int max;
  std::cout << "Enter min & max\n";
  std::cin >> min >> max;

  play(min, max);

  return 0;
}
