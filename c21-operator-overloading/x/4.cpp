#include <cassert>
#include <cstdio>
#include <iostream>
#include <pthread.h>
#include <ranges>

#pragma pack(1)

class FixedPoint2 {
  int8_t fractional{};
  int16_t whole{};

public:
  explicit FixedPoint2(double x);
  FixedPoint2(int16_t whole, int8_t fractional);

  FixedPoint2(const FixedPoint2 &) = delete;
  FixedPoint2& operator=(const FixedPoint2 &) = delete;

  explicit operator double() const;

  friend std::ostream &operator<<(std::ostream &out, const FixedPoint2 &point);
  friend bool testDecimal(const FixedPoint2 &fp);
};
#include <cassert>
#include <iostream>

// You will need to make testDecimal a friend of FixedPoint2
// so the function can access the private members of FixedPoint2
bool testDecimal(const FixedPoint2 &fp) {
  if (fp.whole >= 0) {
    return fp.fractional >= 0 && fp.fractional < 100;
  } else {
    return fp.fractional <= 0 && fp.fractional > -100;
  }
}

int main() {
  FixedPoint2 a{ 0.01 };
  assert(static_cast<double>(a) == 0.01);

  FixedPoint2 b{ -0.01 };
  assert(static_cast<double>(b) == -0.01);

  FixedPoint2 c{ 1.9 }; // make sure we handle single digit decimal
  assert(static_cast<double>(c) == 1.9);

  FixedPoint2 d{ 5.01 }; // stored as 5.0099999... so we'll need to round this
  assert(static_cast<double>(d) == 5.01);

  FixedPoint2 e{ -5.01 }; // stored as -5.0099999... so we'll need to round this
  assert(static_cast<double>(e) == -5.01);

  // Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
  FixedPoint2 f { 106.9978 }; // should be stored with base 107 and decimal 0
  assert(static_cast<double>(f) == 107.0);

  // Handle case where the argument's decimal rounds to -100 (need to decrease base by 1)
  FixedPoint2 g { -106.9978 }; // should be stored with base -107 and decimal 0
  assert(static_cast<double>(g) == -107.0);

  return 0;
}
FixedPoint2::FixedPoint2(double x) {
  bool negative{};
  if (x < 0) {
    negative = true;
    x = -x;
  }


  whole = static_cast<int16_t>(x);
  // fraction
  double f{x - whole};
  f *= 100;
  // fraction's fraction
  double ff{f - static_cast<int>(f)};

  fractional = static_cast<int8_t>(static_cast<int8_t>(f) + (ff > 0.5 ? 1 : 0));

  if (negative) {
    whole = -whole;
    fractional = -fractional;
  }

  whole += fractional / 100;
  fractional %= 100;

}


FixedPoint2::FixedPoint2(int16_t whole, int8_t fractional)
: fractional{fractional}, whole{whole} {
  // if the numbers is negative, make both whole and fractional parts negative
  if (whole < 0 || fractional < 0) {
    if (whole > 0) { this->whole = -whole; }
    if (fractional > 0) { this->fractional = -fractional; }
  }

  // adjust for fractional overflow
  this->whole += this->fractional / 100;
  this->fractional %= 100;
}


FixedPoint2::operator double() const {
  return whole + fractional / 100.0;
}

std::ostream& operator<<(std::ostream &out, const FixedPoint2 &point) {
  return out << static_cast<double>(point);
}
