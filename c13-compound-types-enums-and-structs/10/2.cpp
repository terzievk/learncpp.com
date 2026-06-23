#include <iostream>

struct Fraction {
  int num{0};
  int den{1};
};

Fraction readFraction() {
  Fraction f{};
  std::cin >> f.num >> f.den;

  return f;
}

constexpr Fraction multiplyTwoFractions(const Fraction& a, const Fraction& b) {
  return {a.num * b.num, a.den * b.den};
}

void print (const Fraction& f) {
  std::cout << f.num << '/' << f.den << '\n';
}

int main() {

  print(multiplyTwoFractions(readFraction(), readFraction()));

  return 0;
}
