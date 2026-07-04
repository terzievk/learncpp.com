#include <iostream>
#include <string>

template <typename T, typename N, typename Q>
class Triad {
  T x{};
  N y{};
  Q z{};

public:
  Triad(const T& x, const N& y, const Q& z): x{x}, y{y}, z{z} {}

  const T& first() const {return x;}
  const T& second() const {return y;}
  const T& third() const {return z;}

  void print() const {
    std::cout << '[' << x << ", " << y << ", " << z << ']';
  }
};


int main() {
  Triad<int, int, int> t1{ 1, 2, 3 };
  t1.print();
  std::cout << '\n';
  std::cout << t1.first() << '\n';

  using namespace std::literals::string_literals;
  const Triad t2{ 1, 2.3, "Hello"s };
  t2.print();
  std::cout << '\n';

  return 0;
}
