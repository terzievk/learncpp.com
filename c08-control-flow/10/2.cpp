#include <iostream>

int sumTo(int value) {
  int sum{};
  // let's pretend we need a loop for the sum
  for (int i{1}; i <= value; ++i) {
    sum += i;
  }

  return sum;
}

int main() {
  int x;
  std::cin >> x;

  std::cout << sumTo(x) << '\n';

  return 0;
}
