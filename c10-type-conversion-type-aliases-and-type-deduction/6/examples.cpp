#include <iostream>

int main()
{
  unsigned char c { 'a' };
  using uint = unsigned int;
  std::cout << uint { c } << '\n';

  return 0;
}
