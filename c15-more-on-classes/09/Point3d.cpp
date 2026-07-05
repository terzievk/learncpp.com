#include "./Point3d.h"
#include "./Vector3d.h"

#include <iostream>

void Point3d::print() const {
  std::cout << "Point(" << x << ", " << y << ", " << z << ")\n";
}


void Point3d::moveByVector(const Vector3d& v) {
  x += v.x;
  y += v.y;
  z += v.z;
}
