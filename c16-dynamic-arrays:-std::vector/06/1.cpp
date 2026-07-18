#include <iostream>
#include <vector>

int main() {
  std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
  // Add your code here
  for (auto i{0u}; i < arr.size(); ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}
