#include "./Vector3d.h"

#include <iostream>

void Vector3d::print() const {
  std::cout << "Vector(" << x << ", " << y << ", " << z << ")\n";
}
