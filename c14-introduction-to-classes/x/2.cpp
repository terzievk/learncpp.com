#include <iostream>

class Fraction {
  int numerator{ 0 };
  int denominator{ 1 };

public:
  Fraction() {
    std::cout << "Enter a value for numerator: ";
    std::cin >> numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> denominator;
    std::cout << '\n';
  }

  Fraction(int n, int d): numerator{n}, denominator{d} {}

  Fraction multiply(const Fraction& f1, const Fraction& f2) {
    return { f1.numerator * f2.numerator, f1.denominator * f2.denominator };
  }

  void printFraction(const Fraction& f) {
    std::cout << f.numerator << '/' << f.denominator << '\n';
  }

};



int main() {
  Fraction f1{};
  Fraction f2{};

  std::cout << "Your fractions multiplied together: ";

  f1.printFraction(f1.multiply(f1, f2));

  return 0;
}
