#include <iostream>

class Accumulator
{
private:
  int m_value { 0 };

public:
  void add(int value) { m_value += value; }
  int value() const { return m_value; } // added this reasonable access function
};

void print(const Accumulator& accumulator) // no longer a friend of Accumulator
{
  std::cout << accumulator.value(); // use access function instead of direct access
}

int main()
{
  Accumulator acc{};
  acc.add(5); // add 5 to the accumulator

  print(acc); // call the print() non-member function

  return 0;
}
