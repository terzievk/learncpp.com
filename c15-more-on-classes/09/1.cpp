#include <iostream>

class Vector3d;

class Point3d {
  double x{};
  double y{};
  double z{};

public:
  Point3d(double x, double y, double z) : x{x}, y{y}, z{z} {}

  void print() const {
    std::cout << "Point(" << x << ", " << y << ", " << z << ")\n";
  }

  void moveByVector(const Vector3d& v);
};

class Vector3d {
  double x{};
  double y{};
  double z{};

public:
  Vector3d(double x, double y, double z) : x{x}, y{y}, z{z} {}

  void print() const {
    std::cout << "Vector(" << x << ", " << y << ", " << z << ")\n";
  }

  friend void Point3d::moveByVector(const Vector3d& v);
};

void Point3d::moveByVector(const Vector3d& v) {
  x += v.x;
  y += v.y;
  z += v.z;
}

int main() {
  Point3d p { 1.0, 2.0, 3.0 };
  Vector3d v { 2.0, 2.0, -3.0 };

  p.print();
  p.moveByVector(v);
  p.print();

  return 0;
}
