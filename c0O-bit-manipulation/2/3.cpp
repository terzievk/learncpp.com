#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits) {
  if ((bits & std::bitset<4> {1000}) == std::bitset<4>{1000}) {
    bits <<= 1;
    bits |= std::bitset<4> {0001};

    return bits;
  }

  bits <<= 1;

  return bits;
}

int main() {
  std::bitset<4> bits1{ 0b0001 };
  std::cout << rotl(bits1) << '\n';

  std::bitset<4> bits2{ 0b1001 };
  std::cout << rotl(bits2) << '\n';

  return 0;
}
