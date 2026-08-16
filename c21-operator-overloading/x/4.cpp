#include <cassert>
#include <iostream>
#include <pthread.h>

#pragma pack(1)

class FixedPoint2 {
  int8_t fractional{};
  int16_t whole{};

public:
  explicit FixedPoint2(double x);
  FixedPoint2(int16_t whole, int8_t fractional);

  explicit operator double() const;

  FixedPoint2 operator-();

  friend std::ostream &operator<<(std::ostream &out, const FixedPoint2 &point);
  friend std::istream &operator>>(std::istream &in, FixedPoint2 &point);
  friend bool operator==(const FixedPoint2 &a, const FixedPoint2 &b);
  friend FixedPoint2 operator+(const FixedPoint2 &a, const FixedPoint2 &b);

  friend bool testDecimal(const FixedPoint2 &fp);
};

int main() {
  assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
  assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

  // Test additional cases -- h/t to reader Sharjeel Safdar for these test cases

  // both positive, no decimal overflow
  assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });
  // both positive, with decimal overflow
  assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });
  // both negative, no decimal overflow
  assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 });
  // both negative, with decimal overflow
  assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 });
  // second negative, no decimal overflow
  assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });
  // second negative, possible decimal overflow
  assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });
  // first negative, no decimal overflow
  assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });
  // first negative, possible decimal overflow
  assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });

  FixedPoint2 a{ -0.48 };
  assert(static_cast<double>(a) == -0.48);
  assert(static_cast<double>(-a) == 0.48);

  std::cout << "Enter a number: "; // enter 5.678
  std::cin >> a;
  std::cout << "You entered: " << a << '\n';
  assert(static_cast<double>(a) == 5.68);
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

std::istream &operator>>(std::istream &in, FixedPoint2 &point) {
  double x{};
  in >> x;
  point = FixedPoint2 {x};
  return in;
}

bool operator==(const FixedPoint2 &a, const FixedPoint2 &b) {
  return a.fractional == b.fractional && a.whole == b.whole;
}

FixedPoint2 operator+(const FixedPoint2 &a, const FixedPoint2 &b) {
  return FixedPoint2{static_cast<double>(a) + static_cast<double>(b)};
}

FixedPoint2 FixedPoint2::operator-() {
  return FixedPoint2{-static_cast<double>(*this)};
}

// You will need to make testDecimal a friend of FixedPoint2
// so the function can access the private members of FixedPoint2
bool testDecimal(const FixedPoint2 &fp) {
  if (fp.whole >= 0) {
    return fp.fractional >= 0 && fp.fractional < 100;
  } else {
    return fp.fractional <= 0 && fp.fractional > -100;
  }
}
