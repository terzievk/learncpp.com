#include <iostream>
#include <vector>

int main() {
  std::vector v{'h', 'e', 'l', 'l', 'o'};

  std::cout << "The array has " << std::size(v) << " elements.\n";

  std::cout << v[1];

  std::cout << v.at(1);
}
