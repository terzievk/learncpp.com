#include <iostream>
#include <array>

int main() {
  constexpr std::array a{'h', 'e', 'l', 'l', 'o'};
  std::cout << "The length is " << a.size() << '\n';
  std::cout << a[1];
  std::cout << a.at(1);
  std::cout << std::get<1>(a);
  std::cout << '\n';
}
