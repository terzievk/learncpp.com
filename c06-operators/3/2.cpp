#include <iostream>

int readNumber() {
  std::cout << "Enter an integer: ";
  int x;
  std::cin >> x;

  return x;
}

constexpr bool isEven(int x) {
  return !(x % 2);
}

int main() {
  while (std::cin) {
    std::cout << isEven(readNumber()) << '\n';
  }

  return 0;
}
