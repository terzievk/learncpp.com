#include <iostream>

// x E [0, 9]
bool isPrime(int x) {
  if (x == 2) {
    return true;
  } else if (x == 3) {
    return true;
  } else if (x == 5) {
    return true;
  } else if (x == 7) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int x;
  std::cin >> x;

  if (isPrime(x)) {
    std::cout << "The digit is prime\n";
  } else {
    std::cout << "The digit is not prime\n";
  }
  return 0;
}
