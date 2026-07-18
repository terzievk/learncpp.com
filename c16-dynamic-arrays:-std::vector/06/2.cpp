#include <iostream>
#include <vector>

// Implement printArray() here
template <typename T>
void printArray(const std::vector<T>& arr) {
  for (auto i{0u}; i < arr.size(); ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

int main()
{
  std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

  printArray(arr); // use function template to print array

  return 0;
}
