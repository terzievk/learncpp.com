#include <cmath>
#include <iostream>

class Point2d {
  double x{};
  double y{};

public:
  explicit Point2d(double xx = 0.0, double yy = 0.0): x{xx}, y{yy} {}

  void print() {
    std::cout << "Point2d(" << x << ", " << y << ")\n";
  }

  double distanceTo(const Point2d& other) const {
    return std::sqrt((x - other.x) * (x - other.x)
                     + (y - other.y) * (y - other.y));
  }
};

int main() {
  Point2d first{};
  Point2d second{ 3.0, 4.0 };

  first.print();
  second.print();

  std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

  return 0;
}
