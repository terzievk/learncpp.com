#include <iostream>

#define CONSTEVAL(...) [] consteval { return __VA_ARGS__; }()               // C++20 version per Jan Scultke (https://stackoverflow.com/a/77107431/460250)
#define CONSTEVAL11(...) [] { constexpr auto _ = __VA_ARGS__; return _; }() // C++11 version per Justin (https://stackoverflow.com/a/63637573/460250)

// This function returns the greater of the two numbers if executing in a constant context
// and the lesser of the two numbers otherwise
constexpr int compare(int x, int y) // function is constexpr
{
  if (std::is_constant_evaluated())
    return (x > y ? x : y);
  else
    return (x < y ? x : y);
}

int main()
{
  int x { 5 };
  std::cout << compare(x, 6) << '\n';                  // will execute at runtime and return 5

  std::cout << compare(5, 6) << '\n';                  // may or may not execute at compile-time, but will always return 5
  std::cout << CONSTEVAL(compare(5, 6)) << '\n';       // will always execute at compile-time and return 6


  return 0;
}
