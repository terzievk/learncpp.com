#include <iostream>
#include <cmath>

consteval int doSomething(int x, int y) // function is consteval
{
  x = x + 2;       // we can modify the value of non-const function parameters

  int z { x + y }; // we can instantiate non-const local variables
  if (x > y)
    z = z - 1;   // and then modify their values

  return z;
}

int main()
{
  constexpr int g { doSomething(5, 6) };
  std::cout << g << '\n';

  return 0;
}
