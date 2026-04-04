#include <iostream>

int readNumber() {
  std::cout << "Please enter a number: ";
  int x;
  std::cin >> x;
  return x;
}

void writeAnswer(int x) {
  std::cout << "The sum is: " << x << '\n';
}

int main() {
  writeAnswer(readNumber() + readNumber());

  return 0;
}
