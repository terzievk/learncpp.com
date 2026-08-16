#include <iostream>

#pragma pack(1)

class Test {
  int8_t y{};
  int16_t x{};
};

int main() {
  std::cout << sizeof(double) << '\n';
  std::cout << sizeof(float) << '\n';
  std::cout << sizeof(int) << '\n';
  std::cout << sizeof(int32_t) << '\n';
  std::cout << sizeof(int16_t) << '\n';
  std::cout << sizeof(int8_t) << '\n';
  std::cout << (1 << 15) << '\n';
  std::cout << sizeof(Test) << '\n';
}
