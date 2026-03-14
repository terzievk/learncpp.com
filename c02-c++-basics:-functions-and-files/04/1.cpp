#include <iostream>

int doubleNumber(int x) {
  return x*2;
}
int main() {
  int x;
  std::cin >> x;

  std::cout << doubleNumber(x) << '\n';

  return 0;
}
