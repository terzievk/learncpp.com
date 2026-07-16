#include <iostream>
#include <vector>

int main()
{
  std::vector prime{ 2, 3, 5, 7, 11 };

  int index { 3 };                   // non-constexpr
  std::cout << prime.data()[index] << '\n'; // possible warning: index implicitly converted to std::size_t, narrowing conversion

  return 0;
}
