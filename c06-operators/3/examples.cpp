// #include <iostream>

// bool isOdd(int x) {
//   return x % 2; // fails when x is -5
// }

// int main() {
//   std::cout << isOdd(5) << '\n';
//   std::cout << isOdd(-5) << '\n';
//   std::cout << static_cast<bool>(1) << '\n';
//   std::cout << static_cast<bool>(100) << '\n';
//   std::cout << static_cast<bool>(0) << '\n';
//   std::cout << static_cast<bool>(-0) << '\n';
//   std::cout << static_cast<bool>(-10) << '\n';
//   std::cout << static_cast<bool>(-1) << '\n';
//   std::cout << static_cast<bool>(-1) << '\n';
//   return 0;
// }

#include <cassert> // for assert
#include <cstdint> // for std::int64_t
#include <iostream>

// note: exp must be non-negative
// note: does not perform range/overflow checking, use with caution
constexpr std::int64_t powint(std::int64_t base, int exp)
{
  assert(exp >= 0 && "powint: exp parameter has negative value");

  // Handle 0 case
  if (base == 0)
    return (exp == 0) ? 1 : 0;

  std::int64_t result{ 1 };
  while (exp > 0)
    {
      if (exp & 1)  // if exp is odd
        result *= base;
      exp /= 2;
      base *= base;
    }

  return result;
}

int main()
{
  std::cout << powint(2, 5) << '\n'; // 7 to the 12th power

  return 0;
}
