#include <iostream>

class Average {
  std::int32_t sum{};
  int count{};

  double getAverage() const {
    return count ? static_cast<double>(sum) / count : 0;
  }

public:
  Average() {}

  friend std::ostream &operator<<(std::ostream &out, const Average &a) {
    return out << a.getAverage();
  }

  Average& operator+=(int x) {
    sum += x;
    ++count;
    return *this;
  }
};

int main() {
  Average avg{};
  std::cout << avg << '\n';

  avg += 4;
  std::cout << avg << '\n'; // 4 / 1 = 4

  avg += 8;
  std::cout << avg << '\n'; // (4 + 8) / 2 = 6

  avg += 24;
  std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

  avg += -10;
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

  (avg += 6) += 10; // 2 calls chained together
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

  Average copy{ avg };
  std::cout << copy << '\n';
}
