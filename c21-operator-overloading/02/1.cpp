#include <iostream>

class Fraction {
  int num{};
  int den{};

public:
  Fraction(int num, int den):num{num}, den{den} {}

  void print() const {
    std::cout << num << '/' << den << '\n';
  }
};

int main() {
  Fraction f1{ 1, 4 };
  f1.print();

  Fraction f2{ 1, 2 };
  f2.print();

  return 0;
}
