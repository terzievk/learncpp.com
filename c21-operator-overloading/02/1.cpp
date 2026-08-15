#include <iostream>
#include <numeric>

class Fraction {
  int num{};
  int den{};

  void reduce() {
    int d{std::gcd(num, den)};

    num /= d;
    den /= d;
  }

public:
  Fraction(int num, int den) : num{num}, den{den} {
    reduce();
  }

  void print() const {
    std::cout << num << '/' << den << '\n';
  }

  friend Fraction operator*(const Fraction &f, const Fraction &g) {
    return Fraction{f.num * g.num, f.den * g.den};
  }

  friend Fraction operator*(int x, const Fraction &f) {
    return Fraction{x * f.num, f.den};
  }

  friend Fraction operator*(const Fraction &f, int x) {
    return x * f;
  }
};

int main() {
  Fraction f1{2, 5};
  f1.print();

  Fraction f2{3, 8};
  f2.print();

  Fraction f3{ f1 * f2 };
  f3.print();

  Fraction f4{ f1 * 2 };
  f4.print();

  Fraction f5{ 2 * f2 };
  f5.print();

  Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
  f6.print();

  Fraction f7{0, 6};
  f7.print();

  return 0;
}
