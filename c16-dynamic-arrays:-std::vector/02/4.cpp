/*
  Enter 3 integers: 3 4 5
  The sum is: 12
  The product is: 60
 */
#include <iostream>
#include <vector>

int main() {
  std::cout << "Enter 3 integers: ";

  std::vector<int> v(3);
  std::cin >> v[0] >> v[1] >> v[2];

  std::cout << "The sum is: " << v[0] + v[1] + v[2] << '\n';

  std::cout << "The product is: " << v[0] * v[1] * v[2] << '\n';

  return 0;
}
