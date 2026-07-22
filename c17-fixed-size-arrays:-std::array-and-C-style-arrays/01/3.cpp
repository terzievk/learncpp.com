#include <iostream>
#include <array>

int main() {
  constexpr std::array arr{'h', 'e', 'l', 'l', 'o'};

  std::cout << arr[1] << '\n';
}
