#include <iostream>

// Preferred version
void printDigitName(int x) {
  switch (x)
    {
    case 1: // not indented from switch statement
      std::cout << "One";
      return;
    case 2:
      std::cout << "Two";
      return;
    case 3:
      std::cout << "Three";
      return;
    default:
      std::cout << "Unknown";
      return;
    }
}

int main() {
  printDigitName(3);
  std::cout << '\n';

  return 0;
}
