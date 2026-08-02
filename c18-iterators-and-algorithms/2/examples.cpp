#include <array>
#include <cstddef>
#include <iostream>

int main()
{
  // In C++17, the type of variable arr is deduced to std::array<int, 7>
  // If you get an error compiling this example, see the warning below
  std::array arr{ 0, 1, 2, 3, 4, 5, 6 };
  std::size_t length{ std::size(arr) };

  // while-loop with explicit index
  std::size_t index{ 0 };
  while (index < length)
    {
      std::cout << arr[index] << ' ';
      ++index;
    }
  std::cout << '\n';

  // for-loop with explicit index
  for (index = 0; index < length; ++index)
    {
      std::cout << arr[index] << ' ';
    }
  std::cout << '\n';

  // for-loop with pointer (Note: ptr can't be const, because we increment it)
  for (auto ptr{ &arr[0] }; ptr != (&arr[0] + length); ++ptr)
    {
      std::cout << *ptr << ' ';
    }
  std::cout << '\n';

  // range-based for loop
  for (int i : arr)
    {
      std::cout << i << ' ';
    }
  std::cout << '\n';

  return 0;
}
