#include <array>
#include <functional> // for std::reference_wrapper
#include <iostream>

int main()
{
  int x { 1 };
  int y { 2 };
  int z { 3 };

  std::array<std::reference_wrapper<int>, 3> arr { x, y, z };

  arr[1].get() = 5; // modify the object in array element 1

  std::cout << arr[1] << y << '\n'; // show that we modified arr[1] and y, prints 55

  return 0;
}
