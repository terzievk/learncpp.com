#include <iostream>

// define your factorial() function template here
template <int N>
constexpr int factorial() {

  static_assert(N >= 0 && "Factorial is not defined for negative numbers");

  int prod{1};
  for (int i{1}; i <= N; ++i) {
    prod *= i;
  }

  return prod;
}



int main() {
  static_assert(factorial<0>() == 1);
  static_assert(factorial<3>() == 6);
  static_assert(factorial<5>() == 120);

  // factorial<-3>(); // should fail to compile

  return 0;
}
