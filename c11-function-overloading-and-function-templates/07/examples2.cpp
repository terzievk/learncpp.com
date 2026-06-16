#include <iostream>

template <typename T>
void printIDAndValue(T value);

template <>
void printIDAndValue<int>(int value)
{
  static int id{ 0 };
  std::cout << ++id << ") " << value << '\n';
}

template <>
void printIDAndValue<double>(double value)
{
  static int id{ 0 };
  std::cout << ++id << ") " << value << '\n';
}

int main()
{
  printIDAndValue(12);   // calls printIDAndValue<int>()
  printIDAndValue(13);   // calls printIDAndValue<int>()

  printIDAndValue(14.5); // calls printIDAndValue<double>()

  return 0;
}
