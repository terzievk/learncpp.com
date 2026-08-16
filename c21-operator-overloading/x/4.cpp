#include <cassert>
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
};

int main() {
  FixedPoint2 a{ 34, 56 };
  std::cout << a << '\n';
  std::cout << static_cast<double>(a) << '\n';
  assert(static_cast<double>(a) == 34.56);

  FixedPoint2 b{ -2, 8 };
  assert(static_cast<double>(b) == -2.08);

  FixedPoint2 c{ 2, -8 };
  assert(static_cast<double>(c) == -2.08);

  FixedPoint2 d{ -2, -8 };
  assert(static_cast<double>(d) == -2.08);

  FixedPoint2 e{ 0, -5 };
  assert(static_cast<double>(e) == -0.05);

  FixedPoint2 f{ 0, 10 };
  assert(static_cast<double>(f) == 0.1);

  return 0;
}

FixedPoint2::FixedPoint2(int16_t whole, int8_t fractional)
: fractional{fractional}, whole{whole} {}

FixedPoint2::operator double() const {
  if (whole < 0 || fractional < 0) {
    return - ( std::abs(whole) + std::abs(fractional / 100.0) );
  }

  return whole + fractional / 100.0;
}

std::ostream& operator<<(std::ostream &out, const FixedPoint2 &point) {
  return out << static_cast<double>(point);
}
