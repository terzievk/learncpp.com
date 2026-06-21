#include <iostream>

void printAddresses(int& ref, int val)
{
  std::cout << "The address of the value parameter is: " << &val << '\n';
  std::cout << "The address of the reference parameter is: " << &ref << '\n';
}

int main()
{
  int x { 5 };
  int y { 5 };

  std::cout << "The address of x is: " << &x << '\n';
  std::cout << "The address of x is: " << &y << '\n';
  printAddresses(x, x);

  return 0;
}
