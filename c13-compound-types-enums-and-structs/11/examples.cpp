#include <iostream>

struct Foo
{
  short a {};
  int b {};
  double c {};
};

int main()
{
  std::cout << "The size of short is " << sizeof(short) << " bytes\n";
  std::cout << "The size of int is " << sizeof(int) << " bytes\n";
  std::cout << "The size of double is " << sizeof(double) << " bytes\n";

  std::cout << "The size of Foo is " << sizeof(Foo) << " bytes\n";

  return 0;
}
