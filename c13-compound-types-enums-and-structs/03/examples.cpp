#include <cstdint>  // for std::int8_t
#include <iostream>

// Use an 8-bit integer as the enum underlying type
enum Color : std::int8_t
{
  black,
  red,
  blue,
};

int main()
{
  Color c{ black };
  std::cout << sizeof(c) << '\n'; // prints 1 (byte)

  return 0;
}
