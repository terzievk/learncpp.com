#include <iostream>

int sumOfDigits(int n) {
  if (n <= 0) {
    return 0;
  }

  return n % 10 + sumOfDigits(n / 10);
}

int main() {
  std::cout << sumOfDigits(93427) << '\n';
}
