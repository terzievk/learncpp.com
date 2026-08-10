#include <iostream>

void printBinary(unsigned int x) {
  if (x > 1) {
    printBinary(x/2);
  }

  std::cout << x % 2;
}

int main() {
  int x;
  std::cin >> x;

  printBinary(static_cast<unsigned int>(x));
  std::cout << '\n';
}
