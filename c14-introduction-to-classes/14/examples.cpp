#include <iostream>

class Fraction
{
private:
  int m_numerator{ 0 };
  int m_denominator{ 1 };

public:
  // Default constructor
  Fraction(int numerator = 0, int denominator = 1)
  : m_numerator{ numerator }, m_denominator{ denominator }
  {
  }

  // Copy constructor
  Fraction(const Fraction& fraction)
  : m_numerator{ fraction.m_numerator }
    , m_denominator{ fraction.m_denominator }
  {
    std::cout << "Copy constructor called\n";
  }

  void print() const
  {
    std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
  }
};

void printFraction(Fraction f) // f is pass by value
{
  f.print();
}

int main()
{
  Fraction f{ 5, 3 };

  printFraction(f); // f is copied into the function parameter using copy constructor

  return 0;
}
