#ifndef _VECTOR_3D_
#define _VECTOR_3D_

#include "./Point3d.h"

class Vector3d {
  double x{};
  double y{};
  double z{};

public:
  Vector3d(double x, double y, double z) : x{x}, y{y}, z{z} {}

  void print() const;

  friend void Point3d::moveByVector(const Vector3d& v);
};


#endif  // _VECTOR_3D_
