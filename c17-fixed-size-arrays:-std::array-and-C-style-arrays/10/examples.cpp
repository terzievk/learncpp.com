#include <iostream>

void print(char ptr[])
{
  std::cout << ptr << '\n'; // output string
}

int main()
{
  char str[]{ "string" };
  std::cout << str << '\n'; // outputs string

  print(str);

  return 0;
}
