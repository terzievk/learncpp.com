#ifndef _POINT_3D_
#define _POINT_3D_

class Vector3d;

class Point3d {
  double x{};
  double y{};
  double z{};

public:
  Point3d(double x, double y, double z) : x{x}, y{y}, z{z} {}

  void print() const;

  void moveByVector(const Vector3d& v);
};

#endif  // _POINT_3D_
