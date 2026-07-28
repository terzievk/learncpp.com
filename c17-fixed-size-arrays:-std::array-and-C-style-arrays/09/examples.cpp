#include <iostream>

int main()
{
  [[maybe_unused]]  int x {};
  const int* ptr{ &x }; // assume 4 byte ints

  std::cout << ptr << ' ' << (ptr - 1) << ' ' << (ptr - 2) << '\n';

  return 0;
}
