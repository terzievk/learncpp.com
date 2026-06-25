#include <iostream>

class Point3d {
  int x {};
  int y {};
  int z {};

public:
  void setValues(int xx, int yy, int zz) {
    x = xx;
    y = yy;
    z = zz;
  }

  void print() const {
    std::cout << '<' << x << ", " << y << ", " << z << '>';
  }

  bool isEqual(const Point3d& other) const {
    return x == other.x && y == other.y && z == other.z;
  }
};

int main() {
  Point3d point1{};
  point1.setValues(1, 2, 3);

  Point3d point2{};
  point2.setValues(1, 2, 3);

  std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

  Point3d point3{};
  point3.setValues(3, 4, 5);

  std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

  return 0;
}
