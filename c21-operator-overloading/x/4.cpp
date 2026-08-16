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
  FixedPoint2 a{ 1, 104 };
  std::cout << a << '\n';
  std::cout << static_cast<double>(a) << '\n';
  assert(static_cast<double>(a) == 2.04);
  assert(testDecimal(a));

  FixedPoint2 b{ 1, -104 };
  assert(static_cast<double>(b) == -2.04);
  assert(testDecimal(b));

  FixedPoint2 c{ -1, 104 };
  assert(static_cast<double>(c) == -2.04);
  assert(testDecimal(c));

  FixedPoint2 d{ -1, -104 };
  assert(static_cast<double>(d) == -2.04);
  assert(testDecimal(d));

  return 0;
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
