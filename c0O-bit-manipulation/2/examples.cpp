#include <bitset>
#include <iostream>

int main() {
  std::bitset<4> x { 0b1100 };

  std::cout << x << '\n';
  std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
  std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000

  // int x {192444};
  // int8_t y {static_cast<int8_t> (x)};
  // std::cout << x << ' ' << y << '\n';

  return 0;
}
