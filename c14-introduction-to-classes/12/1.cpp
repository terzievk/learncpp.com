#include <iostream>

class Ball {
  std::string color {"black"};
  double radius {10.0};

public:
  Ball() = default;
  Ball(std::string_view s): color{s} {}
  Ball(const std::string& col, double r): color{col}, radius{r} {}
  Ball(double r): radius{r} {}

};

int main() {
  Ball def{};
  Ball blue{ "blue" };
  Ball twenty{ 20.0 };
  Ball blueTwenty{ "blue", 20.0 };

  return 0;
}
